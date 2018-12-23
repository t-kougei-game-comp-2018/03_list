#include <stdio.h>
#include <stdlib.h>

typedef struct t {
	struct node *prev;
	struct node *next;

	int value;
}node;


//改行コードの削除
void trim(char* str)
{
	char *p;
	p = strchr(str, '\n');
	if (p != NULL) {
		*p = '\0';
	}
}


//新しいノードを作る
node *createNode(int val)
{
	node *newNode;
	newNode = (node *)malloc(sizeof(node));
	newNode->next = NULL;
	newNode->prev = NULL;
	newNode->value = val;


	return newNode;
}


//targetの上にnewを追加する
void addTop(node *target, node *new)
{
	target->prev = new;
	new->next = target;
}


//ノードを削除する
void delNode(node *delNode)
{

	node *prev = delNode->prev;	//自分の前
	node *next = delNode->next;	//自分の次


	if (prev != NULL) prev->next = delNode->next; //前の次を 自分の次にする
	if (next != NULL) next->prev = delNode->prev; //次の前を 自分の前にする


	printf("%d\n", delNode->value);	//削除するものを呟く

	free(delNode);	//解放
}


//一番最初を消す
node *delTop(node *top)
{
	node *rp = top->next;
	delNode(top);

	return rp;
}


//末端まで表示する
void showNode(node *top)
{
	node *np = top;
	int i = 0;
	while (1)
	{
		if (np == NULL) break;

		if (i == 0)
		{
			printf("%d", np->value);
			i++;
		}
		else
		{
			printf(",%d", np->value);
		}

		if (np->next == NULL) break;
		np = np->next;
	}
	printf("\n");
}




int main(int argc, char *argv[])
{
	node *top = NULL; //先頭把握用

	char str[7];

	while (fgets(str, sizeof(str), stdin))
	{
		trim(str);
		int number = atoi(str);


		//先頭削除
		if (number == -1)
		{
			top = delTop(top);
		}

		//現リストを表示
		else if (number == 0)
		{
			showNode(top);
		}

		//追加
		else
		{

			if (top == NULL)
			{
				top = createNode(number);
			}
			else
			{
				node *new = createNode(number);
				addTop(top, new);
				top = new;
			}
		}
	}


	return 0;
}
