#include <stdio.h>
#include <string.h>

void processString(char *str)
{
    for (int i = 0; str[i] != '\0'; ++i)
    {
        printf("character at ind %d is %c\n", i, str[i]);
    }
}

int main()
{
    char *str = "abcdefg";
    char *str2 = "test";

    processString(str);
    printf("%s\n", str);

    printf("%s is %d chars long\n", str, (int) strlen(str));
    printf("strcmp %s %s: %d\n", str, str, strcmp(str, str));
    printf("strcmp %s %s: %d\n", str, str2, strcmp(str2, str));
    printf("strcmp %s %s: %d\n", str2, str, strcmp(str, str2));
    // strcpy
    // strcat
}