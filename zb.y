%{
#include "tree.h"
#include <stdlib.h>

extern tree root;
%}

%token <i>	Ident 1 IntConst 2
%token	If 11 Then 12 End 13 While 14 Do 15 Else 16
%token	Assign 21 LParen 22 RParen 23 
%token	Plus 24 Minus 25 Star 26 Slash 27
%token	Eq  28 Ne 29 Lt 30 Le 31 Gt 32 Ge 33 
%token	Eoln 34 UPlus 35 UMinus 36 
%token	NoType 41 Integer 42 Boolean 43 Prog 44 Comma 45

%start	program

%union { tree p; int i; }

%type <p>	optdecl idlist stmtseq stmt expr sum term signed factor

%%
program
	: optdecl stmtseq
		{ root = buildTree (Prog, $1, $2, NULL); }
	;
optdecl 
	: /* empty */
		{ $$ = NULL; }
	| Integer idlist Eoln optdecl
		{ $$ = buildTree (Integer, $2, NULL, NULL); $$->next = $4; }
	| Boolean idlist Eoln optdecl
		{ $$ = buildTree (Boolean, $2, NULL, NULL); $$->next = $4; }
	;
idlist
	: Ident
		{ $$ = buildIntTree (Ident, $1); }
	| Ident Comma idlist
		{ $$ = buildIntTree (Ident, $1); $$->next = $3; }
	;
stmtseq
	: stmt 
		{ $$ = $1; }
	| stmt stmtseq 
		{ $1->next = $2; $$ = $1; }
	;
stmt
	: Ident Assign expr eoln
		{ $$ = buildTree (Assign, buildIntTree (Ident, $1), $3, NULL); }
	| While expr Do eoln stmtseq End eoln
		{ $$ = buildTree (While, $2, $5, NULL); }
	| If expr Then eoln stmtseq End eoln
		{ $$ = buildTree (If, $2, $5, NULL); }
	| If expr Then eoln stmtseq Else eoln stmtseq End eoln
		{ $$ = buildTree (If, $2, $5, $8); }
	;
expr
	: sum Eq sum
		{ $$ = buildTree (Eq, $1, $3, NULL); }
	| sum Ne sum
		{ $$ = buildTree (Ne, $1, $3, NULL); }
	| sum Lt sum
		{ $$ = buildTree (Lt, $1, $3, NULL); }
	| sum Le sum
		{ $$ = buildTree (Le, $1, $3, NULL); }
	| sum Gt sum
		{ $$ = buildTree (Gt, $1, $3, NULL); }
	| sum Ge sum
		{ $$ = buildTree (Ge, $1, $3, NULL); }
	| sum
		{ $$ = $1; }
	;
sum
	: sum Plus term
		{ $$ = buildTree (Plus, $1, $3, NULL); }
	| sum Minus term
		{ $$ = buildTree (Minus, $1, $3, NULL); }
	| term
		{ $$ = $1; }
	;
term
	: term Star signed
		{ $$ = buildTree (Star, $1, $3, NULL); }
	| term Slash signed
		{ $$ = buildTree (Slash, $1, $3, NULL); }
	| signed
		{ $$ = $1; }
	;
signed
	: Plus factor
		{ $$ = buildTree (UPlus, $2, NULL, NULL); }
	| Minus factor
		{ $$ = buildTree (UMinus, $2, NULL, NULL); }
	| factor
		{ $$ = $1; }
	;
factor
	: LParen expr RParen
		{ $$ = $2; }
	| Ident
	 	{ $$ = buildIntTree (Ident, $1); }
	| IntConst
		{ $$ = buildIntTree(IntConst, $1); }
	;
eoln
	: Eoln
	| Eoln eoln
	;
%%

