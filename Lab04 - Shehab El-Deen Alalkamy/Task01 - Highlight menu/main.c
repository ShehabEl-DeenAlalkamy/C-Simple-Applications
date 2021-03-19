#include <stdio.h>
#include <stdlib.h>
#include<windows.h>

#define x_cord 50
#define y_cord 10

COORD coord={0,0};                   // this is global variable
                                    //center of axis is set to the top left cornor of the screen
 void gotoxy(int x,int y)
 {
   coord.X=x;
   coord.Y=y;
   SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),coord);
 }

void SetColor(int ForgC)
 {
    WORD wColor;

    HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_SCREEN_BUFFER_INFO csbi;

    if(GetConsoleScreenBufferInfo(hStdOut, &csbi))
    {
        wColor = (csbi.wAttributes & 0xF0) + (ForgC & 0x0F);
        SetConsoleTextAttribute(hStdOut, wColor);
    }
    return;
}

int main()
{
    int not_exit = 1, index, current_choice = 1;
    char menu[3][15] = {"1.New.", "2.Display.", "3.Exit."}, ch;

    while(not_exit)
    {
        for(index = 0 ; index < 3 ; index++)
        {
             if(index == current_choice-1)
                SetColor(2);
             else
                SetColor(15);

             printf("%s\n\n", menu[index]);
        }


        ch = getch();

        if(ch == 13)
        {
            system("cls");
            gotoxy(x_cord, y_cord);
            SetColor(2);
            printf("%s", menu[current_choice-1]);
            getch();
            system("cls");

            if(current_choice == 3)
            {
                system("cls");
                gotoxy(50, y_cord);
                SetColor(15);
                printf("See you soon.\n");
                not_exit = 0;
                getch();
            }
        }
        else if(ch == -32)
        {
            ch = getch();
            if(ch == 80)    //DOWNWARD ARROW
            {
                current_choice += 1;
                if(current_choice > 3)
                    current_choice = 1;

                system("cls");

               /* gotoxy(x_cord, y_cord);
                SetColor(2);
                printf("%s", menu[current_choice-1]);
                if(current_choice == 3)
                    getch();*/

            }
            else if(ch == 72)    //UPWARD ARROW
            {
                current_choice -= 1;
                if(current_choice < 1)
                    current_choice = 3;

                system("cls");

                /*gotoxy(x_cord, y_cord);
                SetColor(2);
                printf("%s", menu[current_choice-1]);
                if(current_choice == 3)
                    getch();*/
            }
            else
            {
                system("cls");
                gotoxy(45, y_cord);
                SetColor(15);
                printf("INVALID CHOICE. PRESS ANY KEY.");
                getch();
                system("cls");
            }
        }
        else{
                system("cls");
                gotoxy(42, y_cord);
                SetColor(15);
                printf("INVALID CHOICE. PRESS ANY KEY.");
                getch();
                system("cls");
        }

      /*  if(current_choice == 3)
        {
            system("cls");
            gotoxy(50, y_cord);
            SetColor(15);
            printf("See you soon.\n");
            getch();
            not_exit = 0;

        }
        else
        {
            getch();
            system("cls");
        }*/

    }
    return 0;
}
