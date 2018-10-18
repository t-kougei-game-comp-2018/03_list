#include<stdio.h>
#include<stdlib.h>
int main(int argc,char *argv[])
{
char str[5];
int array[100];
int index=0,i;
while(fgets(str,sizeof(str),stdin)){
int n=atoi(str);
if(1<=n){
array[index]=n;
index++;
}
    
else if(n==0){
    for(i=index-1;i>=0;i--){
        printf("%d",array[i]);
        if(i>0){
            printf(",");
        }
    }
    printf("\n");
}
    else if(n==-1){
        printf("%d\n",array[index-1]);
        index--;
    }
    
 }
    return 0;
}
