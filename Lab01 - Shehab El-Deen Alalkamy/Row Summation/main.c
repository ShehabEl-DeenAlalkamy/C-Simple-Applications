#include <stdio.h>
#include <stdlib.h>

#define col_size 3
#define row_size 3

int main()
{
    float arr[row_size][col_size], sum[row_size] = {0.0};
    int row, col;

    printf("***************************\n");
    printf("I N P U T   P R O C E S S\n");
    printf("***************************\n");
    for(row = 0 ; row < row_size ; row++)
    {
        for(col = 0 ; col < col_size ; col++)
        {
            printf("Element[%d][%d]: ", row + 1, col + 1);
            scanf("%f", &arr[row][col]);
            sum[row] += arr[row][col];
        }
        printf("\n");
    }

    printf("\n\n*************\n");
    printf("O U T P U T\n");
    printf("*************\n");
    for(row = 0 ; row < row_size ; row++)
    {
        for(col = 0 ; col < col_size ; col++)
        {
            printf("%.2f\t", arr[row][col]);
            if(col == 2)
                printf("TOTAL: %.2f", sum[row]);
        }
        printf("\n\n");
    }

    return 0;
}
