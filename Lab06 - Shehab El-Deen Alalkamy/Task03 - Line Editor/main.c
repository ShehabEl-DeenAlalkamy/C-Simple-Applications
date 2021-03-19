#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <windows.h>

#define str_size 20

COORD coord = {0,0};

void gotoxy(int x,int y)
 {
   coord.X=x;
   coord.Y=y;
   SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),coord);
 }


int main()
{
    int letters, index = 0, not_enter_key = 1, within_str_length = 1;
    int line_st = 0, line_end = 0, cursor = 0;
    int y = 2;

    printf("Enter the maximum number of letters: ");
    scanf("%d", &letters);

    char *str = (char *) malloc(letters * sizeof(char));
    str[0] = '\0';

    char ch;

    printf("Please insert your paragraph: \n");

    do{
        ch = getch();

        if(ch == 13)
        {
            //end input process
            not_enter_key = 0;
        }
        else if(ch == -32)  //extended key
        {
            ch = getch();

            if(ch == 75)    //left arrow
            {
                //move step to the left
                cursor--;
                if(cursor < line_st)
                    {
                        cursor = line_st;
                        gotoxy(cursor, y);
                    }
                else
                    gotoxy(cursor, y);
            }
            else if(ch == 77)   //right arrow
            {
                //move step to the right
                cursor++;
                if(cursor > line_end)
                {
                    cursor = line_end;
                    gotoxy(cursor, y);
                }
                else
                    gotoxy(cursor, y);
            }
            else if(ch == 71)    //home
            {
                //go to start
                cursor = line_st;
                gotoxy(cursor, y);
            }
            else if(ch == 79)
            {
                //go to end
                cursor = line_end;
                gotoxy(cursor, y);
            }
            else if(ch == 83)   //delete
            {
                str[cursor] = ' ';
                system("cls");
                printf("Enter the maximum number of letters: \n");
                printf("Please insert your paragraph: \n");
                printf("%s", str);
                gotoxy(cursor, y);
                cursor--;
            }
        }
        else if(ch == 8)     //backspace
        {
            //remove the previous letter and displace the whole string one step backward
            int counter;

            for(counter = cursor-1 ; str[counter]!= '\0' ; counter++)
                str[counter] = str[counter+1];

            system("cls");
            printf("Enter the maximum number of letters: \n");
            printf("Please insert your paragraph: \n");
            printf("%s", str);
            gotoxy(cursor-1, y);
            cursor--;
        }
        else
        {
            //save it to the string
            if(strlen(str) > letters-2)
                within_str_length = 0;
            else
            {
                printf("%c", ch);
                str[index] = ch;
                str[index + 1] = '\0';
                index++;
                line_end++;
                cursor = line_end;
                gotoxy(line_end, y);
            }
        }


    } while(not_enter_key && within_str_length);


    system("cls");
    printf("Paragraph: %s\n", str);

    /*if(strlen(str) > str_size-2)
        within_str_length = 0;
    else if(str[index] == 13)
        not_enter_key = 0;
    else if()

    index++;


    str[index] = '\0';     //adding our terminator



    printf("\n\n*************\n");
    printf("O U T P U T\n");
    printf("*************\n");
    printf("You inserted the following: %s\n", str);

*/


    return 0;
}
