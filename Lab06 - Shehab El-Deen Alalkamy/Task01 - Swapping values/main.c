#include <stdio.h>
#include <stdlib.h>

void swap_vals(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

int main()
{
    int x, y;
    printf("Enter 2 values.\n");
    printf("Value 1: ");
    scanf("%d", &x);
    printf("value 2: ");
    scanf("%d", &y);

    swap_vals(&x, &y);

    printf("\nValue 1: %d", x);
    printf("\nValue 2: %d\n", y);
    return 0;
}
