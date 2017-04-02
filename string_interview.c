#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <assert.h>

//#define my_strcpy_FUN
//#define my_strcat_FUN
//#define my_strstr_FUN
#define link_list

#if defined my_strcpy_FUN

char *my_strcpy(char *des, const char *src)
{
	assert((des != NULL) && (src != NULL));
	
	char *address = des;
	while((*des++ = *src++) != '\0')
	{
	}
	
	return address;
}


int main(void)
{
	char *src="abcde";
	char strDes[10];
	char *des = strDes;
	
	if(1 == my_strcpy(des,src))
	{
		printf("strDes=%s\n",strDes);
	}
	else
	{
		printf("Copy string returns failed!!\n");
	}
}

#elif defined my_strcat_FUN

char *my_strcat(char *pDes, const char *pSrc)
{	
	assert((pDes != NULL) && (pSrc != NULL));
	char *tmp = pDes;
	
	pDes+= strlen(pDes);
	
	while((*pDes++ = *pSrc++) != '\0')
	{
		
	}
	
	return tmp;
}
	
int main(void)
{
	char pSrc[] = {"shownum"};
	char pDes[30] = {"1234meme"};
	
	my_strcat(pDes, pSrc);
	
	printf("%s\n", pDes);

	return 0;
}

#elif defined my_strstr_FUN


int my_strstr(char *str, char *substr)
{
	assert((str != NULL) && (substr != NULL));
	
	if((strlen(str) == 0) && (strlen(substr) == 0))
	{
		return 1;
	}
	
	char *p_str = str, *p_substr = substr;
	
	while(*p_str)
	{
		p_substr = substr;
		
		while(*p_str++ == *p_substr++)
		{
			if(*p_substr == '\0')
			{
				return 1;
			}
		}
		
		p_str++;
	}
	
	return 0;
}

int main(void)
{
	char *pStr = "";
	char *pSub = "";

	printf("%d\n", my_strstr(pStr, pSub));
	return 0;
}

#elif defined link_list

typedef struct stu
{
	int num;
	struct stu *next;
} STU;

#define LEN sizeof(STU)

STU *create(void)
{
	STU *head, *p1, *p2;
	int i = 190;
	
	if((p1 = (STU *)malloc(LEN)) == NULL)
	{
		perror("malloc failed!");
		return -1;
	}
	p1->num = 100;
	p1->next = NULL;
	head = p2 = p1;
	
	while(p1->num != 200)
	{
		if((p1 = (STU *)malloc(LEN)) == NULL)
		{
			perror("malloc failed!");
			return -1;
		}
		p1->num = i++;
		p1->next = NULL;
		p2->next = p1;
		p2 = p1;
	}
	
	return head;
}

STU *Insert(STU *head)
{
	STU *p, *left, *right;
	p = head;
	
	while(p->num != 198)
	{
		if(p->next == NULL)
		{
			return -1;
		}
		
		p = p->next;
		printf("---------%d\n", p->num);
	}
	
	left = p;
	right = p->next;
	
	p = (STU *)malloc(LEN);
	p->num = 88;
	left->next = p;
	p->next = right;
	
	return head;
}

STU *DelNode(STU *head, int num)
{
	STU *previous, *current;
	current = head;
	
	while(current->next->num != num)
	{
		current = current->next;
	}
//	previous 
	
	return head;
}

void showme(STU *head)
{
	STU *p = head;
	while(p->next != NULL)
	{
		printf("%d\n", p->num);
		p = p->next;
	}
}

int main(void)
{
	STU *head = create();
	showme(head);
	head = Insert(head);
	showme(head);
	
	return 0;
}

#endif