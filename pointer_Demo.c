#include <stdio.h>
#include <stdlib.h> 
#include <string.h>



/***************************************************************
	remainning problems:
	1. function pointer
	2. return local pointer in a function to its caller, is it legal?
	3. malloc a pointer in a function, then free the whole function in its caller. is it legal?
****************************************************************/

#if 0
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

int *arr = NULL;

int* twoSum(int* nums, int numsSize, int target) 
{
    int i, j;
	
	arr = (int *)malloc(2 * sizeof(int));
	memset(arr, 0, 2 * sizeof(int));

    if(numsSize < 2)
    {
        printf("wrong number size!\n");
        return NULL;
    }

    for(i = 0; i < numsSize - 1; i++)
    {
        for(j = i + 1; j < numsSize; j++)
        {
            if(target == *(nums + i) + *(nums + j))
            {
                *(arr + 0) = *(nums + i);
                *(arr + 1) = *(nums + j);
                
                return arr;
            }
        }
    }
    
    printf("cannot find the numbers!\n");
    return NULL;
}


int main(void)
{
	int nums[3] = {3, 2, 4};
	/*
	int *nums = NULL;
	*(nums + 0) = 3;
	*(nums + 1) = 2;
	*(nums + 2) = 4;
	*/
	
	int numsSize = 3;
	int target = 6;
	int *array = NULL;

//	memset(arr, 0, 2 * sizeof(int));
	int i;
	
	array = twoSum(nums, numsSize, target);
	
	for(i = 0; i < 2; i++)
		printf("%d\n", *(array + i));

	free(arr);
	
	return 0;
}

#else

int *callme(void)//(int num)
{
	int i = 10;
	int num = 500;
	int *p = NULL;
	p = (int *)malloc(sizeof(int));
	memset(p, 0, sizeof(int));
	p = &num;
	//*p = num;

	//printf("%d\n", *p);

	return p;
}

int main(void)
{
	int (*pointer)();// = NULL;

	pointer = *callme;
	
	printf("%d\n", (*pointer)());
	free(pointer);

	return 0;
}

#endif

