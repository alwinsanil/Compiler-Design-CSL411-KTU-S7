digit [0-9]
%{
	#include<ctype.h>
	#include<stdio.h>
	char vc=0, cc=0;
%}

%%
[digit][digit] {}
[aeiouAEIOU] {vc++;}
[a-z A-Z] {cc++;}
%%

void main()
{
	printf("Enter the data: ");
	yyin = stdin;
	yylex();
	printf("\nVowel Count: %d\nConsonants: %d\n", vc, cc);
}

int yywrap()
{
	return 1;
}
