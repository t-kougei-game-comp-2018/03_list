#include <stdio.h>
#include <stdlib.h>

typedef struct t {
	struct node *prev;
	struct node *next;

	int value;
}node;


//���s�R�[�h�̍폜
void trim(char* str)
{
	char *p;
	p = strchr(str, '\n');
	if (p != NULL) {
		*p = '\0';
	}
}


//�V�����m�[�h�����
node *createNode(int val)
{
	node *newNode;
	newNode = (node *)malloc(sizeof(node));
	newNode->next = NULL;
	newNode->prev = NULL;
	newNode->value = val;


	return newNode;
}


//target�̏��new��ǉ�����
void addTop(node *target, node *new)
{
	target->prev = new;
	new->next = target;
}


//�m�[�h���폜����
void delNode(node *delNode)
{

	node *prev = delNode->prev;	//�����̑O
	node *next = delNode->next;	//�����̎�


	if (prev != NULL) prev->next = delNode->next; //�O�̎��� �����̎��ɂ���
	if (next != NULL) next->prev = delNode->prev; //���̑O�� �����̑O�ɂ���


	printf("%d\n", delNode->value);	//�폜������̂�ꂭ

	free(delNode);	//���
}


//��ԍŏ�������
node *delTop(node *top)
{
	node *rp = top->next;
	delNode(top);

	return rp;
}


//���[�܂ŕ\������
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
	node *top = NULL; //�擪�c���p

	char str[7];

	while (fgets(str, sizeof(str), stdin))
	{
		trim(str);
		int number = atoi(str);


		//�擪�폜
		if (number == -1)
		{
			top = delTop(top);
		}

		//�����X�g��\��
		else if (number == 0)
		{
			showNode(top);
		}

		//�ǉ�
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
