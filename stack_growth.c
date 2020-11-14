#include <stdio.h>

int help(int *value)
{
    int newVal = 0;
    printf("original address: %x\n", value);
    printf("new address: %x\n", &newVal);

    if (&newVal > value)
    {
        printf("Stack grows up!\n");
    }
    else
    {
        printf("stack grows down!\n");
    }
    
}

int main() 
{
    int value = 0;
    help(&value);
}