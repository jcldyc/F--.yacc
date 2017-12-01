#include <stdio.h>
#include "tree.h"

static char TokName[][12] = 
	{"<eof>", 
	"Ident", "IntConst", "", "", "", "", "", "", "", "",
	"IF", "THEN", "END", "WHILE", "DO", "ELSE", "", "", "", "",
	"=", "(", ")", "+", "-", "*", "/", ".EQ.", ".NE.", ".LT.",
	".LE.", ".GT.", ".GE.", "+", "-", "<eoln>", "<NoType>", "<IntType>", "<BoolType>"};
static int indent = 0;
void printTree (tree p)
{
	if (p == NULL) return;
	for (; p != NULL; p = p->next) {
		printf ("%*s%s", indent, "", TokName[p->kind]);
		switch (p->kind) {
			case Ident: 
				printf ("  %s (%d)\n", id_name (p->value), p->value);
				break;
			case IntConst:
				printf ("  %d\n", p->value);
				break;
			default:
				printf ("\n");
				indent += 2;
				printTree (p->first);
				printTree (p->second);
				printTree (p->third);
				indent -= 2;
			}
		}
}
