#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct cell
{
    struct cell *prev;
    struct cell *next;
    int data;
};

struct cell *newList(int data, struct cell *next);

int addList(struct cell **foot, int data);

int delList(struct cell **foot);

void showList(struct cell *foot);

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
                showList(list);
                break;
            case -1:
                delList(&list);
                break;
            default:
                addList(&list, data);
                break;
        }              
    }

    fclose(stdin);
    return 0;
}

struct cell *newList(int data, struct cell *next)
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
        return new;
    }
}

int addList(struct cell **foot, int data)
{
    struct cell *prev = NULL;
    
    prev = newList(data, *foot);
    if(prev == NULL)
        return (-1);
    else
    {      
        *foot = prev;
    }    
    return 0;
}

int delList(struct cell **foot)
{
    struct cell *prev = NULL;
    
    //printf("%d", foot -> data);
    prev = (*foot) -> next;
    free(*foot);
    *foot = prev;   
    
    return 0;
}

void showList(struct cell *foot)
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
