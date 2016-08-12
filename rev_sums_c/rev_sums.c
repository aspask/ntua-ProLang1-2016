#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char * inputString(FILE* fp, size_t size){
//The size is extended by the input with the value of the provisional
    char *str;
    int ch;
    size_t len = 0;
    str = realloc(NULL, sizeof(char)*size);//size is start size
    if(!str)return str;
    while(EOF!=(ch=fgetc(fp)) && ch != '\n'){
        str[len++]=ch;
        if(len==size){
            str = realloc(str, sizeof(char)*(size+=16));
            if(!str)return str;
        }
    }
    str[len++]='\0';

    return realloc(str, sizeof(char)*len);
}

void strrev(char * str) {
   char temp;
   int i, j = 0;
 
   i = 0;
   j = strlen(str) - 1;
 
   while (i < j) {
      temp = str[i];
      str[i] = str[j];
      str[j] = temp;
      i++;
      j--;
   }
}


int test(char * number, int carry)
{
	int length,r=0,l=carry,templ,tempr,temp;
    char *left,*right,str[4],inter[4];

	length = strlen(number);
    left = (char *) malloc(length/2 + 1 * sizeof(char));
    right = (char *) malloc(length/2 + 1 * sizeof(char));
    strcpy(left,"");
	strcpy(right,"");
	strcpy(inter,"");

	//printf("The number is :%s and length %d\n",number,length);
	
    for(;l+r+1<length;l++,r++)
    {
    	//printf("left:%s right:%s l:%d r:%d c:%d\n",left,right,l,r,carry);
        //printf("index %d\n", length-1-r);
        //printf("char %c\n", number[length-1-r]+'0');
        tempr = number[length-1-r]-'0';
        //printf("tempr:%d\n",tempr);
        

        if(tempr==9 && carry==1)
  		{
	        if ((templ = number[l]-'0')!=0)
            {
            return 0;
            }

	        //printf("tempr:%d\n",tempr);
	        //printf("templ:%d\n",templ);

	        sprintf(str,"%d",tempr - 9*carry);
			strcat(right,str);
			sprintf(str,"%d",9*carry);
			strcat(left,str);
			continue;
		}

        if(carry)
        {
        	tempr+=10;
            //printf("!!!\n");
            //printf("kratoumeno %c\n",number[length-2-r] );
            for(temp=length-2-r;number[temp]=='0';temp--)
            {
                //printf("aaaa\n");
                if(temp<=l)
                {
                    return 0;
                }
                number[temp]='9';
            }
            number[temp]-=1;
        	templ=10;
        }
        else
        {
        	templ=0;
        }

        templ += number[l]-'0';
        //printf("tempr:%d\n",tempr);
        //printf("templ:%d\n",templ);

        sprintf(str,"%d",tempr - 9*carry);
		strcat(left,str);
		sprintf(str,"%d",9*carry);
		strcat(right,str);

        if( (carry=templ-tempr)!=0 && carry!=1)
        {
        	//printf("0\n");
        	//printf("carryyyyyyyy:%d\n",carry);
        	return 0;
        }
    }
        
        /*--------------------------------------------------------------------*/

    //printf("left:%s right:%s l:%d r:%d c:%d\n",left,right,l,r,carry);
    if(r+l+1==length)
    {
		sprintf(inter,"%d",(number[length/2]-'0')/2+5*carry);
    }
    else if (r+l==length)
    {
        if (carry)
        {
            return 0;
        }
    }
    //if carry =1??????
    strrev(right);
    //printf("!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!\n");
    printf("%s%s%s\n",left,inter,right);
    return 1;

}

int main(int argc, char **argv)
{
	int length;
    char *number;
    //printf("argv[%d]: %s\n", 1, argv[1]);
	FILE* file = fopen (argv[1] ,"r");
	number = inputString(file, 10);
	fclose (file);
	length = strlen(number);

    if(number[0]=='1' && number[length-1]=='0')//if first digit is 1 and last is 0, we have a carry
    {
		if(test(number,1)==0)
    	{
    		printf("0\n");
    		return 0;
    	}
		free(number);
	    return 0;

    }

    if(test(number,0)==0)
    {
        if(number[0]!='1')//if first digit is 1 try with both 0 or 1 as carry
    	{
    		printf("0\n");
    		return 0;
    	}
    	else if(test(number,1)==0)//else no carry
    	{
    		printf("0\n");
    		return 0;
    	}
    }
	free(number);
    return 0;
}