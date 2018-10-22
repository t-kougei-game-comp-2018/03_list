#include <stdio.h>

int main(int argc, char *argv[]) 
{
    char str[5]; 
    int i=0,j,x,a[100];
    while(fgets(str, sizeof(str), stdin)){
        x=atoi(str);
        if(x>0){
            a[i]=x;
            i++;
        }
        if(x==0){
            printf("%c",a[i]);
            for(j=i-1;j>0;j--)
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
