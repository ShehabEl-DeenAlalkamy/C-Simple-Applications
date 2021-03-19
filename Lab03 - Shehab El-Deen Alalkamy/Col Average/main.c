#include <stdio.h>
#include <stdlib.h>

#define col_size 3
#define row_size 3

int main()
{
    float arr[row_size][col_size], col_sum[col_size] = {0.0}, col_avg[col_size] = {0.0};
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
        }

        printf("\n");
    }

    //Column average calculation - Transpose of the matrix method
     for(col = 0 ; col < col_size ; col++)
    {
        for(row = 0 ; row < row_size ; row++)
            col_sum[col] += arr[row][col];
        col_avg[col] = col_sum[col] / 3;
    }


    printf("\n\n*************\n");
    printf("O U T P U T\n");
    printf("*************\n");
    for(row = 0 ; row < row_size ; row++)
    {
        for(col = 0 ; col < col_size ; col++)
            printf("\t\t%.2f", arr[row][col]);

        printf("\n\n");
    }

    printf("\tAVG: \t");
    for(col = 0 ; col < col_size ; col++)
        printf("%.3f\t\t", col_avg[col]);

    return 0;
}
