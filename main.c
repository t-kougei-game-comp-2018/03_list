#include <stdio.h>

int main(int argc, char *argv[]) 
{
    char str[5];
    char a[100];
    int i=0,j,x;
    
    while(fgets(str, sizeof(str), stdin)){
        x=atoi(str)
        if(x>0){
            a[i]=str;
            i++;
        }
        if(x==0){
            printf("%c",a[i-1]);
            for(j=i-2;j>0;j--)
                printf(",%c",a[j]);
            printf("\n");
        }
        if(x==-1){
            printf("%c\n",a[i-1]);
            i--;
        }
    }
    return 0;
}
