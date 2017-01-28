#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

typedef enum { false, true } bool;

// struct sq
// {
// 	int n;
// 	bool pa;
// 	bool ka;
// 	bool de;
// 	bool ar;
// };

struct pos
{
	int x;
	int y;
	bool r;
	struct pos * next;
};

int board_nums[7][8],sum=0;
struct pos * part[7][7];

////////////////////////arx
// struct sq board[7][8];
// int solutions=0;

int mark(int count[7][7], int x, int y, bool board_av[7][8], int a,int b)
{
	// printf("mark\n");
	// printf("x is %d y is %d\n",x,y);

	// for (int i = 0; i < 7; ++i)
	// {
	//     for (int j = i; j < 7; ++j)
	//     {
	//         printf("%d  ",count[i][j]);
	//     }
	// }
	// printf("\n");

	if (x>0)
	{
		if (board_av[x-1][y]==0)
		{
			int min, max;
			if (board_nums[x-1][y]<board_nums[x][y])
			{
				min=board_nums[x-1][y];
				max=board_nums[x][y];
			}
			else
			{
				max=board_nums[x-1][y];
				min=board_nums[x][y];
			}
			count[min][max]=count[min][max]-1;
			// printf(" meiwnw %d %d\n", min, max);
			if((count[min][max])==0 && ((min>a)||((min==a)&&(max>b))))
			{
				// printf("apositions of %d %d are zero\n",min,max);
				return 1;
			}
			// part[min][max]=part[min][max]->next;
		}

	}
	// printf("mark ends1\n");

	// printf("\n");
	// for (int i = 0; i < 7; ++i)
	// {
	//     for (int j = i; j < 7; ++j)
	//     {
	//         printf("%d  ",count[i][j]);
	//     }
	// }
	// printf("\n");

	if(x<6)
	{
		// printf("eeeee\n");
		if (board_av[x+1][y]==0)
		{
			// printf("eeeee\n");

			int min, max;
			// printf("x is %d y is %d\n",x,y);

			if (board_nums[x+1][y]<board_nums[x][y])
			{
				min=board_nums[x+1][y];
				max=board_nums[x][y];
			}
			else
			{
				max=board_nums[x+1][y];
				min=board_nums[x][y];
			}
			// printf(" !!!meiwnw %d %d\n", min, max);
			count[min][max]=count[min][max]-1;
			if((count[min][max])==0 && ((min>a)||((min==a)&&(max>b))))
			{
				// printf("bpositions of %d %d are zero\n",min,max);
				return 1;
			}
			// part[min][max]=part[min][max]->next;
		}
	}
	// printf("\n");
	// for (int i = 0; i < 7; ++i)
	// {
	//     for (int j = i; j < 7; ++j)
	//     {
	//         printf("%d  ",count[i][j]);
	//     }
	// }
	// printf("\n");
	// printf("mark ends2\n");

	if(y>0)
	{
		if (board_av[x][y-1]==0)
		{
			int min, max;
			if (board_nums[x][y-1]<board_nums[x][y])
			{
				min=board_nums[x][y-1];
				max=board_nums[x][y];
			}
			else
			{
				max=board_nums[x][y-1];
				min=board_nums[x][y];
			}
			count[min][max]=count[min][max]-1;
			// printf(" meiwnw %d %d\n", min, max);
			if((count[min][max])==0 && ((min>a)||((min==a)&&(max>b))))
			{
				// printf("cpositions of %d %d are zero\n",min,max);
				return 1;
			}
			// part[min][max]=part[min][max]->next;
		}
	}
	//     printf("\n");
	// for (int i = 0; i < 7; ++i)
	// {
	//     for (int j = i; j < 7; ++j)
	//     {
	//         printf("%d  ",count[i][j]);
	//     }
	// }
	// printf("\n");
	// printf("mark ends\n");

	if(y<7)
	{
		if (board_av[x][y+1]==0)
		{
			int min, max;
			if (board_nums[x][y+1]<board_nums[x][y])
			{
				min=board_nums[x][y+1];
				max=board_nums[x][y];
			}
			else
			{
				max=board_nums[x][y+1];
				min=board_nums[x][y];
			}
			// printf(" meiwnw %d %d\n", min, max);
			count[min][max]=count[min][max]-1;
			if((count[min][max])==0 && ((min>a)||((min==a)&&(max>b))))
			{
				// printf("dpositions of %d %d are zero\n",min,max);
				return 1;
			}
			// part[min][max]=part[min][max]->next;
		}
	}
	//     printf("\n");
	// for (int i = 0; i < 7; ++i)
	// {
	//     for (int j = i; j < 7; ++j)
	//     {
	//         printf("%d  ",count[i][j]);
	//     }
	// }
	// printf("\n");
	// printf("mark ends\n");


	return 0; 
}

int solve(bool board_av[7][8],int count[7][7], int a, int b)
{

	bool f1,f2;
	// printf("\n");
	// for (int i = 0; i < 7; ++i)
	// {
	// 	for (int j = i; j < 7; ++j)
	// 	{
	// 		printf("%d  ",count[i][j]);
	// 	}
	// }
	// printf("\n");

	// // print board availability
	// for(int i=0;i<7;i++)
	// {
	//     for (int j = 0; j < 8; j++)
	//     {
	//         printf("%d ",( board_av[i][j]));
	//     }
	//     printf("\n");
	// }


	int a1,b1;
	if(a==7)
	{
		// printf("EEEEEEEEEEEEE!!!!!\n");
		sum++;
		return 100;
	}
	else
	{

		if (b==6)
		{
			// printf("EEEEEEEEEEEEE1!!!!!\n");
			a1=a+1;
			b1=a1;
		}
		else
		{
			a1=a;
			b1=b+1;
		}

		struct pos * p=part[a][b];

		while(count[a][b]>0)
			// while(true)
		{
			// printf("count is %d\n",count[a][b]);
			// printf("plakidio %d %d\n",a,b );
			// printf("position is %d %d %d\n",p->x,p->y,p->r);
			bool board_av1[7][8];
			int count1[7][7];

			for (int i = 0; i < 7; ++i)
			{
				for (int j = 0; j < 7; ++j)
				{
					count1[i][j]=count[i][j];
				}
			}

			for (int i = 0; i < 7; ++i)
			{
				for (int j = 0; j < 8; ++j)
				{
					board_av1[i][j]=board_av[i][j];
				}
			}

			bool na;
			// int my_x=part[a][b]->x,my_y=part[a][b]->y,my_r=part[a][b]->r;
			if(p->r==0)
				na=board_av[(p->x)+1][p->y];
			else
				na=board_av[p->x][(p->y)+1];

			//if available
			if(na==0 && board_av[p->x][p->y]==0)
			{
				count1[a][b]=count1[a][b]+13;
				// printf("!!! %d %d %d\n", my_x, my_y, my_r);
				//printf("%d %d %d %d\n",board[my_x][my_y].pa,board[my_x][my_y].ka,board[my_x][my_y].de,board[my_x][my_y].ar );
				// printf("plakidio %d %d\n",a,b );
				// if (board[my_x][my_y].pa==0)
				f1=mark(count1,p->x,p->y,board_av,a,b);
				if(p->r==0)
				{
					// printf("aou ka8eta\n");
					f2=mark(count1,(p->x)+1,p->y,board_av,a,b);
				}
				else
				{
					// printf("aou orizontia\n");
					f2=mark(count1,p->x,(p->y)+1,board_av,a,b);
				}
				// printf("nikaki\n");
				count[a][b]--;
				count1[a][b]-=11;
				//not available any more
				if (f1 || f2)
				{
					p=p->next;
					continue;
				}
				board_av1[p->x][p->y]=1;
				if(p->r==0)
					board_av1[(p->x)+1][p->y]=1;
				else
					board_av1[p->x][(p->y)+1]=1;

				solve(board_av1,count1,a1,b1);

			}
			p=p->next;
		}
	}
	return 10;
}

int main(int argc, char **argv)
{
	int count[7][7];
	bool board_av[7][8];

	// init counters
	for (int i = 0; i < 7; ++i)
	{
		for (int j = 0; j < 7; ++j)
		{
			count[i][j]=0;
		}
	}

	FILE* file = fopen (argv[1] ,"r");
	//int sum1=0;
	for(int i=0;i<7;i++)
	{
		for (int j = 0; j < 8; j++)
		{
			// read input and find possible locations of parts
			board_av[i][j]=0;
			fscanf(file,"%d",&( board_nums[i][j] ));
			//printf("aaaaaa %d\n",( board[i][j].n ));
			if(i==0)
				;
			// board[i][j].pa=1;
			else
			{
				//printf("%d %d panw\n",i,j );
				//board[i][j].pa=0;
				int min, max;
				if (board_nums[i-1][j]<board_nums[i][j])
				{
					min=board_nums[i-1][j];
					max=board_nums[i][j];
				}
				else
				{
					max=board_nums[i-1][j];
					min=board_nums[i][j];
				}
				//printf("%d %d\n", min , max);
				count[min][max]+=1;
				//sum1++;
				struct pos * new;
				new=(struct pos *)malloc(sizeof(struct pos));
				new->x=i-1;
				new->y=j;
				new->r=0;
				new->next=part[min][max];
				part[min][max]=new;
			}
			// if(i==6)
			// 	board[i][j].ka=1;
			// else
			// 	board[i][j].ka=0;
			if(j==0)
				;
			// board[i][j].ar=1;
			else
			{
				//printf("%d %d aristera\n",i,j );
				// board[i][j].ar=0;
				int min, max;
				if (board_nums[i][j-1]<board_nums[i][j])
				{
					min=board_nums[i][j-1];
					max=board_nums[i][j];
				}
				else
				{
					max=board_nums[i][j-1];
					min=board_nums[i][j];
				}
				//printf("%d %d\n", min , max);
				count[min][max]+=1;
				//sum1++;
				struct pos * new;
				new=(struct pos *)malloc(sizeof(struct pos));
				new->x=i;
				new->y=j-1;
				new->r=1;
				new->next=part[min][max];
				part[min][max]=new;

			}
			// if(j==7)
			// 	board[i][j].de=1;
			// else
			// 	board[i][j].de=0;    		
		}
		// fscanf(file,"\n");  
	}
	fclose(file);

	// print board availability
	// for(int i=0;i<7;i++)
	// {
	//     for (int j = 0; j < 8; j++)
	//     {
	//         printf("%d ",( board_av[i][j]));
	//     }
	//     printf("\n");
	// }

	// int sum=0;

	//print number of solutions
	// find if one part has no possible position

	// for (int i = 0; i < 7; ++i)
	// {
	//     for (int j = i; j < 7; ++j)
	//     {
	//         // sum+=count[i][j];
	//         printf("\n");

	//         printf("%d  ",count[i][j]);
	//         // if (count[i]==0)
	//         // {
	//         //     printf("0\n");
	//         //     return 0;
	//         // }
	//         printf("\n");

	//     }
	// }

	solve(board_av,count,0,0);
	printf("%d\n",sum);
	// for (int i = 0; i < 7; ++i)
	// {
	//     for (int j = i; j < 7; ++j)
	//     {
	//         printf("a %d b %d\n",i,j );
	//         if (solve(count,part,i,j)==0)
	//         {
	//             printf("asdfg\n");
	//         }
	//         // printf("%d\n",solve(count,part,i,j));
	//     }
	// }

	// printf("%d\n",solve(count,part,0,0));
	return 0;
}
