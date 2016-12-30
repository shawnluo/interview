#include <stdio.h>

int main(void)
{
	int *pt = NULL;
	int i = 0;
	pt = &i;		//it will be segment fault, if without this!!!!!!
	*pt = 100;
	
	return 0;
}

