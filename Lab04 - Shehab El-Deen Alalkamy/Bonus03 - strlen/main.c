#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char str[100];
    int i;

    printf("***************************\n");
    printf("I N P U T   P R O C E S S\n");
    printf("***************************\n");
    printf("Please insert your string: ");
    gets(str);

    printf("\n\n*************\n");
    printf("O U T P U T\n");
    printf("*************\n");

    for (i = 0; str[i] != '\0'; ++i);

    printf("Length of the string: %d\n", i);
     printf("Length of the string: %d\n", strlen(str));

    return 0;
}
