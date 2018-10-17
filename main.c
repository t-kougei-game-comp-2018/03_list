#include <stdio.h>

int main(int argc, char *argv[]) 
{
    int str[100],i=0,count=0;
    
    while(1){
        scanf("%d",&str[i]);
        i++;
        count++;
        if(str[i]==0)
            break;
        else if(str[i]==-1)
            break;
    }
    if(str[i]==-1){
        for(i=0;i<count-1;i++){
            printf("%d",str[i]);
        }
    }
    
    else{
        printf("%d",str[i]);
    }

    return 0;
}
