#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void swap(int *p1, int *p2)
{
	int tmp;
	tmp = *p1;
	*p1 = *p2;
	*p2 = tmp;
}

/*
	start_num	: starts from ZERO;
	rev_num		: how many numbers will be reverted. starts from 1.
*/
void inv(int x[], int start_num, int rev_num)
{
	int temp;
	int i, j;
	int middle;
	
	middle = (rev_num - 1) / 2 + 1;	//get the arry number of middle. we need plus 1 since rev_num starts from 1.
	printf("middle = %d\n", middle);
	
	for(i = 0; i <= middle; i++)
	{
		j = rev_num + 1 -i;
		swap(&x[i + start_num], &x[j + start_num]);
	}
}

void showme(int *arr, int num)
{
	int i;

	for(i = 0; i < num; i++)
	{
		printf("%5d", *(arr + i));
	}	
	printf("\n");
}

int main()
{
	time_t t;
	int i, n = 16;
	int arr[n];
	
	srand((unsigned) time(&t));
	for(i = 0; i < n; i++)
	{
		arr[i] = rand() % 100;
	}
	
	int num = n;//sizeof(arr) / sizeof(arr[0]);
	
	showme(arr, num);
	
	inv(arr, 1, 6);
	showme(arr, num);
	
	return 0;
}