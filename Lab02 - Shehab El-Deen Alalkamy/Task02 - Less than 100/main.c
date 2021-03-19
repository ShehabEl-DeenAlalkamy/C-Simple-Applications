#include <stdio.h>
#include <stdlib.h>

#include<windows.h>

COORD coord={0,0};                   // this is global variable
                                    //center of axis is set to the top left cornor of the screen
 void gotoxy(int x,int y)
 {
   coord.X=x;
   coord.Y=y;
   SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),coord);
 }

int main()
{
    int sum_less_than_100 = 1;
    float sum = 0.0;

    while(sum_less_than_100)
    {
        float number;
        printf("Please enter a number.\nYour input: ");
        scanf("%f", &number);
        printf("\n\n");

        sum += number;

        if(sum > 100.0)
        {
            sum_less_than_100 = 0;
            printf("You have exceeded 100 as a summation.\nCurrent Summation: %f", sum);
            getch();
        }
    }

    system("cls");
    gotoxy(48, 10);
    printf("H A V E  N I C E  D A Y.");
    getch();
    system("cls");
    gotoxy(0, 0);

    return 0;
}
