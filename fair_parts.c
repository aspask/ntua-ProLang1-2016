#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int N,M;

int valid(long *weight,int max)
{
    long sum = 0;
    int counter = 0,i ;
    for(i=0;i<M && counter<N;i++)
    {
        //printf("%ld %d \n",sum ,counter);    
        if((sum+=weight[i])>max)
        {
            sum =weight[i];
            counter++;

        }   
    }
    //printf(" i:%d counter: %d\n",i,counter);
    if(counter != N)
    {
        return 1;
    }
    else 
    {
        return 0;
    }
}

void print(long *weight,int max)
{
    long sum = 0;
    int counter = 0,i,j,sep[N-1];
    //printf("%ld", weight[0] );
    //sum=weight[M-1];
    for(i=M-1;i>=0 && counter<N;i--)
    {   
        if((sum+=weight[i])>max)
        {
            sum =weight[i];
            sep[counter]=i;
            counter++;
            //printf(" |");
        }
        if (i==N-1-counter)
        {
            //printf("finish\n");
            break;
        }
        //printf(" %ld",weight[i]);    
    }

    //printf("%d <= %d\nlast separator %d\n", counter, N-1, sep[counter-1]);

    for (;i>0;i--,counter++)
    {
        //printf("sep[%d]=%d\n",counter,i-1);
        sep[counter]=i-1;
    }
    // for (nsep=counter-1,j=0;counter<N-1;)
    // {
    //     //printf("j: %d counter: %d\n last separator %d\n",j, counter, sep[counter-1]);

    //     if (j<sep[nsep])
    //     {
    //         //printf("j<sep[nsep] where j= %d,nsep=%d and sep[nsep]=%d\n", j,nsep,sep[nsep]);
    //         sep[counter]=j;
    //         counter++;
    //         j++
    //         //printf("counter is now %d out of %d\n", counter,N-1);
    //     }
    //     else if (j==sep[nsep])
    //     {
    //         //printf("j==sep[nsep] where j= %d,nsep=%d and sep[nsep]=%d\n", j,nsep,sep[nsep]);
    //         nsep--;
    //     }
    //     else
    //     {
    //         //printf("errrrrror\n");
    //     }
    // }

    // for (int i = 6470; i < N-1; ++i)
    // {
    //     printf("%d :%d   ",i,sep[i] );
    // }

    //printf("%d <= %d\n", counter, N-1);

    for(i=counter-1,j=0;i>=0;i--)
    {
        //printf("%d\n", i);
        for(;j<sep[i]+1;j++)
        {
            printf("%ld ", weight[j]);
        }
        printf("| ");        
        //printf("| (j:%d sep[%d]:%d)",j,i,sep[i]);        
    }

    for (; j < M-1; j++)
    {
        printf("%ld ", weight[j]);
    }
    printf("%ld\n", weight[j]);

}
int main(int argc, char **argv)
{
    // printf("%d\n", INT_MAX);
    // printf("%lld\n", LLONG_MAX);
    // printf("%ld\n", LONG_MAX);
    int a,b,i;
    long *weight,r,l,middle;
    long long max=0,max1=0,max2=0,max3;
    FILE* file = fopen (argv[1] ,"r");
    fscanf(file,"%d %d",&M,&N);
    weight = (long *) malloc(M * sizeof(long));
    for(i=0;i<M;i++)
    {   

        fscanf(file,"%ld",&weight[i]);
        // if(i>21738)
        // printf("%ld\n", weight[i]);
        max1+=weight[i];
        // if(i>21738)
        // printf("%lld %lld\n", max1,max2);

        if(i<M-N+1)
            max2+=weight[i];
        if(weight[i]>max)
            max=weight[i];
    }
    fclose(file);
    
    if(max2<max)
        max3=max;
    else
        max3=max2;

    if(max3>max1)
        r=max1;
    else
        r=max3;

    if (max2/N>max)
        l=max2/N;
    else
        l=max;

    //printf("!!! %ld %ld\n",l,r);

    //printf("%d\n",valid(weight,170));
   middle = (l+r)/2;
 
   while (l <= r) {
    //printf("!!! %ld %ld\n",l,r);
    if(l==r)
    {
        //printf("\nfound %ld\n", l);
        print(weight,l);
         break;
    }
    a=valid(weight,middle-1);
    b=valid(weight,middle);
    //printf("%ld %d %d\n",middle,a,b );
      if (!a && !b)
      {
        if(l==middle)
        {
            l=middle+1;
        }
        else
        {
            l = middle;    
        }
      }
      else if (!a && b)
      {
         //printf("\nfound %ld\n", middle);
         print(weight,middle);
         break;
      }
      else
      {
         r = middle;
      }
 
      middle = (l + r)/2;
   }
   if (l > r)
   {
      printf("Not found! %ld\n",middle);
   }

    // printf("%d %d\n ",M,N);
    // for(i=0;i<M;i++)
    // {   
    //     printf("%d\n",weight[i]);
    // }

    return 0;
}