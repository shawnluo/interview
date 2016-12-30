#include <stdlib.h>
#include <inttypes.h>
#include <stdio.h>
#include <stdint.h>
#include <memory.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <sys/mman.h>

int main(void)
{
    /***********************************
    *       1. one way to test memory
    ***********************************/

    //  Create an int.
    int x = 0;

    //  Find its address.
    char buf[100];

	// PRIuPTR is the equivalent of u (in "%u") for uintptr_t values
    sprintf(buf, "%" PRIuPTR, (uintptr_t)&x);
    printf("The address of x is %s.\n", buf);

    //  Read the address from buf to u.
    uintptr_t u;
    sscanf(buf, "%" SCNuPTR, &u);

    //  Convert the integer value to an address.
    int *p = (int *)u;

    //  Modify the int through the new pointer.
    *p = 123;

    //  Display the int.
    printf("x = %d\n", x);

    /***********************************
    *       2. another way to test memory!
    ***********************************/
    int var = 7456;
    printf("Adress of var = %x, var=%d\n", &var, var);
    int *ptr = (int *)0x22cd28;
    printf(" ptr points to %x\n", ptr);
    //*ptr = 123;			//this will cause trouble!
    printf("New value of var=%d\n", var);

    /************************************
     *      3. the third way to test memory!
     *              For accessing Specific memory from user space, we have to map the memory Address to Programs Virtual Address using mmap(), 
	 *				the below C code shows the implementation:
     *
     *              Take a file "test_file" containing "ABCDEFGHIJ".
     **************************************/

	printf("=====================Demo3==================\n");
    char *map_base_addr; // Maping Base address for file
    int  fd;             // File descriptor for open file
    int  size = 12;

    fd            = open("test_file", O_RDWR);                                   //open the file for reading and writing
    map_base_addr = mmap(NULL, size, PROT_READ | PROT_WRITE, MAP_SHARED, fd, 0); // Maping file into memory

    char *ch = map_base_addr;
    int  i;

    /*Printing first 10 char*/
    for (i = 0; i < size; i++)
    {
        fputc(*(ch + i), stdout);
    }
    printf("\n");

    *(ch + 1) = 's';
    *(ch + 4) = 's';
    *(ch + 7) = 's';

    /*Printing char after modification*/
    for (i = 0; i < size; i++)
    {
        fputc(*(ch + i), stdout);
    }
    printf("\n");
    /* Finally unmap the file. This will flush out any changes. */
    munmap(map_base_addr, size);

    return 0;
}
