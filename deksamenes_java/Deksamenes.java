import java.io.File;
import java.io.FileNotFoundException;
import java.util.Scanner;


public class Deksamenes {
    public static void main(String[] args) {
        
        
         
         File file = new File(args[0]);
        //File file = new File("/home/nikos/Desktop/input/input20.txt");
         
        int N,height=0;
        int[][] Coordinates;
        int Max_vol=0,volume;
        Scanner scan;
        try {
        scan = new Scanner(file);
            
                
            
        
        
        N = scan.nextInt();
        Coordinates = new int[2*N][2];
            

        
         
        for (int i = 0; i < 2*N; i+=2) {
            //System.out.println(i);
            Coordinates[i][0]=scan.nextInt();
            Coordinates[i+1][0]=scan.nextInt();
            Coordinates[i][1]= scan.nextInt();
            Coordinates[i][1]*= scan.nextInt();
            Max_vol+=(Coordinates[i+1][0])*Coordinates[i][1];
                
            Coordinates[i+1][0]	+=Coordinates[i][0];
            Coordinates[i+1][1]= -Coordinates[i][1];
            
        }
            
        volume =scan.nextInt();
        scan.close();
        if(volume>Max_vol) System.out.println("Overflow");
        else if(volume==Max_vol) System.out.println(Coordinates[N-1][0]);
        else{
            //Sort(Coordinates,2*N,1);
            //java.util.Arrays.sort(Coordinates, java.util.Comparator.<Int[]>comparingInt(a -> a[0]).thenComparingDouble(a -> a[1]));
            //java.util.Arrays.sort(Coordinates, java.util.Comparator.comparingInt(a -> a[0]));
            java.util.Arrays.sort(Coordinates, new java.util.Comparator<int[]>() {
                  public int compare(int[] a, int[] b) {
                    return (a[0] < b[0] ? -1 : (a[0] == b[0] ? 0 : 1));
                  }
                });
            int current_vol=0,i=1,ratio=Coordinates[0][1],temp2=0;
            height=Coordinates[0][0];
            
            
            while(current_vol<volume)
            {	
                temp2=	(Coordinates[i][0]-height)*ratio;
                current_vol+=temp2;
                    
                height=Coordinates[i][0];
                ratio+=Coordinates[i][1];
                                
                i++;	
            }
            height=Coordinates[i-2][0];
            ratio-=Coordinates[i-1][1];
        
        
            current_vol-=temp2;
            double fina =(double)(volume-current_vol);
            
                fina/=(double)ratio;
                fina+=height;
                //fina=round(fina, 2);
                System.out.printf("%.2f", fina);
                //String s = String.format("%.5f", fina);
                System.out.println();
            
        }

        } catch (FileNotFoundException e1) {
            e1.printStackTrace();
        }
        }
    
    
     
    

}
        

      
