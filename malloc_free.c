#include <stdlib.h>
#include <string.h>
#include <stdio.h>

int main()
{
    char *s = malloc(10);
    memset(s, 'a', 9);
    s[9] = '\0';
    puts(s);
    free(s);
}