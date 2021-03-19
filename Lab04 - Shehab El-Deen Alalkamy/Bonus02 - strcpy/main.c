#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char str_1[100], str_2[100], index;

    printf("Enter the string: ");
    fgets(str_1, sizeof(str_1), stdin);

    printf("string length: %d\n", strlen(str_1));

    printf("string[4]: %c\n", str_1[4]);
    printf("string[5]: %c\n", str_1[5]);


    for (index = 0; str_1[index] != '\0'; index++)
    {
        str_2[index] = str_1[index];
    }
    printf("index: %d\n", index);

    str_2[index] = '\0';

    printf("Copied string: %s", str_2);

    return 0;
}
