#!/bin/bash
for i in $(seq 16)
do
	echo "Press enter to proceed with test number " $i
	read ANS
	./dom input/test$i.txt
	cat input/output$i.txt
done
