/* A Bison parser, made by GNU Bison 2.3.  */

/* Skeleton interface for Bison's Yacc-like parsers in C

   Copyright (C) 1984, 1989, 1990, 2000, 2001, 2002, 2003, 2004, 2005, 2006
   Free Software Foundation, Inc.

   This program is free software; you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation; either version 2, or (at your option)
   any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program; if not, write to the Free Software
   Foundation, Inc., 51 Franklin Street, Fifth Floor,
   Boston, MA 02110-1301, USA.  */

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

/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     N = 258,
     Z = 259,
     SEP = 260,
     COMMENT = 261,
     AVM_POP = 262,
     AVM_PUSH = 263,
     AVM_DUMP = 264,
     AVM_ASSERT = 265,
     AVM_ADD = 266,
     AVM_SUB = 267,
     AVM_MUL = 268,
     AVM_DIV = 269,
     AVM_MOD = 270,
     AVM_PRINT = 271,
     AVM_EXIT = 272,
     AVM_INT8_TYPE = 273,
     AVM_INT16_TYPE = 274,
     AVM_INT32_TYPE = 275,
     AVM_FLOAT_TYPE = 276,
     AVM_DOUBLE_TYPE = 277,
     AVM_OPEN_BR = 278,
     AVM_CLOSE_BR = 279
   };
#endif
/* Tokens.  */
#define N 258
#define Z 259
#define SEP 260
#define COMMENT 261
#define AVM_POP 262
#define AVM_PUSH 263
#define AVM_DUMP 264
#define AVM_ASSERT 265
#define AVM_ADD 266
#define AVM_SUB 267
#define AVM_MUL 268
#define AVM_DIV 269
#define AVM_MOD 270
#define AVM_PRINT 271
#define AVM_EXIT 272
#define AVM_INT8_TYPE 273
#define AVM_INT16_TYPE 274
#define AVM_INT32_TYPE 275
#define AVM_FLOAT_TYPE 276
#define AVM_DOUBLE_TYPE 277
#define AVM_OPEN_BR 278
#define AVM_CLOSE_BR 279




#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
#line 41 "AVMGrammar.y"
{
	char *string;
	struct yaccValue *val;
	struct yaccInstruction *inst;
}
/* Line 1529 of yacc.c.  */
#line 103 "AVMParser.yy.hpp"
	YYSTYPE;
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif

extern YYSTYPE yylval;

