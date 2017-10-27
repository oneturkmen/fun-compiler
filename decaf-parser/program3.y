/**
  Program 3, program3.y
  Purpose: syntax analyzer (parser) file

  @author Batyr Nuryyev
  @date   10/27/2017
*/



%{

#include <iostream>
#include <vector>
#include <typeinfo>
#include <FlexLexer.h>
#include "program3.hpp"

using namespace std;

/*
 * These are declared in "main" so that we can pass values between
 * the two portions of the program.
 */

extern Node *tree;
extern yyFlexLexer scanner;
extern int yylineno;

/*
 * Need to do this define, an "acceptable" hack to interface
 * the C++ scanner with the C parser.
 */

#define yylex() scanner.yylex()

// need the function prototype for the parser.

void yyerror(const char *, int, int);
void yyerror(const char *);

%}

/*
 * Bison Declarations
 *
 */

%locations

%code {
  #define YYLTYPE YYLTYPE
}

%union {
  Node *ttype;
}

%token NLL THIS VOID NEW READ PRINT
%token LC LS LP RC RP RS
%token CLASS IF ELSE WHILE RETURN DOT SEMICOLON
%token INT
%token <ttype> ID NUMBER
%type <ttype> simple_type
%type <ttype> type
%type <ttype> name
%type <ttype> var_decl
%type <ttype> assignment element
%type <ttype> empty_exp_in_brackets
%type <ttype> exprsn_in_brackets
%type <ttype> new_expression
%type <ttype> expression

%left EQUALS NOTEQL LESSGRT MOREGRT GREATER LESS
%left PLUS MINUS OROR    /* shift-reduce errors are solved by this */
%left MULT DIV REMAINDER ANDAND    /* shift-reduce errors are solved by this */

%precedence <string> NOT     /* exponentiation */

%%

start:
  %empty
  | assignment {
                 tree = $1;
               }
  ;


/* FIXME: How to properly start and initialize a tree? */
assignment:
  assignment element
  | element {
              $$ = new Node;
              $$->setLeft($1);
            }
  ;

element:
  var_decl {
             $$ = new Node;
             $$->setLeft($1);
           }
  | expression {
                 $$ = new Node;
                 $$->setLeft($1);
               }
  ;

name:
  THIS {
         $$ = new Node;
         $$->setValKeyw("this");
         $$->setValProd("<Name> --> this");
       }
  | ID {
         $$ = new Node;
         $$->setValProd("<Name> --> identifier");
       }
  | name DOT ID {
                  $$ = new Node;
                  $$->setLeft($1);
                  $$->setValId($3->getValId());
                  $$->setValProd("<Name> --> <Name> . identifier");
                }
  | name LS expression RS {
                            $$ = new Node;
                            $$->setLeft($1);
                            $$->setRight($3);
                            $$->setValProd("<Name> --> <Name> [ <Expression> ]");
                          }
  ;

expression:
  name {
         $$ = new Node;
         $$->setLeft($1);
         $$->setValProd("<Expression> --> <Name>");
       }
  | NUMBER {
             $$ = new Node;
             //$$->setValNum($1->getValNum());
             $$->setValProd("<Expression> --> number");
           }
  | NLL {
          $$ = new Node;
          $$->setValProd("<Expression> --> null");
        }
  | READ LP RP {
                 $$ = new Node;
                 $$->setValProd("<Expression> --> read ( )");
               }
  | new_expression {
                     $$ = new Node;
                     $$->setLeft($1);
                     $$->setValProd("<Expression> --> <NewExpression>");
                   }
  | PLUS expression {
                      $$ = new Node;
                      $$->setRight($2);
                      $$->setValProd("<Expression> --> + <Expression>");
                    }
  | MINUS expression {
                       $$ = new Node;
                       $$->setRight($2);
                       $$->setValProd("<Expression> --> - <Expression>");
                     }
  | NOT expression {
                     $$ = new Node;
                     $$->setRight($2);
                     $$->setValProd("<Expression> --> ! <Expression>");
                   }
  | expression EQUALS expression {
                                   $$ = new Node;
                                   $$->setValProd("<Expression> --> <Expression> == <Expression>");
                                 }
  | expression NOTEQL expression {
                                   $$ = new Node;
                                   $$->setValProd("<Expression> --> <Expression> != <Expression>");
                                 }
  | expression LESSGRT expression {
                                    $$ = new Node;
                                    $$->setValProd("<Expression> --> <Expression> <= <Expression>");
                                  }
  | expression MOREGRT expression {
                                    $$ = new Node;
                                    $$->setValProd("<Expression> --> <Expression> >= <Expression>");
                                  }
  | expression GREATER expression {
                                    $$ = new Node;
                                    $$->setValProd("<Expression> --> <Expression> > <Expression>");
                                  }
  | expression LESS expression {
                                 $$ = new Node;
                                 $$->setValProd("<Expression> --> <Expression> < <Expression>");
                               }
  | expression PLUS expression {
                                 $$ = new Node;
                                 $$->setLeft($1);
                                 $$->setRight($3);
                                 $$->setValProd("<Expression> --> <Expression> + <Expression>");
                               }
  | expression MINUS expression {
                                  $$ = new Node;
                                  $$->setLeft($1);
                                  $$->setRight($3);
                                  $$->setValProd("<Expression> --> <Expression> - <Expression>");
                               }
  | expression OROR expression {
                                 $$ = new Node;
                                 $$->setLeft($1);
                                 $$->setRight($3);
                                 $$->setValProd("<Expression> --> <Expression> || <Expression>");
                               }
  | expression MULT expression {
                                 $$ = new Node;
                                 $$->setLeft($1);
                                 $$->setRight($3);
                                 $$->setValProd("<Expression> --> <Expression> * <Expression>");
                               }
  | expression DIV expression {
                                $$ = new Node;
                                $$->setLeft($1);
                                $$->setRight($3);
                                $$->setValProd("<Expression> --> <Expression> / <Expression>");
                              }
  | expression REMAINDER expression  {
                                       $$ = new Node;
                                       $$->setLeft($1);
                                       $$->setRight($3);
                                       $$->setValProd("<Expression> --> <Expression> % <Expression>");
                                     }
  | expression ANDAND expression {
                                   $$ = new Node;
                                   $$->setLeft($1);
                                   $$->setRight($3);
                                   $$->setValProd("<Expression> --> <Expression> && <Expression>");
                                 }
  | LP expression RP {
                       $$ = new Node;
                       $$->setLeft($2);
                       $$->setValProd("<Expression> --> ( <Expression> )");
                     }
  ;

new_expression:
  NEW ID LP RP {
                 $$ = new Node;
                 $$->setValProd("<NewExpression> --> new identifier ( )");
                 $$->setValId($2->getValId());
                 $$->setValKeyw("new");
               }
  | NEW ID exprsn_in_brackets empty_exp_in_brackets {
                            $$ = new Node;
                            $$->setLeft($3);
                            $$->setRight($4);
                            $$->setValId($2->getValId());
                            $$->setValKeyw("new");
                            $$->setValProd("<NewExpression> --> new identifier <[ Expression ]>* <[ ]>*");
                          }
  ;

exprsn_in_brackets:
  %empty { $$ = new Node; }
  | exprsn_in_brackets LS expression RS {
                                          $$ = $1;
                                          $$->pushNonTerminal($3);
                                        }
  ;

empty_exp_in_brackets:
  %empty { $$ = new Node; }
  | LS RS empty_exp_in_brackets {
                                  $$ = new Node;
                                  $$->setValProd("<NewExpression> --> <[ ]>");
                                  $$->pushNonTerminal($3);
                                }
  ;

var_decl:
  type ID SEMICOLON {
                      $$ = new Node;
                      $$->setLeft($1);
                      $$->setValProd("<VarDec> --> <Type> identifier ;");
                    }
  | type ID error {
                    yyerrok;
                    yyerror("Invalid character! Expected semicolon ...",
                            @3.first_line,
                            @3.first_column);
                    yyclearin;
                  }
  | type error SEMICOLON {
                           yyerrok;
                           yyerror("parse error on identifier",
                                    @2.first_line,
                                    @2.first_column);
                           yyclearin;
                         }
  ;

type:
  simple_type {
                $$ = new Node;
                $$->setLeft($1);
                $$->setValProd("<Type> --> <SimpleType>");
              }
  | type LS RS {
                 $$ = new Node;
                 $$->setValProd("<Type> --> <Type> [ ]");
               }
  | error LS RS {
                  yyerrok;
                  yyerror("Parse error on type", @1.first_line, @1.first_column);
                  yyclearin;
                }
  | type error RS {
                    yyerrok;
                    yyerror("Missing [ character", @1.first_line, @1.first_column);
                    yyclearin;
                  }
  | type LS error {
                    yyerrok;
                    yyerror("Missing ] character");
                    yyclearin;
                  }
  ;

simple_type:
  INT {
        $$ = new Node;
        $$->setValKeyw("int");
      }
  | error {
            yyerrok;
            yyerror("Invalid simple type!");
            yyclearin;
          }
  ;

%%
