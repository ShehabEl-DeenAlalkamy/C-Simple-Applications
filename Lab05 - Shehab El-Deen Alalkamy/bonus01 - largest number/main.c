#include <stdio.h>
#include <stdlib.h>

int max(int a, int b, int c)
{
    int max = a;

    if(b > max)
        max = b;

    if(c > max)
        max = c;

    return max;
}


int main()
{
    int a, b, c;
    printf("1st number: ");
    scanf("%d", &a);
    printf("2nd number: ");
    scanf("%d", &b);
    printf("3rd number: ");
    scanf("%d", &c);

    int largest = max(a, b, c);

    printf("\nLargest number: %d", largest);

    return 0;
}
