#!/bin/bash
ocamlc str.cma deksamenes.ml -o deksa
for i in $(seq 0 20)
do
	echo "Press enter to proceed with test number " $i
	read ANS
	time ./deksa input/input$i.txt
	cat output/output$i.txt
	echo ""
done
