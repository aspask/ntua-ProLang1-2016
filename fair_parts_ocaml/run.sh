#!/bin/bash
ocamlc str.cma fair_parts.ml -o fair
for i in $(seq 32)
do
	echo "Press enter to proceed with test number " $i
	read ANS
	./fair inputs/input$i.txt
done
