#include <stdio.h>

int main(int argc, char *argv[])
{
	char str[100];
	int array[100];
	int i = 0;
	int j, n;

	while (fgets(str, sizeof(str), stdin)) 
	{
		 n = atoi(str);
		
		if (1 <= n) 
		{
			array[0] = n;
			i++;
		}
		
		/*else if(n > 0 && i > 0)
        	{
        		for(j = i; j > 0; j--)
            		{
               			array[j] = array[j - 1];
            		}
            		array[0] = n;
            		i++;
        	}*/
		
		else if(n == 0)
        	{
           		for(j = i - 1; j >= 0; j--)
            		{
                		printf("%d",array[j]);
                		if(j > 0)
                		{
                   			printf(",");
                		}
            		}
			
            		printf("\n");
        	}
		
		else if(n == -1)
        	{
            		printf("%d\n",array[i-1]);
			i--;
		}
	}
	return 0;
}
