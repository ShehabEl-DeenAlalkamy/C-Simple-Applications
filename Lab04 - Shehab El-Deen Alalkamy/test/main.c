#include <stdio.h>
#include <stdlib.h>


void e(int n)
{
    if(n > 0)
    {
        e(--n);
        printf("%d", n);
        e(--n);
    }
}

int main()
{
    int a;
    a = 4;
    e(a);

    int x=5;
    int b;
    b = -14%x;
    printf("\n\n%d",b);
}
