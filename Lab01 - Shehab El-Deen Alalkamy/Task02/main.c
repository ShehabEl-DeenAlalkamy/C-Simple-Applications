#include <stdio.h>
#include <stdlib.h>

int main()
{
    int y;

    printf("Enter a number: ");

    scanf("%d", &y);

    printf("The hexadecimal of %d: %x", y, y);

    getch();

    return 0;
}
