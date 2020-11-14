#include <stdio.h>

int helper(int *a, int *b)
{
    printf("a is %d\n", *a);
    printf("b is %d\n", *b);
}

int (*fPtr)(int *, int*) = helper;

typedef int (*fPtrType)(int *, int *);

int main()
{
   int a = 2;
   int b = 3;
   fPtrType ptr1 = helper;

   fPtr(&a, &b); 
   ptr1(&a, &b);
}