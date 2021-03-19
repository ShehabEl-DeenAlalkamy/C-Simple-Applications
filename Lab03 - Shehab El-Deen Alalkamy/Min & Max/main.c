#include <stdio.h>
#include <stdlib.h>

#define index_size 4
#define col_size 3
#define row_size 3

int main()
{

    //1-Dimensional array
    float arr_1[index_size], max_1, min_1;
    int index, max_1_pos, min_1_pos;

    printf("------------------------------------\n");
    printf("1 - D I M E N S I O N A L  A R R A Y\n");
    printf("------------------------------------\n\n");

    printf("***************************\n");
    printf("I N P U T   P R O C E S S\n");
    printf("***************************\n");

    for(index = 0 ; index < index_size ; index++)
    {
        printf("Element[%d]: ", index + 1);
        scanf("%f", &arr_1[index]);
        printf("\n");
    }

    //minimum value initialization
    min_1 = arr_1[0];
    min_1_pos = 0;

    //maximum value initialization
    max_1 = arr_1[0];
    max_1_pos = 0;

    printf("*************\n");
    printf("O U T P U T\n");
    printf("*************\n");
    for(index = 0 ; index < index_size ; index++)
    {
        printf("%.2f\t", arr_1[index]);

        if(arr_1[index] < min_1)                 //minimum value detection
        {
            min_1 = arr_1[index];
            min_1_pos = index;

        }
        else if(arr_1[index] > max_1)          //maximum value detection
        {
            max_1 = arr_1[index];
            max_1_pos = index;
        }
    }

    printf("\n\n*****************\n");
    printf("M A X  &  M I N\n");
    printf("*****************\n");
    printf("--> Max: %.2f at position: %d\n", max_1, max_1_pos + 1);
    printf("--> Min: %.2f at position: %d\n", min_1, min_1_pos + 1);

    getch();
    system("cls");


    //2-Dimensional array
    float arr[row_size][col_size], max, min;
    int row, col, max_pos[2], min_pos[2];

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
            scanf("%f", &arr[row][col]);
        }
        printf("\n");
    }

    //minimum value initialization
    min = arr[0][0];
    min_pos[0] = 0;
    min_pos[1] = 0;
    //maximum value initialization
    max = arr[0][0];
    max_pos[0] = 0;
    max_pos[1] = 0;

    printf("*************\n");
    printf("O U T P U T\n");
    printf("*************\n");
    for(row = 0 ; row < row_size ; row++)
    {
        for(col = 0 ; col < col_size ; col++)
        {
             printf("%.2f\t", arr[row][col]);

             if(arr[row][col] < min)          //minimum value detection
                {
                    min = arr[row][col];
                    min_pos[0] = row;
                    min_pos[1] = col;
                }
            else if(arr[row][col] > max)      //maximum value detection
                {
                    max = arr[row][col];
                    max_pos[0] = row;
                    max_pos[1] = col;
                }
        }

        printf("\n\n");
    }
    printf("\n\n*****************\n");
    printf("M A X  &  M I N\n");
    printf("*****************\n");
    printf("--> Max: %.2f at row: %d and col: %d\n", max, max_pos[0] + 1, max_pos[1] + 1);
    printf("--> Min: %.2f at row: %d and col: %d\n", min, min_pos[0] + 1, min_pos[1] + 1);

    return 0;
}
