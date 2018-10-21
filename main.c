#include <stdio.h>

int main(int argc, char *argv[]) 
{
    char str[100];
    int array[100],i = 0,j;
    
    while(fgets(str, sizeof(str), stdin)){
        int input = atoi(str);
        
        if(input > 0 && i = 0)
        {
            array[i] = input;
            i++;
        }
        else if(input > 0 && i > 0)
        {
            for(j = 0; j < i; j++)
            {
                array[j + 1] = array[j];
            }
            
            array[0] = input;
            i++;
        }
        else if(input == 0)
        {
            for(j = 0; j < i; j++)
            {
                printf("%d",array[j]);
                
                if(j < i - 1)
                {
                    printf(",");
                }
            }
        }
        else if(input == -1)
        {
            printf("%d",array[0]);
            
            for(j = 0; j < i - 1; j++)
            {
                array[j] = array[j + 1];
            }
            
            i--;
        }
    }

    return 0;
}
