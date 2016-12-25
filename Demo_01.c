/*
	Demo 01: 
		1. sructure
		2. typedef
		3. malloc & free
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct foo
{
	int i;
	int j;	
}Foo;

Foo* bar(void)
{
	Foo *baz;
	baz = malloc(sizeof(Foo));
	printf("%d\n", sizeof(Foo));
	
	return baz;
}

int main(void)
{
	Foo* fun;
	Foo* ttt;
	fun = bar();
	free(fun);		// WORKS! It will free baz.
	free(ttt);		// WRONG! 
	
	return 0;
}