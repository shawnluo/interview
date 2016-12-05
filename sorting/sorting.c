#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int getPivot(int i, int j);

void quicksort(int *arr, int startNum, int endNum);

char *GetMemory(void)
{
    char p_arr[] = "p_arr : hello world";
    char *p_heap = (char *)malloc(sizeof(char) * 20);
    char *ptr    = "ptr : hello world";

    strcpy(p_heap, "p_heap: hello world!");

    printf("%08X\n", p_arr);
    printf("%08X\n", &p_arr);
    printf("%08X\n", p_heap);
    printf("%08X\n", &p_heap);
    printf("%08X\n", ptr);
    printf("%08X\n", &ptr);
    puts(p_arr);
    puts(ptr);
    puts(p_heap);

    return ptr;
}

void swap(int *a, int *b)
{
    int tmp = 0;

    tmp = *a;
    *a  = *b;
    *b  = tmp;
}

void my_print(int *arr, int len)
{
    int i;

    for (i = 0; i < len; i++)
    {
        printf("%4d, ", arr[i]);
    }
    printf("\n");
}

#define quick
//#define tt	//tmp
//#define xx	//bubble 1
//#define yy	//bubble 2 min/max

int len;

int main(void)
{
//	char *str       = NULL;
//	str             = GetMemory();

//	printf("%08X\n", str);
//	printf("%08X\n", &str);
//	puts(str);

    int arr[] = { 1, 11, 211, 6, 12, -3, 77, 0, 432 };
    len = sizeof(arr) / sizeof(arr[0]);
	int rate = 0;

//	len = 99999999;

//    printf("%d\n", len);

#ifdef xx
    //bubble 1
    
    int i, j;
    for (i = 0; i < len - 1; i++)
    {
        for (j = 0; j < len - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])            //from small -> big
            {
                swap(&arr[j], &arr[j + 1]);
				rate++;
            }
        }
    }

    my_print(arr, len);
	printf("rate = %d\n", rate);

#elif defined yy
	int min = 0, tmp = 0;
    int i, j;

	for(i = 0; i < len - 1; i++)
	{
		min = arr[i];
		tmp = i;
		for(j = i + 1; j < len; j++)
		{
			if(min > arr[j])
			{
				min = arr[j];
				tmp = j;
			}
		}
		
		if(tmp != i)
		{
			swap(&arr[i], &arr[tmp]);
			rate++;
		}
	}
	
	my_print(arr, len);
	printf("rate = %d\n", rate);

#elif defined tt	//smaller -> bigger
	int i, j;
	for(i = 0; i < len; i++)
	{
		for(j = 0; j < len - i - 1; j++)
		{
			if(arr[j] > arr[j + 1])
			{
				swap(&arr[j], &arr[j + 1]);
				rate++;
			}
		}
	}
	my_print(arr, len);
	printf("rate = %d\n", rate);

	int k = 5, jj;
//	k++;
	jj = k++;
	int rr = k;
//	printf("%d, %d\n", k++, ++k);
	printf("%d, %d\n", jj, rr);

#elif defined quick
	quicksort(arr, 0, len - 1);	
	my_print(arr, len);
//	printf("%d\n", i);
#endif

    return 0;
}


void quicksort(int *arr, int startNum, int endNum)
{
	int pivot;
	int left;
	int right;

	if(startNum < endNum)
	{
//		return;

		pivot = startNum;
		left = startNum + 1;
		right = endNum;
		
		while(left <= right)
		{
			while((arr[left] <= arr[pivot]) && (left <= endNum))
			{
				left++;
			}

			while((arr[right] > arr[pivot]) && (right >= startNum))
			{
				right--;
			}

			if(left < right)
			{
				swap(&arr[left], &arr[right]);
			}
			
			swap(&arr[startNum], &arr[right]);
		}

		quicksort(arr, startNum, right - 1);
		quicksort(arr, right + 1, endNum);
	}
}
