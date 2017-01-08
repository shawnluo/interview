#include <stdio.h>
#include <stdlib.h> 
#include <string.h>

#if 0
int main(void)
{
	struct Student
	{
		long num;
		char name[20];
		char sex;
		float score;
	};
	
	struct Student stu_1;
	struct Student *p;
	p = &stu_1;
	stu_1.num = 10101;
	strcpy(stu_1.name, "Li Lin");
//	stu_1.name = "Xi Lin";
	stu_1.sex = 'M';
	stu_1.score = 89.5;
	p->score = 100;
	
	printf("No.:%ld\nname:%s\nsex:%c\nscore:%5.1f\n", \
	stu_1.num, stu_1.name, stu_1.sex, stu_1.score);
	printf("\nNo.:%ld\nname:%s\nsex:%c\nscore:%5.1f\n", \
	p->num, (*p).name, (*p).sex, (*p).score);
	
	return 0;
}
#endif

#if 0

typedef struct Student
{
	int num;
	char name[20];
	char sex;
	int age;
} STU;

typedef struct
{
	char x;
	char z;
	double y;
	//char z;
}KK;

STU stu[3] = {{10101, "Li Lin", 'M', 18}, {10102, "Zhang Fang", 'M', 19}, \
				{10104, "Wang Min", 'F', 20}};

int main(void)
{
	STU *p;
	//printf(" No.    Name     sex  age\n");
	for(p = stu; p < stu + 3; p++)
	{
		//printf("%5d %-20s %2c %4d\n", p->num, p->name, p->sex, p->age);
	}
	
	printf("%d\n", sizeof(KK));
		
	return 0;
}
#endif

typedef struct
{
	char x;
	//char z;
	double y;
	char z;
}KK;

int main(void)
{
	printf("%d\n", sizeof(KK));
	return 0;
}