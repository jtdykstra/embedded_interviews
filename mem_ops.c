#include <stdio.h>
#include <string.h>

int main()
{
    char result[40];
    char str1[] = "hello there friend!               ";
    char *str2 = "fuck off  ";
    puts(str1);
    puts(str2);

    memmove(str1+12, str2,  strlen(str2)+1);

    puts(str1);
    puts(str2);

    memcpy(str1+12, str2,  strlen(str2)+1);

    puts(str1);
    puts(str2);
    
}