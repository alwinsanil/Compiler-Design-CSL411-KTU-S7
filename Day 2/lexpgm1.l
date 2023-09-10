%{
	int nl=0, nw=0, nc=0;
%}

%%
\n {nl++; nw++;}
\t {nw++;}
([ ])+ {nw++;}
. {nc++;}
%%

void main()
{
	printf("Enter the data: ");
	yyin = stdin;
	yylex();
	printf("\nLines: %d\nWords: %d\nCharacters: %d\n", nl,nw,nc);
}

int yywrap()
{
	return 1;
}
