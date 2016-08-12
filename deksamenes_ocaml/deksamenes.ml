let input file =
	let ic = open_in file in
		let line1 = input_line ic in 
    		let n = int_of_string line1 in
    let deks_list = ref [] in
		for i = 1 to n do
			let deks = (List.map (int_of_string) (Str.split (Str.regexp " ") (input_line ic))) in
				let area = (List.nth deks 2) * (List.nth deks 3) in
				let start_h = (List.nth deks 0) in
    				deks_list := (start_h, area) :: (start_h+(List.nth deks 1), -area) :: !deks_list
		done;
		let line2 = input_line ic in
			let v = int_of_string line2 in
			close_in ic;
			(!deks_list,v)
;;

let compare a b =
	fst(a)-fst(b)
;;

let my_sort lista =
	List.fast_sort compare lista
;;

let rec solve deks_list water height capac =
	match deks_list with
		| [] -> (* Overflow *)( print_string "Overflow"; print_newline (); ())
		| h::t ->
		let new_h = fst(h) in
		let rise = ((new_h-height) * capac) in
			if (rise >= water)
			then (* (print_int height ; print_string " height " ; print_int water ; print_string " water " ; print_int (capac) ; print_string "  capac " ; print_int new_h ; print_string " " ;*)
				(*(print_int height ; print_string " height " ; print_int water ; print_string " water " ; print_int (capac) ; print_string "  capac " ; print_int new_h ; print_string " " ;*)
				let res = (( water*1000 / capac) + 5) / 10 in
				let dekad = (res mod 100) in
				let mystr = (if (dekad<10) then "0" else "" ) in
					(print_int (height + res/100) ; print_string "." ; print_string mystr; print_int dekad; print_newline (); ())
				
			else
				solve t (water-rise) new_h (capac+(snd(h)))
;;

let deksamenes file =
	let (lista , nero) = input file in
		solve (my_sort lista) nero 0 0
;;

deksamenes Sys.argv.(1)
;;