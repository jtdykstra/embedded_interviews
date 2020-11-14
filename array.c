#include <stdio.h>

#define ARRAY_SIZE 10

int main()
{
    int values[ARRAY_SIZE] = {1}; // WILL ONLY INITIALIZE the first element! And this is compiler dependent!

    for (int i = 0; i < ARRAY_SIZE; ++i)
    {
        printf("Values at %d is %d\n", i, values[i]);
    }
}