#include <stdio.h>

int main(int argc, char *argv[]) 
{
    char str[5];
    int array[100];
    int index  = 0;
    
    while(fgets(str, sizeof(str), stdin)){
        printf("%s", str);
    }

    return 0;
}
