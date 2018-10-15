#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct cell
{
    struct cell *prev;
    struct cell *next;
    int data;
};

struct cell *NewList(int data, struct cell *next)
{
    struct cell *new = NULL;
    
    new = malloc(sizeof(struct cell));
    if(new == NULL)
    {
        return(NULL);
    }
    else
    {
        new -> next = next;
        new -> data = data;
    }
}

int AddList(struct cell **foot, int data)
{
    struct cell *prev = NULL;
    
    prev = NewList(data, *foot);
    if(prev == NULL)
        return (-1);
    else
    {      
        *foot = prev;
        return 0;
    }    
}

int DelList(struct cell **foot)
{
    struct cell *prev = NULL;
    
    printf("%d", foot -> data);
    prev = (*foot) -> next;
    free(*foot);
    *foot = prev;   
}

void ShowList(struct cell *foot)
{
    while(foot != NULL)
    {
        printf("%d", foot -> data);
        foot = foot -> next;
        if(foot != NULL)
        {
            printf(",");
        }
    }
}


int main(int argc, char *argv[]) 
{
    int data;
    char str[5];
    FILE *stdin;
    struct cell *list = NULL;
   
    stdin = fopen("input1.txt","r"); 
    if(stdin == NULL)
    {
        printf("ファイル読み込みに失敗しました。\n");        
        return -1;
    }
    
    while(fgets(str, sizeof(str), stdin))
    {
        data = atoi(str);
        switch (data)
        {
            case 0:
                showlist(list);
                break;
            case -1:
                DelList(list);
                break;
            default:
                AddList(list);
                break;
        }              
    }

    fclose(stdin);
    return 0;
}

