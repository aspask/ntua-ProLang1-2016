let rec conversion number  =
	let t = Big_int.zero_big_int in
	let tree = Big_int.big_int_of_int 3 in
	if (Big_int.eq_big_int number t) then []
	else
     (( Big_int.mod_big_int ( number) tree)) :: (conversion ( Big_int.div_big_int (number) tree))
;;

let rec print_list_h = function 
[] -> ()
| e::[] -> print_int e ;
| e::l -> print_int e ; print_string "," ; print_list_h l
;;

let print_list a =
	print_string "[";
	print_list_h a;
	print_string "]"
;;

let conv number = 
List.map (fun i -> Big_int.int_of_big_int i  ) (conversion number)
;;

let rec solve  n number = (*if carry = 1 add 1 to the next power*)
 	let rec scale counter n number carry left right =
(* 	print_int (n-counter+1); print_newline ();
*)	match (List.length number) with 
	| 0 ->  if (carry == 1)
			then 
				if (n>=counter)
				then (left,(right@[counter]))
				else ([],[])
			else (left,right) 
	| _ ->
	 	match (n-counter+1) with 
	 	| 0 -> ([],[])
	 	| _ -> 
		 	match ((List.hd number) + carry ) with 
		 	| 0 -> scale (counter+1) n (List.tl number) 0 left right
		 	| 1 -> scale (counter+1) n (List.tl number) 0 left (right@[counter])
		 	| 2 -> scale (counter+1) n (List.tl number) 1 (left@[counter]) (right)
		 	| 3 -> scale (counter+1) n (List.tl number) 1 left right
		 	| _ -> raise Not_found
    in 				
    scale 1 n number 0 [] []
;;

let balance n number =
	let (left, right) = solve n (conv(Big_int.big_int_of_int number)) in
		print_list left; print_string " "; print_list right; print_newline (); ()	
;;

balance (int_of_string Sys.argv.(1)) (int_of_string Sys.argv.(2))
;;