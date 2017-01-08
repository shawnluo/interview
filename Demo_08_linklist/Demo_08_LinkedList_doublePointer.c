#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node_s
{
	int num;
	char *value;
	struct node_s *next;
} Node;

#define LEN sizeof(Node)

Node *creat()
{
	Node *head;
	Node *p1, *p2;
	
	int i;
	char *str[3] = {"day", "to", "die!"}; 
	
	p2 = p1 = (Node *)malloc(sizeof(LEN));
	p1->value = "good";
	p1->num = 100;
	p1->next = NULL;
	
	head = p1;	
	
	for(i = 0; i < 3; i++)
	{
		p1 = (Node *)malloc(sizeof(LEN));
		p1->num = i;
		p1->value = str[i];
		p1->next = NULL;
		p2->next = p1;
		p2 = p1;
	}
	
	return head;
}

Node *removeNode(Node **head, int searchValue)
{
	Node **doublepointer = head;
		
	while(*doublepointer && ((*doublepointer)->num != searchValue))
	{
		doublepointer = &(*doublepointer)->next;
	}
	
	Node *deleteNode = *doublepointer;
	*doublepointer = deleteNode->next;
	deleteNode->next = NULL;
	
	return deleteNode;
}

void showme(Node *head)
{
//	Node *p = NULL;
//	p = head;
	
	while(head != NULL)
	{
		printf("%d+%s->", head->num, head->value);
		head = head->next;
	}	
	printf("NULL\n");
}

int main(void)
{
//	char s[100];
//	strcpy(s, "sdde");
//	printf("%s\n", s);
	
	Node *head, *deleteNode;

	head = creat();
	showme(head);

	deleteNode = removeNode(&head, 2);
	showme(head);

	deleteNode = removeNode(&head, 1);
	showme(head);
	
	deleteNode = removeNode(&head, 100);
	showme(head);
	
	return 0;
}