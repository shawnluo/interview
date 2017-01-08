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
		p1->value = str[i];
		p1->next = NULL;
		p2->next = p1;
		p2 = p1;
	}
	
	return head;
}

void showme(Node *head)
{
//	Node *p = NULL;
//	p = head;
	
	while(head != NULL)
	{
		printf("%s->", head->value);
		head = head->next;
	}	
	printf("NULL\n");
}

int main(void)
{
//	char s[100];
//	strcpy(s, "sdde");
//	printf("%s\n", s);
	
	Node *head;
	head = creat();
//	printf("%s\n", head->value);
	showme(head);
	return 0;
}