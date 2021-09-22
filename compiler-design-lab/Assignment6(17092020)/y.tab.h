/* A Bison parser, made by GNU Bison 3.5.1.  */

/* Bison interface for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2020 Free Software Foundation,
   Inc.

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

/* Undocumented macros, especially those whose name start with YY_,
   are private implementation details.  Do not rely on them.  */

#ifndef YY_YY_Y_TAB_H_INCLUDED
# define YY_YY_Y_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    article_blk = 258,
    book_blk = 259,
    inproceeding_blk = 260,
    article = 261,
    title = 262,
    journal = 263,
    year = 264,
    page = 265,
    volume = 266,
    publisher = 267,
    editor = 268,
    series = 269,
    full = 270,
    minimal = 271,
    crossref = 272,
    NL = 273,
    TAB = 274,
    OPEN = 275,
    CLOSE = 276,
    EQ = 277,
    COMMA = 278,
    HYPHEN = 279,
    NUMBER = 280,
    author = 281,
    ALPHANUM = 282,
    book = 283,
    inproceedings = 284
  };
#endif
/* Tokens.  */
#define article_blk 258
#define book_blk 259
#define inproceeding_blk 260
#define article 261
#define title 262
#define journal 263
#define year 264
#define page 265
#define volume 266
#define publisher 267
#define editor 268
#define series 269
#define full 270
#define minimal 271
#define crossref 272
#define NL 273
#define TAB 274
#define OPEN 275
#define CLOSE 276
#define EQ 277
#define COMMA 278
#define HYPHEN 279
#define NUMBER 280
#define author 281
#define ALPHANUM 282
#define book 283
#define inproceedings 284

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 9 "bibtex_to_xml_converter.y"

    int number;
    char* string;

#line 120 "y.tab.h"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */
