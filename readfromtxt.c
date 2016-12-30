#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#if 0
int main(void)
{
	FILE *fp;
	char str[160];
	
	fp = fopen("file.txt", "r");
	if(fp == NULL)
	{
		perror("Error opening file");
		return -1;
	}
	
	while(!feof(fp))
	{
		if(fgets(str, 20, fp) != NULL)
		{
			//puts(str);
			fflush(stdout);
			puts(str);
		}
		//fflush(stdout);
	}
	fclose(fp);
	
	return 0;
}
#else
	
int test()
{
	i = 5;
	
	return i;
}
int main(void)
{
	char *mem = "Hello world";
	int k = test();
	printf("%d\n", k);
	
	return 0;
}
#endif