#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Employee Employee;
//typedef struct Name Name;
typedef struct Salary Salary;

struct Salary
{
    float gross_sal;
    float taxes;
};

/*struct Name
{
    char f_name[15];
    char l_name[15];
};*/

struct Employee
{
    int code;
    //Name name;
    char full_name[40];
    Salary salary;
};

/*char[] get_full_name(char f_name[], int f_len, char l_name[], int l_len)
{
    f_name[f_len + 2] = '\0';
    f_name[f_len + 1] = ' ';
    char full_name[] = strcat(f_name, l_name);
    return full_name;
}*/

float get_net_sal(float g_sal, float tax)
{
    return g_sal - tax;
}

Employee insert_emp(Employee emp)
{
    printf("***************************\n");
    printf("I N P U T   P R O C E S S\n");
    printf("***************************\n");

    printf("Please insert the following employee's information:\n");
    printf("Code: ");
    scanf("%d", &emp.code);

    printf("Full Name: ");
    scanf("%s", emp.full_name);

    /*printf("First Name: ");
    gets(emp.name.f_name);

    printf("Last Name: ");
    gets(emp.name.l_name);*/

    printf("Gross Salary($): ");
    scanf("%f", &emp.salary.gross_sal);

    printf("Taxes($): ");
    scanf("%f", &emp.salary.taxes);

    return emp;
}


void display_emp(Employee emp)
{
    printf("*************\n");
    printf("O U T P U T\n");
    printf("*************\n");
    printf("Code: %d\n", emp.code);

    printf("Full Name: %s\n", emp.full_name);

    //printf("Full Name: %s", get_full_name(emp.name.f_name, strlen(emp.name.f_name), emp.name.l_name, strlen(emp.name.l_name)));

    printf("Net Salary($): %.3f\n\n", get_net_sal(emp.salary.gross_sal, emp.salary.taxes));
}

int main()
{
    Employee emp;

    //INPUT
    emp = insert_emp(emp);

    printf("\n\n");

    //DISPLAY
    display_emp(emp);

    return 0;
}
