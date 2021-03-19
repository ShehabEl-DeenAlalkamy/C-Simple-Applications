#include <stdio.h>
#include <stdlib.h>

int main()
{
    char x;

    printf("Enter a character: ");

    scanf("%c", &x);

    printf("The ASCII of %c: %d\n\n", x, x);

    getch();

    return 0;
}
