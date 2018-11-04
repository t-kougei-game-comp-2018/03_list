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
    struct cell *list = NULL;
    
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

    return 0;
}

struct cell *newList(int data, struct cell *next)
{
    struct cell *newcell = NULL;
    
    newcell = malloc(sizeof(struct cell));
    if(newcell == NULL)
    {
        return(NULL);
    }
    else
    {
        newcell -> next = next;
        newcell -> data = data;
        return newcell;
    }
}

int addList(struct cell **foot, int data)
{
    struct cell *prev;
    
    prev = newList(data, *foot);
    if(prev == NULL)
        return (-1);
    
    *foot = prev;
       
    return 0;
}

int delList(struct cell **foot)
{
    struct cell *prev;
    
    printf("%d\n", (*foot) -> data);
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
        else
        {
            printf("\n");
        }
    }
}
