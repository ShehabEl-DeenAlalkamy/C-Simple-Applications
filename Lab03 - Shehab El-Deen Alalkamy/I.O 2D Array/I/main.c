#include <stdio.h>
#include <stdlib.h>

#define index_size 5
#define col_size 2
#define row_size 3

int main()
{
    //1-Dimensional array
    int arr_1[index_size], index;

    printf("------------------------------------\n");
    printf("1 - D I M E N S I O N A L  A R R A Y\n");
    printf("------------------------------------\n\n");

    printf("***************************\n");
    printf("I N P U T   P R O C E S S\n");
    printf("***************************\n");

    for(index = 0 ; index < index_size ; index++)
    {
        printf("Element[%d]: ", index + 1);
        scanf("%d", &arr_1[index]);
        printf("\n");
    }

    printf("*************\n");
    printf("O U T P U T\n");
    printf("*************\n");
    for(index = 0 ; index < index_size ; index++)
    {
        printf("%d\t", arr_1[index]);

    }

    getch();
    system("cls");

    //2-Dimensional array
    int arr[row_size][col_size], row, col;
    printf("------------------------------------\n");
    printf("2 - D I M E N S I O N A L  A R R A Y\n");
    printf("------------------------------------\n\n");

    printf("***************************\n");
    printf("I N P U T   P R O C E S S\n");
    printf("***************************\n");

    for(row = 0 ; row < row_size ; row++)
    {
        for(col = 0 ; col < col_size ; col++)
        {
            printf("Element[%d][%d]: ", row + 1, col + 1);
            scanf("%d", &arr[row][col]);
        }
        printf("\n");
    }

    printf("*************\n");
    printf("O U T P U T\n");
    printf("*************\n");
    for(row = 0 ; row < row_size ; row++)
    {
        for(col = 0 ; col < col_size ; col++)
            printf("%d\t", arr[row][col]);
        printf("\n\n");
    }
    return 0;
}
