#include <stdlib.h>
#include <stdio.h>

int power(int x, unsigned int y)
{
	if(y == 0)
	{
		return 1;
	}
	else if(y % 2 == 0)
	{
		return power(x, y / 2) * power(x, y / 2);
	}
	else
	{
		return x * power(x, y / 2) * power(x, y /2);
	}
}

int main(void)
{
	int x = 2;
	unsigned int y = 3;

	printf("%d\n", power(x, y));

	return 0;
}

