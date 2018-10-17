#include <stdio.h>
#include<stdlib.h>
int main(int argc, char *argv[]) 
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
            for(i=0;i<index;i++){
            printf("%d",array[i]);
            }
            printf("¥n");
    }
    else{
        printf("%d¥n",array[index-1]);
        index--;
    }
    
  }

    return 0;
}
