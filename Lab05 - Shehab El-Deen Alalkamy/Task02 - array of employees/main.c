#include <stdio.h>
#include <stdlib.h>

#define emp_no 2

typedef struct Employee Employee;
typedef struct Salary Salary;

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
};

float get_net_sal(float g_sal, float tax)
{
    return g_sal - tax;
}

Employee insert_emp(Employee emp)
{
    printf("Code: ");
    scanf("%d", &emp.code);

    printf("Full Name: ");
    scanf("%s", emp.full_name);


    printf("Gross Salary($): ");
    scanf("%f", &emp.salary.gross_sal);

    printf("Taxes($): ");
    scanf("%f", &emp.salary.taxes);

    return emp;
}


void display_emp(Employee emp)
{
    printf("Code: %d\n", emp.code);

    printf("Full Name: %s\n", emp.full_name);

    printf("Net Salary($): %.3f\n\n", get_net_sal(emp.salary.gross_sal, emp.salary.taxes));
}


int main()
{
    Employee arr_emp[emp_no];
    int index;

    //INPUT
    for(index = 0 ; index < emp_no ; index++)
    {
        printf("Employee no %d:\n", index + 1);
        arr_emp[index] = insert_emp(arr_emp[index]);
        printf("\n");
    }

    printf("\n\n");

    //DISPLAY
    for(index = 0 ; index < emp_no ; index++)
    {
        printf("Employee no %d:\n", index + 1);
        display_emp(arr_emp[index]);
        printf("\n");
    }

    return 0;
}
