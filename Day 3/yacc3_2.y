%{
#include<stdio.h>
%}

%token digit ID                      
%left '+' '-'                                           
%left '*' '/'

%%
E: E '+' E
     |E '*' E
     |E '/' E
     |E '-' E
     |'-'digit
     |'-'ID
     |'('E')'
     |digit
     |ID
     ;
%%

int yyerror(char *s)
{
printf("\nInvalid Expression\n");
exit(0);
}

void main()
{
printf("Enter the expression\n");
yyparse();
printf("\nExpression is valid\n");
}
