#include <stdio.h>

int main()
{
    volatile int *a = (volatile int *) 0x0000000000000000; // 64 bit address
    // printf("%x\n", *a); // likely seg fault
    // *a = 2; probable seg fault
}