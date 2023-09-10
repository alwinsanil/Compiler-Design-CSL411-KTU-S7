#include <stdio.h>
#include <string.h>
#include <ctype.h>
char input[10];
int i, error;
void S();
void A();
void Aprime();
void B();

void main()
{
    i = 0;
    error = 0;
    printf("Enter an expression : ");
    gets(input);
    S();
    if ((strlen(input) == i) && (error == 0))
        printf("String Accepted\n");
    else
        printf("String Rejected\n");
}

void S()
{
    if (input[i] == 'a')
    {
        i++;
        A();
        B();
        if (input[i] == 'e')
            i++;
    }
}

void A()
{
    if (input[i] == 'b')
    {
        i++;
        Aprime();
    }
}

void Aprime()
{
    if (input[i] == 'b')
    {
        i++;
        if (input[i] == 'c')
        {
            i++;
            Aprime();
        }
    }
}

void B()
{
    if (input[i] == 'd')
        i++;
    else
        error = 1;
}