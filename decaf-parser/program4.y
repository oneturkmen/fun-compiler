/**
  Program 4, program4.y
  Purpose: syntax analyzer (parser) file

  @author Batyr Nuryyev
  @date   11/01/2017
*/



%{

#include <iostream>
#include <vector>
#include <typeinfo>
#include <FlexLexer.h>
#include "program4.hpp"

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
%error-verbose

%start start

%code {
  #define YYLTYPE YYLTYPE
}

%union {
  Node *ttype;
}

%token <ttype> ID NUMBER
%token NLL THIS VOID NEW READ PRINT
%token CLASS IF WHILE RETURN
%token INT
%token LP LC COMMA SEMICOLON RC RS RP
%token DOT LS
%token ASSIGN

%type <ttype> program

%type <ttype> class_decl
%type <ttype> class_body

%type <ttype> exprsn_in_brackets
%type <ttype> new_expression
%type <ttype> expression
%type <ttype> optional_expression

%type <ttype> name_other
%type <ttype> name

%type <ttype> constructor_decl method_decl var_decl local_var_decl
%type <ttype> constructor_declmore method_declmore var_declmore local_var_declmore

%type <ttype> multi_brackets

%type <ttype> mult_parameters
%type <ttype> parameter_list
%type <ttype> parameter
%type <ttype> block

%type <ttype> statements
%type <ttype> statement
%type <ttype> conditional_statement

%type <ttype> type_other
%type <ttype> type

%type <ttype> arg_lists
%type <ttype> arg_list

%nonassoc OROR ANDAND    /* shift-reduce errors are solved by this */

%nonassoc EQUALS NOTEQL
%nonassoc GREATER LESS LESSGRT MOREGRT

%left PLUS MINUS    /* shift-reduce errors are solved by this */
%left MULT DIV REMAINDER

%right "then" ELSE
%precedence NOT     /* exponentiation */


%%

start:
  %empty
  | program {
              tree = $1;
            }
  ;

program:
  class_decl {
               $$ = new Node;
               $$->pushNonTerminal($1);
               $$->setStructureType("class_decl");
               $$->setValProd("<Program> --> <ClassDeclaration>+");
             }
  | program class_decl {
                         $$ = $1;
                         $$->pushNonTerminal($2);
                       }

class_decl:
  CLASS ID LC class_body RC {
    $$ = new Node;
    $$->pushNonTerminal($4);
    $$->setValId($2->getValId());
    $$->setValProd("\n<ClassDeclaration> --> class identifier <ClassBody>");
  }
  | error ID LC class_body RC {
    yyerrok;
    yyerror("Parse error on class", @1.first_line, @1.first_column);
    yyclearin;
  }
  | CLASS error LC class_body RC {
    yyerrok;
    yyerror("Parse error on identifier", @2.first_line, @2.first_column);
    yyclearin;
  }
  | CLASS ID error class_body RC {
    yyerrok;
    yyerror("Parse error on [", @3.first_line, @3.first_column);
    yyclearin;
  }
  | CLASS ID LC class_body error {
    yyerrok;
    yyerror("Parse error on ]", @5.first_line, @5.first_column);
    yyclearin;
  }
  ;


/* FIXME: Gotta add more grammar here */
class_body: var_declmore constructor_declmore method_declmore {
    $$ = new Node;
    $$->pushNonTerminal($1);
    $$->pushNonTerminal($2);
    $$->pushNonTerminal($3);
    $$->setValProd("<ClassBody> --> { <VarDeclaration>+ <ConstructorDeclaration>+ <MethodDeclaration>+ }");
  }
  | var_declmore constructor_declmore {
    $$ = new Node;
    $$->pushNonTerminal($1);
    $$->pushNonTerminal($2);
    $$->setValProd("<ClassBody> --> { <VarDeclaration>+ <ConstructorDeclaration>+ }");
  }
  | var_declmore method_declmore {
    $$ = new Node;
    $$->pushNonTerminal($1);
    $$->pushNonTerminal($2);
    $$->setValProd("<ClassBody> --> { <VarDeclaration>+ <MethodDeclaration>+ }");
  }
  | constructor_declmore method_declmore {
    $$ = new Node;
    $$->pushNonTerminal($1);
    $$->pushNonTerminal($2);
    $$->setValProd("<ClassBody> --> { <ConstructorDeclaration>+ <MethodDeclaration>+ }");
  }
  | method_declmore {
    $$ = new Node;
    $$->pushNonTerminal($1);
    $$->setValProd("<ClassBody> --> { <MethodDeclaration>+ }");
  }
  | var_declmore {
    $$ = new Node;
    $$->pushNonTerminal($1);
    $$->setValProd("<ClassBody> --> { <VarDeclaration>+ }");
  }
  | constructor_declmore {
    $$ = new Node;
    $$->pushNonTerminal($1);
    $$->setValProd("<ClassBody> --> { <ConstructorDeclaration>+ }");
  }
  | %empty { $$ = new Node; }
  ;


var_declmore:
  var_declmore var_decl {
    $$ = $1;
    $$->pushNonTerminal($2);
  }
  | var_decl { $$ = new Node; $$->pushNonTerminal($1); }
  ;


multi_brackets:
  LS RS { $$ = new Node; $$->setValProd("<[]>* --> []"); }
  | multi_brackets LS RS {
    $$ = new Node;
    $$->pushNonTerminal($1);
    $$->setValProd("<[]>* --> []");
  }
  ;


var_decl: ID ID SEMICOLON {
    $$ = new Node;
    $$->setValId($2->getValId());
    $$->setValProd("<VarDeclaration> --> identifier identifier ;");
  }
  | INT ID SEMICOLON {
    $$ = new Node;
    $$->setValProd("<VarDeclaration> --> int identifier ;");
  }
  | ID multi_brackets ID SEMICOLON {
    $$ = new Node;
    $$->setValProd("<VarDeclaration> --> identifier <[]>* identifier ;");
    $$->pushNonTerminal($2);
  }
  | INT multi_brackets ID SEMICOLON {
    $$->pushNonTerminal($2);
    $$->setValProd("<VarDeclaration> --> int <[]>* identifier ;");
  }
  ;


type_other:
  INT {
    $$ = new Node;
    $$->setValProd("<Type> --> int");
  }
  | ID LS RS {
    $$ = new Node;
    $$->setValProd("<Type> --> identifier []");
  }
  | type_other LS RS {
    $$ = new Node;
    $$->pushNonTerminal($1);
    $$->setValProd("<Type> --> <Type> [ ]");
  }
  ;


type:
  ID {
    $$ = new Node;
    $$->setValProd("<Type> --> identifier");
  }
  | type_other {
    $$ = new Node;
    $$->pushNonTerminal($1);
  }
  ;


constructor_declmore:
  constructor_declmore constructor_decl {
    $$ = $1;
    $$->pushNonTerminal($2);
  }
  | constructor_decl {
    $$ = new Node;
    $$->pushNonTerminal($1);
  }
  ;


constructor_decl: ID LP parameter_list RP block {
    $$ = new Node;
    $$->setValProd("<ConstructorDeclaration> --> identifier ( <ParameterList> ) <Block>");
    $$->pushNonTerminal($1);
    $$->pushNonTerminal($3);
    $$->pushNonTerminal($5);
  }
  ;


method_declmore:
  method_declmore method_decl {
    $$ = $1;
    $$->pushNonTerminal($2);
  }
  | method_decl { $$ = new Node; $$->pushNonTerminal($1); }
  ;


method_decl:
  INT ID LP parameter_list RP block {
    $$ = new Node;
    $$->setValProd("<MethodDeclaration> --> int identifier ( <ParameterList> ) <Block>");
    $$->pushNonTerminal($4);
    $$->pushNonTerminal($6);
  }
  | ID ID LP parameter_list RP block {
    $$ = new Node;
    $$->setValProd("<MethodDeclaration> --> identifier identifier ( <ParameterList> ) <Block>");
    $$->pushNonTerminal($4);
    $$->pushNonTerminal($6);
  }
  | VOID ID LP parameter_list RP block {
    $$ = new Node;
    $$->setValProd("<MethodDeclaration> --> void identifier ( <ParameterList> ) <Block>");
    $$->pushNonTerminal($4);
    $$->pushNonTerminal($6);
  }
  | INT multi_brackets ID LP parameter_list RP block {
    $$ = new Node;
    $$->setValProd("<MethodDeclaration> --> int <[]>* identifier ( <ParameterList> ) <Block>");
    $$->pushNonTerminal($2);
    $$->pushNonTerminal($5);
    $$->pushNonTerminal($7);
  }
  | ID multi_brackets ID LP parameter_list RP block {
    $$ = new Node;
    $$->setValProd("<MethodDeclaration> --> identifier <[]>* identifier ( <ParameterList> ) <Block>");
    $$->pushNonTerminal($2);
    $$->pushNonTerminal($5);
    $$->pushNonTerminal($7);
  }
  ;


parameter_list:
  %empty  { $$ = new Node; }
  | parameter mult_parameters {
    $$ = new Node;
    $$->setValProd("<ParameterList> --> <Parameter> <, <Parameter> >*");
    $$->pushNonTerminal($1);
    $$->pushNonTerminal($2);
  }
  ;


mult_parameters:
  %empty { $$ = new Node; }
  | mult_parameters COMMA parameter {
    $$ = $1;
    $$->pushNonTerminal($3);
  }
  ;


parameter:
  ID ID {
    $$ = new Node;
    $$->setValProd("<Parameter> --> identifier identifier");
    $$->pushNonTerminal($1);
  }
  | INT ID {
    $$ = new Node;
    $$->setValProd("<Parameter> --> int identifier");
  }
  | ID multi_brackets ID {
    $$ = new Node;
    $$->setValProd("<Parameter> --> identifier <[]>* identifier");
    $$->pushNonTerminal($2);
  }
  | INT multi_brackets ID {
    $$ = new Node;
    $$->setValProd("<Parameter> --> int <[]>* identifier");
    $$->pushNonTerminal($2);
  }
  ;


block:
  LC local_var_declmore statements RC {
    $$ = new Node;
    $$->setValProd("<Block> --> { <LocalVarDeclaration>* <Statement>* }");
    $$->pushNonTerminal($2);
    $$->pushNonTerminal($3);
  }
  | LC local_var_declmore RC {
    $$ = new Node;
    $$->setValProd("<Block> --> { <LocalVarDeclaration>* <Statement>* }");
    $$->pushNonTerminal($2);
  }
  | LC statements RC {
    $$ = new Node;
    $$->setValProd("<Block> --> { <LocalVarDeclaration>* <Statement>* }");
    $$->pushNonTerminal($2);
  }
  | LC RC {
    $$ = new Node;
    $$->setValProd("<Block> --> { <LocalVarDeclaration>* <Statement>* }");
  }
  ;


local_var_declmore:
  local_var_decl { $$ = new Node; $$->pushNonTerminal($1); }
  | local_var_declmore local_var_decl {
    $$ = $1;
    $$->pushNonTerminal($2);
  }
  ;


local_var_decl:
  type ID SEMICOLON {
    $$ = new Node;
    $$->pushNonTerminal($1);
    $$->setValProd("<LocalVarDeclaration> --> <Type> identifier ;");
  }
  ;


statements:
  statement {
    $$ = new Node;
    $$->pushNonTerminal($1);
  }
  | statements statement {
    $$ = $1;
    $$->pushNonTerminal($2);
  }
  ;


statement:
  SEMICOLON {
    $$ = new Node;
    $$->setValProd("<Statement> --> ;");
  }
  | name ASSIGN expression SEMICOLON {
    $$ = new Node;
    $$->setValProd("<Statement> --> <Name> = <Expression> ;");
    $$->pushNonTerminal($1);
    $$->pushNonTerminal($3);
  }
  | name LP arg_list RP SEMICOLON {
    $$ = new Node;
    $$->setValProd("<Statement> --> <Name> ( <ArgList> ) ;");
    $$->pushNonTerminal($1);
    $$->pushNonTerminal($3);
  }
  | conditional_statement {
    $$ = new Node;
    $$->setValProd("<Statement> --> <ConditionalStatement>");
    $$->pushNonTerminal($1);
  }
  | PRINT LP arg_list RP SEMICOLON {
    $$ = new Node;
    $$->setValProd("<Statement> --> print ( <ArgList> ) ;");
    $$->pushNonTerminal($3);
  }
  | WHILE LP expression RP statement {
    $$ = new Node;
    $$->setValProd("<Statement> --> while ( <Expression> ) <Statement>");
    $$->pushNonTerminal($3);
    $$->pushNonTerminal($5);
  }
  | RETURN optional_expression SEMICOLON {
    $$ = new Node;
    $$->setValProd("<Statement> --> return <OptionalExpression> ;");
    $$->pushNonTerminal($2);
  }
  | block {
    $$ = new Node;
    $$->setValProd("<Statement> --> <Block>");
    $$->pushNonTerminal($1);
  }
  ;


conditional_statement:
  IF LP expression RP statement %prec "then" {
    $$ = new Node;
    $$->setValProd("<ConditionalStatement> --> if ( <Expression> ) <Statement>");
    $$->pushNonTerminal($3);
    $$->pushNonTerminal($5);
  }
  | IF LP expression RP statement ELSE statement {
    $$ = new Node;
    $$->setValProd("<ConditionalStatement> --> if ( <Expression> ) <Statement> else <Statement>");
  }
  ;


name_other:
  THIS {
    $$ = new Node;
    $$->setValKeyw("this");
    $$->setValProd("<Name> --> this");
  }
  | ID LS expression RS {
    $$ = new Node;
    $$->setValProd("<Name> --> identifier [ <Expression> ]");
  }
  | name_other DOT ID {
    $$ = new Node;
    $$->pushNonTerminal($1);
    $$->setValProd("<Name> --> <Name> . identifier");
  }
  | name_other LS expression RS {
    $$ = new Node;
    $$->pushNonTerminal($1);
    $$->pushNonTerminal($3);
    $$->setValProd("<Name> --> <Name> [ <Expression> ]");
  }
  ;


name:
  ID {
    $$ = new Node;
    $$->setValProd("<Name> --> identifier");
  }
  | name_other {
    $$ = new Node;
    $$->pushNonTerminal($1);
  }
  ;


arg_lists:
  %empty { $$ = new Node; }
  | arg_lists COMMA expression {
    $$ = $1;
    $$->pushNonTerminal($3);
  }
  ;


arg_list:
  %empty { $$ = new Node; }
  | expression arg_lists {
    $$ = new Node;
    $$->setValProd("<ArgList> --> <Expression> <,<Expression> >*");
    $$->pushNonTerminal($1);
    $$->pushNonTerminal($2);
  }
  ;


optional_expression:
  %empty { $$ = new Node; $$->setValProd("<OptionalExpression> --> epsilon"); }
  | expression {
    $$ = new Node;
    $$->pushNonTerminal($1);
    $$->setValProd("<OptionalExpression> --> <Expression>");
  }
  ;


expression:
  name {
    $$ = new Node;
    $$->pushNonTerminal($1);
    $$->setValProd("<Expression> --> <Name>");
  }
  | NUMBER {
    $$ = new Node;
    $$->setValProd("<Expression> --> number");
  }
  | NLL {
    $$ = new Node;
    $$->setValProd("<Expression> --> null");
  }
  | name LP arg_list RP {
    $$ = new Node;
    $$->setValProd("<Expression> --> <Name> ( <ArgList> )");
    $$->pushNonTerminal($1);
    $$->pushNonTerminal($3);
  }
  | READ LP RP {
    $$ = new Node;
    $$->setValProd("<Expression> --> read ( )");
  }
  | new_expression {
    $$ = new Node;
    $$->pushNonTerminal($1);
    $$->setValProd("<Expression> --> <NewExpression>");
  }
  | PLUS expression {
    $$ = new Node;
    $$->pushNonTerminal($2);
    $$->setValProd("<Expression> --> + <Expression>");
  }
  | MINUS expression {
    $$ = new Node;
    $$->pushNonTerminal($2);
    $$->setValProd("<Expression> --> - <Expression>");
  }
  | NOT expression {
    $$ = new Node;
    $$->pushNonTerminal($2);
    $$->setValProd("<Expression> --> ! <Expression>");
  }
  | expression EQUALS expression {
    $$ = new Node;
    $$->pushNonTerminal($1);
    $$->pushNonTerminal($3);
    $$->setValProd("<Expression> --> <Expression> == <Expression>");
  }
  | expression NOTEQL expression {
    $$ = new Node;
    $$->pushNonTerminal($1);
    $$->pushNonTerminal($3);
    $$->setValProd("<Expression> --> <Expression> != <Expression>");
  }
  | expression LESSGRT expression {
    $$ = new Node;
    $$->pushNonTerminal($1);
    $$->pushNonTerminal($3);
    $$->setValProd("<Expression> --> <Expression> <= <Expression>");
  }
  | expression MOREGRT expression {
    $$ = new Node;
    $$->pushNonTerminal($1);
    $$->pushNonTerminal($3);
    $$->setValProd("<Expression> --> <Expression> >= <Expression>");
  }
  | expression GREATER expression {
    $$ = new Node;
    $$->pushNonTerminal($1);
    $$->pushNonTerminal($3);
    $$->setValProd("<Expression> --> <Expression> > <Expression>");
  }
  | expression LESS expression {
    $$ = new Node;
    $$->pushNonTerminal($1);
    $$->pushNonTerminal($3);
    $$->setValProd("<Expression> --> <Expression> < <Expression>");
  }
  | expression PLUS expression {
    $$ = new Node;
    $$->pushNonTerminal($1);
    $$->pushNonTerminal($3);
    $$->setValProd("<Expression> --> <Expression> + <Expression>");
  }
  | expression MINUS expression {
    $$ = new Node;
    $$->pushNonTerminal($1);
    $$->pushNonTerminal($3);
    $$->setValProd("<Expression> --> <Expression> - <Expression>");
  }
  | expression OROR expression {
    $$ = new Node;
    $$->pushNonTerminal($1);
    $$->pushNonTerminal($3);
    $$->setValProd("<Expression> --> <Expression> || <Expression>");
  }
  | expression MULT expression {
    $$ = new Node;
    $$->pushNonTerminal($1);
    $$->pushNonTerminal($3);
    $$->setValProd("<Expression> --> <Expression> * <Expression>");
  }
  | expression DIV expression {
    $$ = new Node;
    $$->pushNonTerminal($1);
    $$->pushNonTerminal($3);
    $$->setValProd("<Expression> --> <Expression> / <Expression>");
  }
  | expression REMAINDER expression  {
    $$ = new Node;
    $$->pushNonTerminal($1);
    $$->pushNonTerminal($3);
    $$->setValProd("<Expression> --> <Expression> % <Expression>");
  }
  | expression ANDAND expression {
    $$ = new Node;
    $$->pushNonTerminal($1);
    $$->pushNonTerminal($3);
    $$->setValProd("<Expression> --> <Expression> && <Expression>");
  }
  | LP expression RP {
    $$ = new Node;
    $$->pushNonTerminal($2);
    $$->setValProd("<Expression> --> ( <Expression> )");
  }
  ;

new_expression:
  NEW ID LP arg_list RP {
    $$ = new Node;
    $$->pushNonTerminal($4);
    $$->setValProd("<NewExpression> --> new identifier ( <ArgList> )");
  }
  | NEW INT exprsn_in_brackets multi_brackets {
    $$ = new Node;
    $$->pushNonTerminal($3);
    $$->pushNonTerminal($4);
    $$->setValProd("<NewExpression> --> new int <[ Expression ]>* <[ ]>+");
  }
  | NEW ID exprsn_in_brackets multi_brackets {
    $$ = new Node;
    $$->pushNonTerminal($3);
    $$->pushNonTerminal($4);
    $$->setValProd("<NewExpression> --> new identifier <[ Expression ]>* <[ ]>*");
  }
  | NEW INT exprsn_in_brackets {
    $$ = new Node;
    $$->pushNonTerminal($3);
    $$->setValProd("<NewExpression> --> new int <[ Expression ]>*");
  }
  | NEW ID exprsn_in_brackets {
    $$ = new Node;
    $$->pushNonTerminal($3);
    $$->setValProd("<NewExpression> --> new identifier <[ Expression ]>*");
  }
  ;


exprsn_in_brackets:
  %empty { $$ = new Node; };
  | exprsn_in_brackets LS expression RS {
    $$ = $1;
    $$->pushNonTerminal($3);
  }
  ;

%%
