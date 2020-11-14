#include <stdio.h>

int main()
{
    int a[5];
    a[1] = 1;
    a[4] = 6;

    printf("a[1] *(a+1) %d\n", *(a+1));
    printf("a[4] *(a+4) %d\n", *(a+4));

}