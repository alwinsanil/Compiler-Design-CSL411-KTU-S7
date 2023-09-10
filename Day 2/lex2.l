letter [a-zA-Z]
%{
	#include<ctype.h>
	#include<stdio.h>
	char a[50];
%}

%%
letter* {for(int i=0; i<=yyleng; i++)
		{
			if(yytext[i]=='a')
				if(yytext[i+1]=='b')
					if(yytext[i+2]=='c')
					{
						yytext[i]='A';
						yytext[i+1]='B';
						yytext[i+2]='C';
					}
		}
		strcat(a,yytext);
		strcat(a, " ");
		}

%%

void main()
{
	printf("Enter the data: ");
	yyin = stdin;
	yylex();
	printf("%s\n", a);
}

int yywrap()
{
	return 1;
}
