javac Deksamenes.java 
for i in $(seq 20)
do
	echo "Press enter to proceed with test number " $i
	read ANS
	java Deksamenes inputs/input$i.txt
	echo "The right answer is:"
	cat outputs/output$i.txt
	echo ""
done
