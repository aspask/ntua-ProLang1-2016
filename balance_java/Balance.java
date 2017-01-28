
//new DecimalFormat("#.#", new DecimalFormatSymbols(Locale.US))
//import java.io.File;
//import java.io.FileNotFoundException;
import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;



public class Balance {
	public static void main (String args[])
    {	
int sub=0;
//System.out.println("give input");
//Scanner input = new Scanner(System.in);
//String message = input.nextLine();
int num;
long W;
Scanner in = new Scanner(System.in);
if(sub==0) num = in.nextInt();
else num = Integer.parseInt(args[0]);


if(sub==0) W=in.nextLong();
else W = Long.parseLong(args[1], 10);


//int num = in.nextInt();
//long W=in.nextLong();

List<Integer> Lst = new ArrayList<Integer>();
List<Integer> left = new ArrayList<Integer>();
List<Integer> right = new ArrayList<Integer>();
conversion(W,Lst);
//System.out.println(Lst);
/*System.out.println(Lst);
int head = (Integer)Lst.get(1);
System.out.println(head);
Lst.remove(1);*/
//System.out.println("first"+Lst);
scale(num,Lst,left,right);
//System.out.println(Lst);
System.out.print(left);
System.out.println(right);
in.close();
    
    	}
	
		public static void conversion(long W,List<Integer> Lst)
		{  long s = 0L;
		   int element =0;
			while (W>0){
				
			   
			   s = (W % 3L);
			   //int element = toIntExact(s);
			   element = (int) s;
			   Lst.add(element);
			    W = W / 3L;
			}
			
		}
	
		

public static void scale(int num,List<Integer> Lst,List<Integer> left,List<Integer> right)
{ int counter = 1,carry = 0;
  int head=0 ; 
  //List<Integer> tail = new ArrayList<Integer>();
  //tail=Lst.tail();
	while(num-counter>= 0 && Lst.size() > 0)
	{
		
		head = (Integer)Lst.get(0);
		//System.out.println("the head:"+head);
		Lst.remove(0);
		//System.out.println("the list:"+Lst);
		head = head + carry;
		if(head == 0) { carry =0;  }
		else if (head ==1 ) { carry =0; right.add(counter); }
		else if (head ==2 ){ carry =1; left.add(counter); }
		else if (head ==3) {carry =1;}
		/*
		 * System.out.print("counter: "+counter+"");
		System.out.print(Lst);
		System.out.print(carry);
		System.out.print(left);
		System.out.println(right);
		*/
		counter = counter +1;
		

     }//System.out.print("yes ");
	if (carry == 1 && num-counter>= 0  ) right.add(counter);
	else if ( carry == 1 ) {right.clear() ; left.clear(); } ;
}


}