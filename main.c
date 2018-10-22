#include<stdio.h>
int main(int argc,char *argv[])
{
    char str[100];
    int i=0,j,a[100],x;
    while(fgets(str,sizeof(str),stdin)){
        x=atoi(str);
        if(1<=x){
            a[i]=x;
            i++;
        }
        else if(x==0){
            for(j=i-1;j>=0;j--){
                printf("%d",a[j]);
                if(j>0)
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
