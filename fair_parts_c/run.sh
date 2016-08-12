#!/bin/bash
gcc fair_parts.c -o fair -Wall
for i in $(seq 32)
do
	echo "Press enter to proceed with test number " $i
	read ANS
	./fair inputs/input$i.txt
done
