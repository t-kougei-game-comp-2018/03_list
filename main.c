#include <stdio.h>

int main(int argc, char *argv[])

{

	char str[5];
	int array[100];
	int index = 0;
	int i, j;

	while (fgets(str, sizeof(str), stdin)) {

	int n = atoi(str);
	if (n > 0 && i == 0) 
	{
		array[0] = n;
		i++;
	}
	else if(n > 0 && i > 0)
        {
        	for(j = i; j > 0; j--)
            	{
               		array[j] = array[j - 1];
            	}
            	array[0] = n;
            	i++;
        }
	else if(n == 0)
        {
           	for(j = 0; j < i; j++)
            	{
                	printf("%d",array[j]);
                	if(j < i - 1)
                	{
                   		printf(",");
                	}
            	}
            	printf("\n");
        }
	else if(n == -1)
        {
            	printf("%d",array[0]);
            	for(j = 0; j < i - 1; j++)
            	{
                	array[j] = array[j + 1];
            	}
            	i--;
            	printf("\n");
        }
	return 0;
}
