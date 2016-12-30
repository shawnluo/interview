#include <stdlib.h>

/*
	void type pointer
*/

int func_a(void *x)
{
    *(int *)x = 100;		//(int *) is used to define the type to (int *)
    return 0;
}

int main(int argc, char **argv)
{
    int y = 1;

    func_a((void *)&y);
    printf("y=%d\n", y);
    return 0;
}
