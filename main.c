#include <stdio.h>

int main(int argc, char *argv[]) 
{
    char str[5];
    char a[100];
    int i=0,j;
    
    while(fgets(str, sizeof(str), stdin)){
        if(str>0){
            a[i]=str;
            i++;
        }
        if(str==0){
            printf("%c",a[i-1]);
            for(j=i-2;j>0;j--)
                printf(",%c",a[j]);
            printf("\n");
        }
        if(str==-1){
            printf("%c\n",a[i-1]);
            i--;
        }
    }
    return 0;
}
