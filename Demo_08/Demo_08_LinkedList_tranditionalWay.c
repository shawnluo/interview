#include <stdlib.h>
#include <stdio.h>

typedef struct node
{
	int value;
	struct node *next;
} NODE;

#define LEN sizeof(NODE)
int NUM = 0;

NODE *creat()
{
	NODE *head;
	NODE *p1, *p2;
	
	p2 = p1 = (NODE *)malloc(sizeof(LEN));
	if(p1 == NULL)
	{
		fprintf(stderr, "failed to alloc memory!\n");
		return (NODE *)-1;
	}
	p1->value = 100;
	p1->next = NULL;
	head = p1;
	
	while(NUM++ <= 5)
	{
		p1 = (NODE *)malloc(sizeof(LEN));
		p1->value = NUM;
		p2->next = p1;
		p2 = p1;
	}
	p1->next = NULL;
		
	return head;
}

void destory(NODE *head)
{
	
}

void showme(NODE *head)
{
	NODE *p = head;
	while(p->next != NULL)
	{
		printf("%d -> ", p->value);
		p = p->next;
	}
	printf("NULL\n");
}	


/*
	traditional way to delete node by using 2 pointer: previous and current pointer
*/

void DeleteNode(int num, NODE **head_f)
{
	if(num == (*head_f)->value)
	{
		NODE *p;
		p = *head_f;
	
		*head_f = (*head_f)->next;
		free(p);
		return;
	}
	
	NODE *current;
	NODE *previous;
	NODE *temp;
	
	current = (*head_f)->next;
	previous = *head_f;
	
	while(1)//(num != current->value)
	{
		if(num == current->value)
		{
			temp = current;
			previous->next = current->next;
			free(temp);
			return;
		}
		previous = current;
		current = current->next;
	}
}

int main(void)
{
	NODE *head;
	NODE *p;
	
	head = creat();
	p = head;
	
	showme(head);
//	p = head;
//	printf("head = %p   in main()\n", &head);
	
	DeleteNode(100, &head);
	showme(head);
	
	DeleteNode(3, &head);
	showme(head);
	
	destory(head);
	
	return 0;
}