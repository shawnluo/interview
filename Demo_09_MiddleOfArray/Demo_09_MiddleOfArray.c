#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void inv(int x[], int start_num, int rev_num) //3, 5
{
	int temp;
	int i, j;
	int middle;
	
	middle = (rev_num - 1) / 2 + start_num;
	
	for(i = start_num; i <= middle; i++)
	{
		j = start_num + rev_num - 1 - (i - start_num);
		temp = x[i];
		x[i] = x[j];
		x[j] = temp;
	}
}

void showme(int *arr, int num)
{
	int i;

	for(i = 0; i < num; i++)
	{
		printf("%3d", *(arr + i));
	}	
	printf("\n");
}

int main()
{
	int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11};
	int num = sizeof(arr) / sizeof(arr[0]);
	
	showme(arr, num);
	
	inv(arr, 5, 6);
	showme(arr, num);
	
	return 0;
}