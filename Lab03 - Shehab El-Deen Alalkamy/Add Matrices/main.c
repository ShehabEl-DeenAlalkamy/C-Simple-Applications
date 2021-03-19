#include <stdio.h>
#include <stdlib.h>

#define index_size 5

int main()
{
    //1-Dimensional array
    float arr_1[index_size], arr_2[index_size], arr_3[index_size] = {0.0};
    int index;

    printf("------------------------------------\n");
    printf("1 - D I M E N S I O N A L  A R R A Y\n");
    printf("------------------------------------\n\n");

    printf("***************************\n");
    printf("I N P U T   P R O C E S S\n");
    printf("***************************\n");

    printf("FOR FIRST MATRIX:\n");
    for(index = 0 ; index < index_size ; index++)
    {
        printf("Element_1[%d]: ", index + 1);
        scanf("%f", &arr_1[index]);
        printf("\n");
    }

    printf("\nFOR SECOND MATRIX:\n");
    for(index = 0 ; index < index_size ; index++)
    {
        printf("Element_2[%d]: ", index + 1);
        scanf("%f", &arr_2[index]);
        printf("\n");

        arr_3[index] = arr_1[index] + arr_2[index];
    }

    printf("\n\n*************\n");
    printf("O U T P U T\n");
    printf("*************\n");
    for(index = 0 ; index < index_size ; index++)
    {
        printf("%.2f\t", arr_3[index]);

    }

    printf("\n\n");

    return 0;
}
