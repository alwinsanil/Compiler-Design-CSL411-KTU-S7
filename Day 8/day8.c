#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

struct production
{
    char lhs[100];
    char rhs[100];
} prod[100];

char input[20], stack[20];
int input_ptr = 0, top = 0, n;

void Sort()
{
    int i, j;
    struct production temp;
    for (i = 0; i < n - 1; i++)
    {
        for (j = 0; j < n - i - 1; j++)
        {
            if (strlen(prod[j].rhs) < strlen(prod[j + 1].rhs))
            {
                temp = prod[j];
                prod[j] = prod[j + 1];
                prod[j + 1] = temp;
            }
        }
    }
}

void main()
{
    int i, j, k, flag;
    int shift, reduce;
    char temp[100];
    stack[0] = '$';
    printf("Enter number of productions: ");
    scanf("%d%*c", &n);
    printf("Enter productions in the form LHS->RHS\n");
    for (i = 0; i < n; i++)
    {
        printf("Enter production %d: ", i + 1);
        gets(temp);
        for (j = 0; temp[j] != '\0' && temp[j] != '-'; j++)
        {
            prod[i].lhs[j] = temp[j];
        }

        prod[i].lhs[j] = '\0';
        j += 2;
        k = 0;
        for (; temp[j] != '\0'; j++)
        {
            prod[i].rhs[k++] = temp[j];
        }

        prod[i].rhs[j] = '\0';
        j += 2;
    }
    Sort();
    printf("\nEnter the string: ");
    gets(input);
    input[strlen(input)] = '$';
    input[strlen(input)] = '\0';
    do
    {
        shift = reduce = 0;
        if (top == 1 && stack[1] == prod[0].lhs[0] && input[input_ptr] == '$')
        {
            printf("\nString accepted\n");
            exit(0);
        }
        for (i = 0; i < n; i++)
        {
            int m = strlen(prod[i].rhs);
            int t = top;
            for (j = m - 1; j >= 0; j--)
            {
                if (prod[i].rhs[j] != stack[t--])
                    break;
            }
            if (j < 0)
            {
                reduce = 1;
                top -= (m - 1);
                stack[top] = prod[i].lhs[0];
                stack[top + 1] = '\0';
                printf("\n%-20s%-20sReduce to %s->%s", stack, input, prod[i].lhs, prod[i].rhs);
                break;
            }
        }
        if (reduce == 0)
        {
            if (input[input_ptr] != '$')
            {
                shift = 1;
                top++;
                stack[top] = input[input_ptr];
                stack[top + 1] = '\0';
                input[input_ptr] = ' ';
                input_ptr++;
                printf("\n%-20s%-20s%-20s", stack, input, "Shift");
            }
        }
    } while (shift == 1 || reduce == 1);
    printf("\nString rejected\n");
}