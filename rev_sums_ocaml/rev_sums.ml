let explode s =
	let rec exp i l =
		if i < 0 then l else exp (i - 1) (s.[i] :: l) in
			exp (String.length s - 1) []
;;

let split_inp inp =
	
	List.map (fun i -> (int_of_char i) -48)  (explode inp)
;;

let input file = 
	let ic = open_in file in
	    let line = input_line ic in  (* read line from in_channel and discard \n *)	              					 (* write the result to stdout *)
	    close_in ic;  				 (* close the input channel *)
	    split_inp line                		  
;;

let remove_last list = 
   match (List.rev list) with
   | h::t -> List.rev t
   | []   -> []
;;


let rec carry_sub number l =
	let d = (List.nth number (l-1)) in
		match d with
		| 0 -> (carry_sub (remove_last number) (l-1) ) @ [9]
		| _ -> (remove_last number) @ [(d-1)]
;;

(* number is an int list *)
let rec test_loop number carry left right =
	match number with
	| [] -> (* if we got to the middle there should be no carry left *)
		(match carry with
		| 0 -> left^right
		| _ -> raise Not_found)	
	| h :: [] -> (* For odd length we divide with 2 *)
		left^(string_of_int (5*carry+h/2))^right
	| h :: number_int -> (* recursion *)
	let l = (List.length number) in
		let tempr = (10 * carry + (List.nth number (l-1))) in
			if ((tempr = 19))
			then
				if (h = 0)
				(* 9, carry, kai 0 *)
				then
					test_loop (remove_last number_int) 1 ( left ^ "9" ) ( "0" ^ right )
				(* 9, carry, alla oxi 0 *)
				else
					raise Not_found
			(* genikh periptwsh *)
			else
				let next_num =
					(match carry with
					| 0 -> (remove_last number)
					| 1 -> (carry_sub (remove_last number) (l-1))
					| _ -> raise Not_found ) in
						let c = 10 * carry + (List.hd next_num) -tempr in
						match c with
						| 0 -> test_loop (List.tl next_num) 0 ( left ^ (string_of_int (tempr - 9 * carry)) ) ( (string_of_int (9 * carry)) ^ right )
						| 1 -> test_loop (List.tl next_num) 1 ( left ^ (string_of_int (tempr - 9 * carry)) ) ( (string_of_int (9 * carry)) ^ right )
						| _ -> raise Not_found
;;

let main number = 
	try
			match (List.hd number) with
				| 1 -> (match (List.nth number ((List.length number)-1)) with
						| 0 -> test_loop (List.tl number) 1 "" ""
						| _ -> 
							(try
								test_loop (number) 0 "" ""
							with
							| Not_found -> (test_loop (List.tl number) 1 "" "")
							)
						)
				| _ -> test_loop (number) 0 "" ""
	with
	| Not_found -> "0"
;;

let revsum file =
	print_endline (main (input file))
;;

revsum Sys.argv.(1)