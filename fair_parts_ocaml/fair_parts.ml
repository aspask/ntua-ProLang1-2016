let input file = 
  let ic = open_in file in
      let line1 = input_line ic in 
      let line2 = input_line ic in
        let n = List.nth (List.map (int_of_string) (Str.split (Str.regexp " ") line1)) 1 in
        let m = List.nth (List.map (int_of_string) (Str.split (Str.regexp " ") line1)) 0 in
        (m,n,List.map (int_of_string) (Str.split (Str.regexp " ") (line2)))
;;

let get (m,n,lista,b,c,max) = b
;;

let valid  m  n lista  max =
  let iffun (m,n,lista,counter,sum,max) =
    if(sum+List.hd lista >max) then (m,n,List.tl lista,counter+1,List.hd lista,max)   
    else (m,n,List.tl lista,counter,(sum+List.hd lista),max)
  in 
    let rec forloop (i,(m,n,lista,counter,sum,max)) = 
      if(i>=m || counter >=n) then (m,n,lista,counter,sum,max)
      else forloop ((i+1),iffun (m,n,lista,counter,sum,max))
    in  
      if(get(forloop(0,(m,n,lista,0,0,max)))<>n) then 1
      else 0
;;

let rec binary_search m n lista low high =
  if (high = low)
  then
    (* print_int low; *) low
  else
    let middle = (low + high) / 2 in
      match ((valid  m  n lista  (middle-1)),(valid m n lista middle)) with
      | (0,0) -> 
        if (low = middle)
        then (binary_search m n lista (middle+1) high)
        else (binary_search m n lista middle high)
      | (0,1) -> (* (print_int middle); *)middle
      | (1,1) -> (binary_search m n lista low middle)
      |   _   -> raise Not_found
;;

let get1_3 (a,_,_) = a
;;
let get2_3 (_,a,_) = a
;;
let get3_3 (_,_,a) = a
;;

let rec max_list l = match l with
| [] -> 0
| h :: t -> max h (max_list t)
;;

let rec sum_list l = match l with
| [] -> 0
| h :: t -> h + sum_list t
;;


let rec print_list = function 
[] -> ()
| e::[] -> print_int e ;
| e::l -> print_int e ; print_string " " ; print_list l
;;
let ppl lista = print_list (List.rev lista)
;;


let rec print_listofl = function 
[] -> ()
| e::[] -> ppl e ; print_newline ()
| e::l -> ppl e ; print_string " | " ; print_listofl l
;;

let pp lista = print_listofl (List.rev lista)
;;

let rec sublist b e l = 
  match l with
    [] -> failwith "sublist"
  | h :: t -> 
     let tail = if e=0 then [] else sublist (b-1) (e-1) t in
     if b>0 then tail else h :: tail
;;

let rec firstp part lista max sum seps =
  if (lista=[]) then
    ((* print_endline "[]"; *) part)
  else
  if (seps+2>=List.length lista) && ((List.length part)<=2) then
    ((* (print_int (List.length part));  (print_endline "2seps>=length"); *) part@[(List.hd lista)])
  else
  if (sum+(List.hd lista) > max) then
    ((* print_endline ">"; *) part)
  else ((* print_int seps;print_newline ();print_endline "vazw"; *) firstp (part@[(List.hd lista)]) (List.tl lista) max (sum+(List.hd lista)) (seps))
;;

let rec finda a lista max seps=
if(lista=[]) then
a
else if (seps=0) then
 ((* print_endline "seps=0"; *) (a@[lista]))
else 
let aa =firstp [] lista max 0 (seps-1) in
(finda (a@[aa]) (sublist (List.length aa) ((List.length lista)-1) lista) max (seps-1))
;;

let fair_parts file =
  let (m,n,lista) = input file in
  ((* print_int n;print_endline " arxh"; *)pp (finda [] (List.rev lista) (binary_search m n lista (max_list lista) (sum_list lista)) (n-1)))
;;

fair_parts Sys.argv.(1)
