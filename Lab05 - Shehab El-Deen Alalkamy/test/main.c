#include <stdio.h>
#include <stdlib.h>


void dispStrings(int n, int m, char menu[n][m])
{
	int i=0;
	for(i=0;i<n;i++)
	{
		printf("%s\n",menu[i]);
	}

}

int main()
{
	 char menu[3][20] = {"1.New entry.",
                        "2.Display entries.",
                        "3.Exit."};

    dispStrings(menu,3, 20)	;
}
