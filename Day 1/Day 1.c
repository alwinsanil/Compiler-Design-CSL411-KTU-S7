#include <stdlib.h>
#include <stdio.h>
#include <string.h>
char word[50],word2[50],word3[50];

int isKW()
{
if(strcmp(word,"void")==0||strcmp(word,"char")==0||strcmp(word,"int")==0||strcmp(word,"float")==0||strcmp(word,"main")==0)
{
return 1;
}
else
return 0;

}

void main()
{
char ch[100],c;
int k=0;
FILE *fp = fopen("code.txt","r");
if(fp==NULL)
printf("file does not exist\n");
else
{
while ((c=getc(fp)) != EOF)
{
if (c == ' ' || c == '\n')
ch[k]='~';
else
ch[k]=c;
++k;
}
ch[k]='\0';
//printf("%s\n",ch);
}
fclose(fp);
int ikw,len,state=0;
len = strlen(ch);
int i = 0;
int j;
do
{
j=0;	
switch(state)
{
case 0:
{
if(ch[i] == '>')
state = 1;
else if(ch[i] == '<')
state = 4;
else if(ch[i] == '!')
state = 7;
else if(ch[i] == '=')
state = 9;
else if(ch[i]>='0'&&ch[i]<='9') 
{
state = 11;
word2[j]=ch[i];
}
else if(ch[i]>='A'&&ch[i]<='z')
{
state = 15;
word[j]=ch[i];
}
else if(ch[i]=='~')
state = 19;
else if(ch[i]=='('||ch[i]==')'||ch[i]=='}'||ch[i]=='{'||ch[i]==';'||ch[i]==',')
{
printf("%c : Special character\n",ch[i]);
++i;
}
else if(ch[i]=='"')
{
j = 0;
i++;
while(1)
{
word3[j] =ch[i];
i++;
j++;
if(ch[i]=='"')
break;
}
word3[++j] = '\n';
printf("\"%s\" : String\n",word3);
i++;
}
else if(ch[i]=='+'||ch[i]=='-'||ch[i]=='*'||ch[i]=='/')
{
printf("%c : Arithematic Operator\n",ch[i]);
++i;
}
}
break;
case 1:
{
++i;
if(ch[i] == '=')
printf(">= : Relational operator\n");
else
printf("> : Relational operator\n");
state =0;
}
break;
case 4:
{
++i;
if(ch[i] == '=')
printf("<= : Relational operator\n");
else
printf("< : Relational operator\n");
state = 0;
}
break;
case 7:
{
++i;
if(ch[i] == '=')
printf("!= : Relational operator\n");
else
state = 1238;
state =0;
}
break;
case 9:
{
++i;
if(ch[i] == '=')
printf("== : Relational operator EQ");
else
printf("= : Assignment\n");
state = 0;
}
break;
case 11:
{
j=0;
++i;
++j;
while(ch[i]!='\0')
{
if(ch[i]>='0'&&ch[i]<='9')
{
word2[j] = ch[i];
++j; 
++i;
}      
else
break;
}
if(ch[i]=='.')
{
word2[j]='.';
++j;
++i;
while(ch[i]!='\0')
{
if(ch[i]>='0'&&ch[i]<='9')
{
	word2[j] = ch[i];
	++j; 
	++i;
}   
else
	break;
}
}
word2[j]='\0';
printf("%s : number\n",word2);
state = 0;
}
break;
case 15:
{
++i;
++j;
while(ch[i]!='\0')
{
if(ch[i]>='A'&&ch[i]<='Z'||ch[i]>='a'&&ch[i]<='z'||ch[i]>='0'&&ch[i]<='9')
{
word[j] = ch[i];
++j; 
++i;
}
else
break;
}
word[j]='\0';
ikw = isKW(word);
if(ikw == 1)
printf("%s : keyword\n",word);
else
printf("%s : identifier\n",word);
state = 0;
}
break;
case 19:
{
i++;
state = 0;
}
break;
default:
printf("Error\n");
}
}while(i!=len);
}
