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
        else if(x==0){
            for(j=i-1;j>=0;j--){
                printf("%d",a[j]);
                if(i>0)
                    printf(",");
            }
            printf("\n");
        }
        else if(x==-1){
            printf("%d\n",a[i-1]);
            i--;
        }
    }
    return 0;
}
