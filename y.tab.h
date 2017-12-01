/* A Bison parser, made by GNU Bison 2.7.  */

/* Bison interface for Yacc-like parsers in C
   
      Copyright (C) 1984, 1989-1990, 2000-2012 Free Software Foundation, Inc.
   
   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.
   
   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.
   
   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.
   
   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

#ifndef YY_YY_Y_TAB_H_INCLUDED
# define YY_YY_Y_TAB_H_INCLUDED
/* Enabling traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     Ident = 1,
     IntConst = 2,
     If = 11,
     Then = 12,
     End = 13,
     While = 14,
     Do = 15,
     Else = 16,
     Assign = 21,
     LParen = 22,
     RParen = 23,
     Plus = 24,
     Minus = 25,
     Star = 26,
     Slash = 27,
     Eq = 28,
     Ne = 29,
     Lt = 30,
     Le = 31,
     Gt = 32,
     Ge = 33,
     Eoln = 34,
     UPlus = 35,
     UMinus = 36,
     NoType = 41,
     Integer = 42,
     Boolean = 43,
     Prog = 44,
     Comma = 45
   };
#endif
/* Tokens.  */
#define Ident 1
#define IntConst 2
#define If 11
#define Then 12
#define End 13
#define While 14
#define Do 15
#define Else 16
#define Assign 21
#define LParen 22
#define RParen 23
#define Plus 24
#define Minus 25
#define Star 26
#define Slash 27
#define Eq 28
#define Ne 29
#define Lt 30
#define Le 31
#define Gt 32
#define Ge 33
#define Eoln 34
#define UPlus 35
#define UMinus 36
#define NoType 41
#define Integer 42
#define Boolean 43
#define Prog 44
#define Comma 45



#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
{
/* Line 2058 of yacc.c  */
#line 18 "zb.y"
 tree p; int i; 

/* Line 2058 of yacc.c  */
#line 122 "y.tab.h"
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif

extern YYSTYPE yylval;

#ifdef YYPARSE_PARAM
#if defined __STDC__ || defined __cplusplus
int yyparse (void *YYPARSE_PARAM);
#else
int yyparse ();
#endif
#else /* ! YYPARSE_PARAM */
#if defined __STDC__ || defined __cplusplus
int yyparse (void);
#else
int yyparse ();
#endif
#endif /* ! YYPARSE_PARAM */

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */
