#include <stdio.h>
#include <stdlib.h>

typedef struct Employee Employee;
typedef struct Department Department;



struct Employee
{
    int code;
    char full_name[40];
    int salary;
};

struct Department
{
    int dep_no;
    char dep_name[30];
    Employee emp;
};

Department insert_dep(Department dep)
{
    printf("Dep no: ");
    scanf("%d", &dep.dep_no);

    printf("Dep Name: ");
    scanf("%s", dep.dep_name);

    printf("Emp code: ");
    scanf("%d", &dep.emp.code);

    printf("Emp name: ");
    scanf("%s", dep.emp.full_name);

    printf("Emp Salary($): ");
    scanf("%d", &dep.emp.salary);

    return dep;
}

void display_dep(Department dep)
{
    printf("\n\nDep no: %d\n", dep.dep_no);


    printf("Dep Name: %s\n", dep.dep_name);


    printf("Emp code: %d\n", dep.emp.code);


    printf("Emp name: %s\n", dep.emp.full_name);


    printf("Emp Salary($): %d\n", dep.emp.salary);

}

int main()
{
    Department dep;

    dep = insert_dep(dep);

    display_dep(dep);

    return 0;
}
