//H E A D E R S
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>
#include <conio.h>

//D E F I N I T I O N S
#define x_cord 50                      //x-coordinate
#define y_cord 10                      //y-coordinate
#define hl_col 2                       //color of the highlighted choice


//T Y P E  D E F I N I T I O N S
typedef struct Employee Employee;
typedef struct Salary Salary;


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

float get_net_sal(float g_sal, float tax)
{
    return g_sal - tax;
}

void insert_emp(Employee *emp, int x, int y)
{
    printf("before malloc: %d", emp);
    //emp = (Employee *) malloc(1 * sizeof(Employee));
    //printf("\nafter malloc: %d\n", emp);
   // gotoxy(x, y++);
    printf("Code: ");
    scanf("%d", &emp->code);

    printf("\ncode value: %d\n", emp->code);

    //gotoxy(x, y++);
    printf("Full Name: ");
    scanf("%s", &emp->full_name);

    printf("\nname value: %s\n", emp->full_name);

    //gotoxy(x, y++);
    printf("Gross Salary($): ");
    scanf("%f", &emp->salary.gross_sal);
    printf("\ngross value: %f\n", emp->salary.gross_sal);

    //gotoxy(x, y++);
    printf("Taxes($): ");
    scanf("%f", &emp->salary.taxes);
    printf("\ntax value: %f\n", emp->salary.taxes);

    emp->allocated = 1;
    //return emp;
}
void display_emp(Employee emp)
{
    printf("Code: %d\n", emp.code);

    printf("Full Name: %s\n", emp.full_name);

    printf("Net Salary($): %.3f\n\n", get_net_sal(emp.salary.gross_sal, emp.salary.taxes));
}


int main()
{
    int not_exit = 1, emp_no, index, current_choice = 1, x = x_cord, y = y_cord;
    char menu[3][20] = {"1.New entry.",
                        "2.Display entries.",
                        "3.Exit."};
    char emp_entry_page[2][20] = {"1.Insert an index.",
                                  "2.Back."};
    char ch;

    printf("Emp NO: ");
    scanf("%d", &emp_no);

    Employee *emps= (Employee *) malloc(emp_no * sizeof(Employee));

    for(index = 0 ; index < emp_no ; index++)
        emps[index].allocated = 0;


    insert_emp(&emps[0], x, y);

    display_emp(emps[0]);






    return 0;
}
