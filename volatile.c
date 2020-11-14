#include <stdio.h>

/*
volatile

A volatile variable is one that can change unexpectedly. 
Consequently, the compiler can make no assumptions about the value of the variable. 
In particular, the optimizer must be careful to reload the variable every time it is 
used instead of holding a copy in a register. Examples of volatile variables are:

(a) Hardware registers in peripherals (e.g., status registers)

(b) Non-stack variables (e.g. globals) referenced within an interrupt service routine.
        compiler will think global is never modified!

(c) Variables shared by multiple tasks in a multi-threaded application.
        may be modified by another task due to premption
*/

volatile int a = 4;

int main()
{
    printf("%d\n", a);
}