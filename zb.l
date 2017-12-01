%{
#include <stdio.h>
#include "tree.h"
#include "y.tab.h"

int line_no = 1, pos = 1;
%}
L	[A-Za-z]
D	[0-9]
%%
^".C".*		/* comment */ ;
[ \t]+		pos += yyleng;
IF		{pos += 2; return If;}
THEN		{pos += 4; return Then;}
END		{pos += 3; return End;}
WHILE		{pos += 5; return While;}
DO		{pos += 2; return Do;}
BOOLEAN	{ pos += 7; return Boolean; }
INTEGER	{ pos += 7; return Integer; }
{L}({L}|{D})*	{pos += yyleng; yylval.i = lookup (yytext); return Ident;}
{D}+		{pos += yyleng; yylval.i = atoi (yytext); return IntConst;}
"="		{pos += 1; return Assign;}
".EQ."		{pos += 4; return Eq;}
".NE."		{pos += 4; return Ne;}
".LT."		{pos += 4; return Lt;}
".LE."		{pos += 4; return Le;}
".GT."		{pos += 4; return Gt;}
".GE."		{pos += 4; return Ge;}
"+"		{pos += 1; return Plus;}
"-"		{pos += 1; return Minus;}
"*"		{pos += 1; return Star;}
"/"		{pos += 1; return Slash;}
"("		{pos += 1; return LParen;}
")"		{pos += 1; return RParen;}
","		{pos += 1; return Comma;}
"\n"		{line_no ++; pos = 1; return Eoln;}
.		{pos += 1; yyerror ("Bad Character");}
%%
int yywrap (void) { return 1; }
int yyerror (char s[])
{
	printf ("Error: %s at line %d, position %d, token %s\n", s, line_no, pos, yytext);
}

typedef char name[15];
static char Names[200][15] = {"<no name>"};
int top = 0;

int lookup (char s[])
{
	int	i;

	for (i = 1; i <= top; i ++)
		if (strcmp (s, Names[i]) == 0) return i;
	strcpy (Names[++top], s);
	return top;
}

void printNames (void)
{
	int i = 0;

	for (; i <= top; i++)
		printf ("%d\t%s\n", i, Names[i]);
}

char *id_name (int i)
{
	return Names[i];
}
