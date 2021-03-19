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
    gotoxy(48, 10);

    printf("W E L C O M E  U S E R !");
    getch();
    system("cls");

    int valid_choice_or_exit = 1;
    do{
            gotoxy(0, 0);
            printf("Please select a choice of the following: \n");
            printf("a- Choice 1. \nb- Choice 2.\nc- Quit.\n\nYour Choice: ");
            char choice = getche();
            getch();

            system("cls");
            gotoxy(48, 10);

            if(choice != 'a' && choice != 'b' && choice != 'c' )
            {
                printf("SORRY, INVALID CHOICE, BYE..");
                valid_choice_or_exit = 0;
                getch();
                system("cls");
            }
            else
            {
                if(choice == 'a')
                    printf("You chose choice 1.");
                else if(choice == 'b')
                    printf("You chose choice 2.");
                else
                {
                    valid_choice_or_exit = 0;
                    printf("See you soon..");
                }
                getch();
                system("cls");
            }
    } while(valid_choice_or_exit);

    return 0;
}
