#!/bin/bash
gcc rev_sums.c -o revs -Wall
for i in $(seq 25)
	do
	echo "Press enter to proceed with test number " $i
	read ANS
	./revs inputs/input$i.txt
done
