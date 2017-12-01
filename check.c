#include <stdio.h>
#include "tree.h"
#include "y.tab.h"
#include "ST.h"

extern int top;
STentry ST[100] = {0, NoType}; 

void prST (void)
{
	int i;
	printf ("SYMBOL TABLE\n");
	for (i = 0; i <= top; i++) {
		int	t = ST[i].type;
		printf ("%3d %-10s\t%s\n", i, id_name (i), 
				t == Integer ? "Integer" : t == Boolean ? "Boolean" : "<none>");
		}
}

static int check_expr (tree t)
{
	if (t == NULL) { 
		fprintf (stderr, "You shouldn't be here; missing expression\n"); 
		return NoType; 
		}
	switch (t->kind) {
		case Eq : case Ne :
		case Lt : case Le :
		case Gt : case Ge : {
			int t1 = check_expr (t->first), t2 = check_expr (t->second);
			if (t1 != t2) {
				fprintf (stderr, "Type mismatch in comparison\n");
				return (t->value = NoType);
				}
			else 
				return (t->value = Boolean);
			}
			break;

		case Plus : case Minus :
		case Star : case Slash : {
			int t1 = check_expr (t->first), t2 = check_expr (t->second);
			if (t1 != Integer || t2 != Integer) {
				fprintf (stderr, "Type mismatch in binary arithmetic expression\n");
				return (t->value = NoType);
				}
			else 
				return (t->value = Integer);
			}
			break;

		case Ident : {
			int pos = t->value;
			if (ST[pos].index == 0) {
				ST[pos].index = pos;
				ST[pos].type = Integer;
				}
			return ST[pos].type;
			break;
			}
		case IntConst :
			return Integer;		/* t->value contains other info */

		default:
			fprintf (stderr, "You shouldn't be here; invalid expression operator\n");
	}
}

static void handle_decls (tree t)
{
	for (t; t!= NULL; t = t->next) {
		int	type = t->kind;
		tree	p;
		if (type != Integer && type != Boolean) {
			fprintf (stderr, "Bad type in decl\n"); return;
			}
		for (p = t->first; p != NULL; p = p->next) {
			int	pos = p->value;
			ST[pos].index = pos;
			ST[pos].type = type;
			}
		}
}

void check (tree t)
{
	for (t; t != NULL; t = t->next) 
		switch (t->kind) {
			case Prog:
				handle_decls (t->first);
				check (t->second);
				printf ("\n");
				prST ();
				break;
			case Assign :{
				int pos = t->first->value;
				if (ST[pos].index == 0) {
					ST[pos].index = pos;
					ST[pos].type = Integer;
					}
				if (check_expr (t->second) != ST[pos].type) 
					fprintf (stderr, "Type error in assignment to identifier %s\n", 
								id_name(t->first->value));
				break;
				}
			case If :
				if (check_expr (t->first) != Boolean)
					fprintf (stderr, "Non-boolean in condition to IF\n");
				check (t->second);
				check (t->third);
				break;

			case While :
				if (check_expr (t->first) != Boolean)
					fprintf (stderr, "Non-boolean in condition to WHILE\n");
				check (t->second);
				break;

			default :
				fprintf (stderr, "You shouldn't be here; invalid statement\n");
			}
}
