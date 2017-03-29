#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <assert.h>

//#define strcpy	//strcpy
//#define strcat	//strcat
#define strstr	//strstr

#if defined xx
/*
	string copy
*/
int my_strcpy(char *des, const char *src)
{
	if((des == NULL) || (src == NULL))
	{
		return 0;
	}
	
	char *address = des;
	while((*des++ = *src++) != '\0')
	{
	}
	
	return 1;

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

#elif defined yy

int my_strcat(char *pDes, const char *pSrc)
{
	if((pDes == NULL) || (pSrc == NULL))
	{
		return 0;
	}
	
	int n = strlen(pDes);
	pDes = pDes + n;
	
	while((*pDes++ = *pSrc++) != '\0')
	{
		
	}
	
	return 1;
}
	
int main(void)
{
	char pSrc[] = {"show"};
	char pDes[30] = {"1234me"};
	
	my_strcat(pDes, pSrc);
	
	printf("%s\n", pDes);

	return 0;
}

#elif defined strstr
int my_strstr(char *pStr, char *pSub)
{
	char *p1, *p2 = pSub;
	
	if((pStr == NULL) || (pSub == NULL))
	{
		return 0;
	}
	
	if((*pStr == '\0') || (*pSub == '\0'))
	{
		return 0;
	}
	
	for(p1 = pStr; p1 != '\0'; p1++)
	{
//		while((pSub++ == p1++) != '\0')
		for(p2 = pSub; p2 != '\0' && p1 != '\0'; p1++, p2++)
		{
			if(p2 != p1)
			{
				p2 = pSub;
				break;
			}
		}
		
		if(p2 == '\0')
		{
			return 1;
		}
	}
}

int main(void)
{
	char *pStr = "gooday";
	char *pSub = "dy";
	//my_strstr();
	printf("%d\n", my_strstr(pStr, pSub));
	return 0;
}

#endif