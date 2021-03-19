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
    int i = 1, row = 10, col = 53, min_col = 33, max_col = 73, min_row = 10, max_row = 20;

    gotoxy(col, row);
    printf("%d", i);

    for(i = 2 ; i < 10 ; i++)
    {
        if( ((i-1)%3) == 0 )
        {
            row += 5;
            if( row > max_row )
                row = min_row;

            gotoxy(col, row);
            printf("%d", i);
        } else
        {
            row -= 5;
            col -= 20;

            if( row < min_row )
                row = max_row;

            if( col < min_col )
                col = max_col;

            gotoxy(col, row);
            printf("%d", i);
        }
    }
    getch();
    gotoxy(48, 25);
    return 0;
}
