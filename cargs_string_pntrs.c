#include <stdio.h>

int main(int argc, char **argv, char **envp)
{
    for (int i = 0; i < argc; ++i)
    {
        printf("arg %d is %s\n", i, argv[i]);
    }

    int j = 0;

    while(envp[j] != NULL)
    {
        printf("envp %d is %s\n", j, envp[j]);
        ++j;
    }

}