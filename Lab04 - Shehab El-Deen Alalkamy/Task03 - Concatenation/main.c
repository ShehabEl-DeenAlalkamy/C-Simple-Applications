#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char f_name[5], l_name[30];

    printf("***************************\n");
    printf("I N P U T   P R O C E S S\n");
    printf("***************************\n");

    printf("Please insert your first name: ");
    gets(f_name);

    printf("\n\nPlease insert your last name: ");
    gets(l_name);

    strcat(f_name, l_name);            //concatenate l_name in f_name

    printf("\n\n*************\n");
    printf("O U T P U T\n");
    printf("*************\n");
    printf("Your full name is: %s\n", f_name);

    return 0;
}
