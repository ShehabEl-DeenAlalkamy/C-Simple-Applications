//H E A D E R S
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>

//D E F I N I T I O N S
#define x_cord 50                      //x-coordinate
#define y_cord 10                      //y-coordinate
#define hl_col 2                       //color of the highlighted choice


//T Y P E  D E F I N I T I O N S
typedef struct Employee Employee;
typedef struct Salary Salary;

//G L O B A L  V A R I A B L E
COORD coord = {0,0};                   //this is global variable || center of axis is set to the top left corner of the screen

//S T R U C T E R S
struct Salary
{
    float gross_sal;
    float taxes;
};

struct Employee
{
    int code;
    char full_name[40];
    Salary salary;
    int allocated;
};


// F U N C T I O N S
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

float get_net_sal(float g_sal, float tax)
{
    return g_sal - tax;
}

void insert_emp(Employee *emp, int x, int y)
{
    gotoxy(x, y++);
    printf("Code: ");
    scanf("%d", &emp->code);

    gotoxy(x, y++);
    printf("Full Name: ");
    scanf("%s", &emp->full_name);

    gotoxy(x, y++);
    printf("Gross Salary($): ");
    scanf("%f", &emp->salary.gross_sal);

    gotoxy(x, y++);
    printf("Taxes($): ");
    scanf("%f", &emp->salary.taxes);

    emp->allocated = 1;
}

void display_emp(Employee emp)
{
    printf("Code: %d\n", emp.code);

    printf("Full Name: %s\n", emp.full_name);

    printf("Net Salary($): %.3f\n\n", get_net_sal(emp.salary.gross_sal, emp.salary.taxes));
}

void statement(char statement[], int x, int y)
{
    system("cls");
    gotoxy(x, y);
    SetColor(15);
    printf("%s", statement);
    getch();
    system("cls");
}

void display_screen(char page_content[][20], int rows, int choice, int color, int x, int y)
{
    int index, col_pos;
    gotoxy(x, y);

    for(index = 0 ; index < rows ; index++)
        {
             if(index == choice - 1)
             {
                 SetColor(color);
                 col_pos = y;        //save the colored choice position
             }

             else
                SetColor(15);

             printf("%s", page_content[index]);
             gotoxy(x, y+=2);
        }
    gotoxy(x + strlen(page_content[choice - 1]) - 1, col_pos);              //point the cursor to the colored choice
}

int movement(int choice, int limit, int x, int y)
{
    char ch = getch();
    if(ch == 80)         //DOWNWARD ARROW
    {
        choice += 1;
        if(choice > limit)
            choice = 1;

        system("cls");
    }
    else if(ch == 72)    //UPWARD ARROW
    {
        choice -= 1;
        if(choice < 1)
            choice = limit;

        system("cls");
    }
    else
        statement("INVALID KEY. Press any key to continue.", x, y);

    return choice;
}

// M A I N   P R O G R A M
int main()
{
    int not_exit = 1, emp_no, index, current_choice = 1, x = x_cord, y = y_cord;
    char menu[3][20] = {"1.New entry.",
                        "2.Display entries.",
                        "3.Exit."};
    char emp_entry_page[2][20] = {"1.Insert an index.",
                                  "2.Back."};
    char ch;

    gotoxy(x_cord - 30, y_cord);
    printf("Welcome user, please enter the maximum number of employees you'd like to insert: ");
    scanf("%d", &emp_no);

    system("cls");
    gotoxy(x_cord - 10, y_cord);
    printf("Thank you. Press any key to continue");
    getch();
    system("cls");

    Employee *emps= (Employee *) malloc(emp_no * sizeof(Employee));

    //Initialization of emps array to detect allocation later
    for(index = 0 ; index < emp_no ; index++)
        emps[index].allocated = 0;


    while(not_exit)
    {
        display_screen(menu, 3, current_choice, hl_col, x, y);

        ch = getch();

        if(ch == 13)
        {
            system("cls");
            SetColor(15);

            if(current_choice == 1)
            {
                while(not_exit)
                {
                    display_screen(emp_entry_page, 2, current_choice, hl_col, x, y);

                    ch = getch();

                    if(ch == 13)
                    {
                        system("cls");
                        gotoxy(x - 8, y);
                        SetColor(15);

                        if(current_choice == 1)
                        {
                            //INSERT THE INDEX OF THE EMPLOYEE LIST
                             printf("Enter the employee index: ");
                             scanf("%d", &index);

                             while(index < 0 || index > emp_no-1)
                             {
                                 statement("INVALID EMPLOYEE INDEX. Press try again.", x - 12, y);
                                 gotoxy(x - 8, y);
                                 printf("Enter the employee index: ");
                                 scanf("%d", &index);
                             }

                             if(emps[index].allocated == 1)
                                 statement("SORRY ALLOCATED INDEX. Press any key to continue", x - 12, y);

                             else
                             {
                                 system("cls");
                                 insert_emp(&emps[index], x, y);
                                 statement("Entry successful. Press any key to continue", x - 12, y);
                             }
                        }
                        else if(current_choice == 2)
                            not_exit = 0;         //go back to main menu
                    }
                    else if(ch == -32)
                        current_choice = movement(current_choice, 2, x - 12, y);
                    else
                        statement("INVALID KEY. Press any key to continue.", x - 12, y);
                }

                //return back to the status before the second page
                current_choice = 1;
                not_exit = 1;
            }
            else if(current_choice == 2)
            {
                int no_entries = 1;     //A flag to detect whether the employee list is empty or not

                for(index = 0 ; index < emp_no ; index++)
                {
                    if(emps[index].allocated == 1)
                    {
                        display_emp(emps[index]);
                        no_entries = 0;
                    }
                }

                if(no_entries)        //The employee list is empty
                    statement("SORRY NO ENTRIES. Press any key to go back to the main menu.", x - 20, y);

                else
                {
                    printf("Press any key to go back to the main menu.");
                    getch();
                }

            }
            else if(current_choice == 3)
            {
                statement("See you soon. Press any key to continue.", x - 12, y);
                not_exit = 0;
            }

            system("cls");
        }
        else if(ch == -32)       //EXTENDED KEY
            current_choice = movement(current_choice, 3, x - 12, y);
        else
            statement("INVALID KEY. Press any key to continue.", x - 12, y);

    }
    return 0;
}


