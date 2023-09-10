%{
    #include<stdio.h>
    int yylex();
    int yyerror();
    int yyparse();
%}

%token letter digit

%%
var: letter alnum {printf("Valid Identifier");}
	;
alnum: letter alnum
	| digit alnum
	| 
	;
%%

int yyerror()
{
	printf("Not identifier");
	return 0;
}
void main()
{
	printf("Enter data: ");
	yyparse();
}

