#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define str_size 20


/*
    THIS IS WHAT HELPED ME OUT TO DETECT THE ENTER KEY

    HINT: Assuming you mean a CARRIAGE RETURN, it is ASCII 13 or Hexadecimal 0x0D (hence my username 0A0D).
    If you mean LINE FEED, it is ASCII 10 or Hexadecimal 0x0A. I will let you enhance your question more before
    I answer further.
*/


int main()
{
    char str[str_size];
    int index = 0, not_enter_key = 1, within_str_length = 1;

    /* NORMAL METHOD
    printf("***************************\n");
    printf("I N P U T   P R O C E S S\n");
    printf("***************************\n");
    printf("Please insert your full name: ");
    gets(full_name);

    printf("\n\n*************\n");
    printf("O U T P U T\n");
    printf("*************\n");
    printf("You inserted the following: %s\n", full_name);
    */


    //Character by character method
    printf("***************************\n");
    printf("I N P U T   P R O C E S S\n");
    printf("***************************\n");

    printf("\nPlease insert your paragraph: ");

    //NOTE: str[0] = fgetc(stdin);    THEN YOU CAN USE 10 0x0A as the enter key detector

    do{
        str[index] = getche();
        str[index+1] = '\0';

        if(strlen(str) > str_size-2)
            within_str_length = 0;
        else if(str[index] == 13)
            not_enter_key = 0;

        index++;
    } while(not_enter_key && within_str_length);

    str[index] = '\0';     //adding our terminator

    printf("\n\n*************\n");
    printf("O U T P U T\n");
    printf("*************\n");
    printf("You inserted the following: %s\n", str);

    return 0;
}
