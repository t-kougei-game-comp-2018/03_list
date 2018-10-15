#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct cell
{
    struct cell *prev;
    struct cell *next;
    int data;
}

cell *NewList(int data);
int AddList(cell *head, int data);
int DelList(cell **foot);
void ShowList(cell *foot):

int main(int argc, char *argv[]) 
{
    int data;
    char str[5];
    FILE *stdin;
    cell *list = NULL;
   
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

cell *NewList(int data, cell *next)
{
    cell *new = NULL;
    
    new = malloc(sizeof(cell));
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

int AddList(cell **foot, int data)
{
    cell *prev = NULL;
    
    prev = NewList(data, *foot);
    if(prev == NULL)
        return (-1);
    else
    {      
        *foot = prev;
        return 0;
    }    
}

int DelList(cell **foot)
{
    cell *prev = NULL;
    
    printf("%d", foot -> data);
    prev = (*foot) -> next;
    free(*foot);
    *foot = prev;   
}

void ShowList(cell *foot)
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
