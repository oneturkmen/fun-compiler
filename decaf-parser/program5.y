/**
  Program 5, program5.y
  Purpose: syntax analyzer (parser) file

  @author Batyr Nuryyev
  @date   11/26/2017
*/



%{

#include <iostream>
#include <vector>
#include <typeinfo>
#include <FlexLexer.h>
#include "program5.hpp"

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
               $$->setStructureType("program");
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
    $$->setStructureType("class_decl");
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


class_body: var_declmore constructor_declmore method_declmore {
    $$ = new Node;
    $$->pushNonTerminal($1);
    $$->pushNonTerminal($2);
    $$->pushNonTerminal($3);
    $$->setValProd("<ClassBody> --> { <VarDeclaration>+ <ConstructorDeclaration>+ <MethodDeclaration>+ }");
    $$->setStructureType("class_body");
  }
  | var_declmore constructor_declmore {
    $$ = new Node;
    $$->pushNonTerminal($1);
    $$->pushNonTerminal($2);
    $$->setValProd("<ClassBody> --> { <VarDeclaration>+ <ConstructorDeclaration>+ }");
    $$->setStructureType("class_body");
  }
  | var_declmore method_declmore {
    $$ = new Node;
    $$->pushNonTerminal($1);
    $$->pushNonTerminal($2);
    $$->setValProd("<ClassBody> --> { <VarDeclaration>+ <MethodDeclaration>+ }");
    $$->setStructureType("class_body");
  }
  | constructor_declmore method_declmore {
    $$ = new Node;
    $$->pushNonTerminal($1);
    $$->pushNonTerminal($2);
    $$->setValProd("<ClassBody> --> { <ConstructorDeclaration>+ <MethodDeclaration>+ }");
    $$->setStructureType("class_body");
  }
  | method_declmore {
    $$ = new Node;
    $$->pushNonTerminal($1);
    $$->setValProd("<ClassBody> --> { <MethodDeclaration>+ }");
    $$->setStructureType("class_body");
  }
  | var_declmore {
    $$ = new Node;
    $$->pushNonTerminal($1);
    $$->setValProd("<ClassBody> --> { <VarDeclaration>+ }");
    $$->setStructureType("class_body");
  }
  | constructor_declmore {
    $$ = new Node;
    $$->pushNonTerminal($1);
    $$->setValProd("<ClassBody> --> { <ConstructorDeclaration>+ }");
    $$->setStructureType("class_body");
  }
  | %empty { $$ = new Node; }
  ;


var_declmore:
  var_declmore var_decl {
    $$ = $1;
    $$->pushNonTerminal($2);
  }
  | var_decl {
    $$ = new Node;
    $$->pushNonTerminal($1);
    $$->setStructureType("var_declmore");
  }
  ;


multi_brackets:
  LS RS {
    $$ = new Node;
    $$->setValProd("<[]>* --> []");
    $$->setValType("[]");
  }
  | multi_brackets LS RS {
    $$ = $1;
    $$->setValProd("<[]>* --> []");
    $$->_type.append("[]");
  }
  ;


var_decl: ID ID SEMICOLON {
    $$ = new Node;
    $$->setValType($1->getValId());
    $$->setValId($2->getValId());
    $$->setValProd("<VarDeclaration> --> identifier identifier ;");
    $$->setStructureType("var_decl");
  }
  | INT ID SEMICOLON {
    $$ = new Node;
    $$->setValProd("<VarDeclaration> --> int identifier ;");
    $$->setValType("int");
    $$->setValId($2->getValId());
    $$->setStructureType("var_decl");
  }
  | ID multi_brackets ID SEMICOLON {
    $$ = new Node;
    $$->setValProd("<VarDeclaration> --> identifier <[]>* identifier ;");
    $$->setStructureType("var_decl");
    $$->setValType(string($1->getValId()) + " " + $2->getValType());
    $$->setValId($3->getValId());
    $$->pushNonTerminal($2);
  }
  | INT multi_brackets ID SEMICOLON {
    $$->setValProd("<VarDeclaration> --> int <[]>* identifier ;");
    $$->setStructureType("var_decl");
    $$->setValType(string("int") + " " + $2->getValType());
    $$->setValId($3->getValId());
    $$->pushNonTerminal($2);
  }
  ;


type_other:
  INT {
    $$ = new Node;
    $$->setValProd("<Type> --> int");
    $$->setValType("int ");
    $$->setStructureType("type");
  }
  | ID LS RS {
    $$ = new Node;
    $$->setValProd("<Type> --> identifier []");
    $$->setValType($1->getValId() + " []");
    $$->setStructureType("type");
  }
  | type_other LS RS {
    $$ = new Node;
    $$->pushNonTerminal($1);
    $$->setValProd("<Type> --> <Type> [ ]");
    $$->setStructureType("type_multi_brackets");
    $$->setValType($1->getValType() + "[]");
  }
  ;


type:
  ID {
    $$ = new Node;
    $$->setValProd("<Type> --> identifier");
    $$->setValType($1->getValId());
    $$->setStructureType("type");
  }
  | type_other {
    $$ = $1;
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
    $$->setStructureType("constructor_declmore");
  }
  ;


constructor_decl: ID LP parameter_list RP block {
    $$ = new Node;
    $$->setValProd("<ConstructorDeclaration> --> identifier ( <ParameterList> ) <Block>");
    $$->setStructureType("constructor_decl");
    $$->setValId($1->getValId());
    $$->setValType(string($1->getValId()) + " <- " + $3->getValType());
    $$->pushNonTerminal($3);
    $$->pushNonTerminal($5);
  }
  ;


method_declmore:
  method_declmore method_decl {
    $$ = $1;
    $$->pushNonTerminal($2);
  }
  | method_decl {
    $$ = new Node;
    $$->pushNonTerminal($1);
    $$->setStructureType("method_declmore");
  }
  ;


method_decl:
  INT ID LP parameter_list RP block {
    $$ = new Node;
    $$->setValProd("<MethodDeclaration> --> int identifier ( <ParameterList> ) <Block>");
    $$->setStructureType("method_decl");
    // FIXME: set the total type (i.e. with the return types)
    $$->setValType("int <- " + $4->getValType()); // FIXME: how to validate <return> with <method_type> hereerre?
    $$->setValId($2->getValId());
    $$->setReturnType("int");
    $$->pushNonTerminal($4);
    $$->pushNonTerminal($6);
  }
  | ID ID LP parameter_list RP block {
    $$ = new Node;
    $$->setValProd("<MethodDeclaration> --> identifier identifier ( <ParameterList> ) <Block>");
    $$->setStructureType("method_decl");
    $$->setValType($1->getValId() + " <- " + $4->getValType());
    $$->setReturnType($1->getValId());
    $$->setValId($2->getValId());
    $$->pushNonTerminal($4);
    $$->pushNonTerminal($6);
  }
  | VOID ID LP parameter_list RP block {
    $$ = new Node;
    $$->setValProd("<MethodDeclaration> --> void identifier ( <ParameterList> ) <Block>");
    $$->setStructureType("method_decl");
    $$->setValType("void <- " + $4->getValType());
    $$->setReturnType("void");
    $$->setValId($2->getValId());
    $$->pushNonTerminal($4);
    $$->pushNonTerminal($6);
  }
  | INT multi_brackets ID LP parameter_list RP block {
    $$ = new Node;
    $$->setValProd("<MethodDeclaration> --> int <[]>* identifier ( <ParameterList> ) <Block>");
    $$->setStructureType("method_decl");
    $$->setValType(string("int") + " " + $2->getValType() + " <- " + $5->getValType());
    $$->setValId($3->getValId());
    $$->pushNonTerminal($2);
    $$->pushNonTerminal($5);
    $$->pushNonTerminal($7);
  }
  | ID multi_brackets ID LP parameter_list RP block {
    $$ = new Node;
    $$->setValProd("<MethodDeclaration> --> identifier <[]>* identifier ( <ParameterList> ) <Block>");
    $$->setStructureType("method_decl");
    $$->setValType(string($1->getValId()) + " " + $2->getValType() + " <- " + $5->getValType());
    $$->setValId($3->getValId());
    $$->pushNonTerminal($2);
    $$->pushNonTerminal($5);
    $$->pushNonTerminal($7);
  }
  ;


parameter_list:
  %empty  {
    $$ = new Node;
    $$->setValProd("<ParameterList> --> e");
    $$->setStructureType("parameter_list");
    $$->setValType("void");
  }
  | parameter mult_parameters {
    $$ = $2;
    $$->setValProd("<ParameterList> --> <Parameter> <, <Parameter> >*");
    $$->pushNonTerminal($1);
    $$->setStructureType("parameter_list");
    $$->setValType(string($1->getValType()) + $2->getValType());
  }
  ;


mult_parameters:
  %empty {
    $$ = new Node;
    $$->setStructureType("mult_parameters");
  }
  | mult_parameters COMMA parameter {
    $$ = $1;
    $$->pushNonTerminal($3);
    $$->_type.append( string(" x ") + $3->getValType());
  }
  ;


parameter:
  ID ID {
    $$ = new Node;
    $$->setValProd("<Parameter> --> identifier identifier");
    $$->setStructureType("parameter");
    $$->setValType($1->getValId());
    $$->setValId($2->getValId());
  }
  | INT ID {
    $$ = new Node;
    $$->setValProd("<Parameter> --> int identifier");
    $$->setStructureType("parameter");
    $$->setValType("int");
    $$->setValId($2->getValId());
  }
  | ID multi_brackets ID {
    $$ = new Node;
    $$->setValProd("<Parameter> --> identifier <[]>* identifier");
    $$->setStructureType("parameter");
    $$->setValType($1->getValId() + " " + $2->getValType()); // FIXME: gotta somehow find the number brackets.
    $$->setValId($3->getValId());
    $$->pushNonTerminal($2);
  }
  | INT multi_brackets ID {
    $$ = new Node;
    $$->setValProd("<Parameter> --> int <[]>* identifier");
    $$->setStructureType("parameter");
    $$->setValType(string("int") + " " + $2->getValType());
    $$->setValId($3->getValId());
    $$->pushNonTerminal($2);
  }
  ;


block:
  LC local_var_declmore statements RC {
    $$ = new Node;
    $$->setValProd("<Block> --> { <LocalVarDeclaration>* <Statement>* }");
    $$->setStructureType("block");
    $$->pushNonTerminal($2);
    $$->pushNonTerminal($3);
  }
  | LC local_var_declmore RC {
    $$ = new Node;
    $$->setValProd("<Block> --> { <LocalVarDeclaration>* <Statement>* }");
    $$->setStructureType("block");
    $$->pushNonTerminal($2);
  }
  | LC statements RC {
    $$ = new Node;
    $$->setValProd("<Block> --> { <LocalVarDeclaration>* <Statement>* }");
    $$->setStructureType("block");
    $$->pushNonTerminal($2);
  }
  | LC RC {
    $$ = new Node;
    $$->setValProd("<Block> --> { <LocalVarDeclaration>* <Statement>* }");
    $$->setStructureType("block");
  }
  ;


local_var_declmore:
  local_var_decl { $$ = new Node; $$->pushNonTerminal($1); }
  | local_var_declmore local_var_decl {
    $$ = $1;
    $$->pushNonTerminal($2);
    $$->setStructureType("local_var_declmore");
  }
  ;


local_var_decl:
  type ID SEMICOLON {
    $$ = new Node;
    $$->setValProd("<LocalVarDeclaration> --> <Type> identifier ;");
    $$->setStructureType("local_var_decl");
    $$->setValType($1->getValType());
    $$->setValId($2->getValId());
    $$->pushNonTerminal($1);
  }
  ;


statements:
  statement {
    $$ = new Node;
    $$->setStructureType("statements");
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
    $$->setStructureType("statement_semicolon");
  }
  | name ASSIGN expression SEMICOLON {
    $$ = new Node;
    $$->setValProd("<Statement> --> <Name> = <Expression> ;");
    $$->setStructureType("statement_assignment");
    $$->setLocation(@1.first_line, @1.first_column);
    $$->pushNonTerminal($1);
    $$->pushNonTerminal($3);
  }
  | name LP arg_list RP SEMICOLON {
    $$ = new Node;
    $$->setValProd("<Statement> --> <Name> ( <ArgList> ) ;");
    $$->setStructureType("statement_methodcall");
    $$->setLocation(@1.first_line, @1.first_column);
    $$->pushNonTerminal($1);
    $$->pushNonTerminal($3);
  }
  | conditional_statement {
    $$ = new Node;
    $$->setValProd("<Statement> --> <ConditionalStatement>");
    $$->setStructureType("statement_conditionalstmt");
    $$->setLocation(@1.first_line, @1.first_column);
    $$->pushNonTerminal($1);
  }
  | PRINT LP arg_list RP SEMICOLON {
    $$ = new Node;
    $$->setValProd("<Statement> --> print ( <ArgList> ) ;");
    $$->setStructureType("statement_print");
    $$->setLocation(@1.first_line, @1.first_column);
    $$->pushNonTerminal($3);
  }
  | WHILE LP expression RP statement {
    $$ = new Node;
    $$->setValProd("<Statement> --> while ( <Expression> ) <Statement>");
    $$->setStructureType("statement_while");
    $$->setLocation(@1.first_line, @1.first_column);
    $$->pushNonTerminal($3);
    $$->pushNonTerminal($5);
  }
  | RETURN optional_expression SEMICOLON {
    $$ = new Node;
    $$->setValProd("<Statement> --> return <OptionalExpression> ;");
    $$->setStructureType("statement_return");
    $$->setLocation(@1.first_line, @1.first_column);
    $$->pushNonTerminal($2);
  }
  | block {
    $$ = new Node;
    $$->setValProd("<Statement> --> <Block>");
    $$->setStructureType("statement_block");
    $$->pushNonTerminal($1);
  }
  ;


conditional_statement:
  IF LP expression RP statement %prec "then" {
    $$ = new Node;
    $$->setValProd("<ConditionalStatement> --> if ( <Expression> ) <Statement>");
    $$->setStructureType("conditional_statement");
    $$->pushNonTerminal($3);
    $$->pushNonTerminal($5);
  }
  | IF LP expression RP statement ELSE statement {
    $$ = new Node;
    $$->setValProd("<ConditionalStatement> --> if ( <Expression> ) <Statement> else <Statement>");
    $$->setStructureType("conditional_statement");
    $$->pushNonTerminal($3);
    $$->pushNonTerminal($5);
    $$->pushNonTerminal($7);
  }
  ;


name_other:
  THIS {
    $$ = new Node;
    $$->setValKeyw("this");
    $$->setValId("this");
    $$->setValProd("<Name> --> this");
    $$->setStructureType("name_this");
  }
  | ID LS expression RS {
    $$ = new Node;
    $$->setValProd("<Name> --> identifier [ <Expression> ]");
    $$->pushNonTerminal($3);
    $$->setValId($1->getValId());
    $$->setLocation(@3.first_line, @3.first_column);
    $$->setStructureType("name_lsexprs_other");
  }
  | ID DOT ID {
    $$ = new Node;
    $$->pushNonTerminal($1);
    $$->pushNonTerminal($3);
    $$->setLocation(@1.first_line, @1.first_column);
    $$->setStructureType("name_iddotid");
  }
  | name_other DOT ID {
    $$ = new Node;
    $$->pushNonTerminal($1);
    $$->pushNonTerminal($3);
    $$->setValProd("<Name> --> <Name> . identifier");
    $$->setLocation(@1.first_line, @1.first_column);
    $$->setStructureType("name_dotid");
  }
  | name_other LS expression RS {
    $$ = $1;
    $$->pushNonTerminal($3);
    $$->setValProd("<Name> --> <Name> [ <Expression> ]");
    $$->setLocation(@1.first_line, @1.first_column);
    $$->setStructureType("name_lsexprs_other");
  }
  ;


name:
  ID {
    $$ = new Node;
    $$->setValProd("<Name> --> identifier");
    $$->setValId($1->getValId());
    $$->setLocation(@1.first_line, @1.first_column);
    $$->setStructureType("name_id");
  }
  | name_other {
    $$ = $1;
  }
  ;


arg_lists:
  %empty {
    $$ = new Node;
    $$->setStructureType("arg_lists");
  }
  | arg_lists COMMA expression {
    $$ = $1;
    $$->_type.append(" x " + $3->getValType());
    $$->pushNonTerminal($3);
  }
  ;


arg_list:
  %empty {
    $$ = new Node;
    $$->setValType("void");
    $$->setStructureType("arg_list");
  }
  | expression arg_lists {
    $$ = $2;
    $$->setValProd("<ArgList> --> <Expression> <,<Expression> >*");
    $$->setStructureType("arg_list");
    $$->setValType(string($1->getValType()) + $2->getValType());
    $$->setLocation(@1.first_line, @1.first_column);
    $$->pushNonTerminal($1);
  }
  ;


optional_expression:
  %empty {
    $$ = new Node;
    $$->setValProd("<OptionalExpression> --> epsilon");
    $$->setStructureType("optional_expression");
  }
  | expression {
    $$ = new Node;
    $$->pushNonTerminal($1);
    $$->setValProd("<OptionalExpression> --> <Expression>");
    $$->setStructureType("optional_expression");
  }
  ;


expression:
  name {
    $$ = new Node;
    $$->pushNonTerminal($1);
    $$->setValProd("<Expression> --> <Name>");
    $$->setLocation(@1.first_line, @1.first_column);
    $$->setStructureType("expression_name");
  }
  | NUMBER {
    $$ = new Node;
    $$->setValProd("<Expression> --> number");
    $$->setValType("int");
    $$->setStructureType("expression_number");
  }
  | NLL {
    $$ = new Node;
    $$->setValProd("<Expression> --> null");
    $$->setValType("null"); // good with classes
    $$->setStructureType("expression_null");
  }
  | name LP arg_list RP {
    $$ = new Node;
    $$->setValProd("<Expression> --> <Name> ( <ArgList> )");
    $$->pushNonTerminal($1);
    $$->pushNonTerminal($3);
    $$->setLocation(@1.first_line, @1.first_column);
    $$->setStructureType("expression_methodcall");
  }
  | READ LP RP {
    $$ = new Node;
    $$->setValProd("<Expression> --> read ( )");
    $$->setStructureType("expression_read");
    $$->setLocation(@1.first_line, @1.first_column);
    $$->setValType("read");
  }
  | new_expression {
    $$ = new Node;
    $$->pushNonTerminal($1);
    $$->setValProd("<Expression> --> <NewExpression>");
    $$->setLocation(@1.first_line, @1.first_column);
    $$->setStructureType("expression_newexpression");
  }
  | PLUS expression {
    $$ = new Node;
    $$->pushNonTerminal($2);
    $$->setValProd("<Expression> --> + <Expression>");
    $$->setUnaryOperator("+");
    $$->setLocation(@1.first_line, @1.first_column);
    $$->setStructureType("expression_unary");
  }
  | MINUS expression {
    $$ = new Node;
    $$->pushNonTerminal($2);
    $$->setValProd("<Expression> --> - <Expression>");
    $$->setUnaryOperator("-");
    $$->setLocation(@1.first_line, @1.first_column);
    $$->setStructureType("expression_unary");
  }
  | NOT expression {
    $$ = new Node;
    $$->pushNonTerminal($2);
    $$->setValProd("<Expression> --> ! <Expression>");
    $$->setLocation(@1.first_line, @1.first_column);
    $$->setUnaryOperator("!");
    $$->setStructureType("expression_unary_rel");
  }
  | expression EQUALS expression {
    $$ = new Node;
    $$->pushNonTerminal($1);
    $$->pushNonTerminal($3);
    $$->setValProd("<Expression> --> <Expression> == <Expression>");
    $$->setValOp("==");
    $$->setLocation(@1.first_line, @1.first_column);
    $$->setStructureType("expression_binary");
  }
  | expression NOTEQL expression {
    $$ = new Node;
    $$->pushNonTerminal($1);
    $$->pushNonTerminal($3);
    $$->setValOp("!=");
    $$->setValProd("<Expression> --> <Expression> != <Expression>");
    $$->setLocation(@1.first_line, @1.first_column);
    $$->setStructureType("expression_binary");
  }
  | expression LESSGRT expression {
    $$ = new Node;
    $$->pushNonTerminal($1);
    $$->pushNonTerminal($3);
    $$->setValOp("<=");
    $$->setValProd("<Expression> --> <Expression> <= <Expression>");
    $$->setLocation(@1.first_line, @1.first_column);
    $$->setStructureType("expression_binary");
  }
  | expression MOREGRT expression {
    $$ = new Node;
    $$->pushNonTerminal($1);
    $$->pushNonTerminal($3);
    $$->setValOp(">=");
    $$->setValProd("<Expression> --> <Expression> >= <Expression>");
    $$->setLocation(@1.first_line, @1.first_column);
    $$->setStructureType("expression_binary");
  }
  | expression GREATER expression {
    $$ = new Node;
    $$->pushNonTerminal($1);
    $$->pushNonTerminal($3);
    $$->setValOp(">");
    $$->setValProd("<Expression> --> <Expression> > <Expression>");
    $$->setLocation(@1.first_line, @1.first_column);
    $$->setStructureType("expression_binary");
  }
  | expression LESS expression {
    $$ = new Node;
    $$->pushNonTerminal($1);
    $$->pushNonTerminal($3);
    $$->setValOp("<");
    $$->setValProd("<Expression> --> <Expression> < <Expression>");
    $$->setLocation(@1.first_line, @1.first_column);
    $$->setStructureType("expression_binary");
  }
  | expression PLUS expression {
    $$ = new Node;
    $$->pushNonTerminal($1);
    $$->pushNonTerminal($3);
    $$->setValOp("+");
    $$->setValProd("<Expression> --> <Expression> + <Expression>");
    $$->setStructureType("expression_binary");
    $$->setLocation(@1.first_line, @1.first_column);
  }
  | expression MINUS expression {
    $$ = new Node;
    $$->pushNonTerminal($1);
    $$->pushNonTerminal($3);
    $$->setValOp("-");
    $$->setValProd("<Expression> --> <Expression> - <Expression>");
    $$->setLocation(@1.first_line, @1.first_column);
    $$->setStructureType("expression_binary");
  }
  | expression OROR expression {
    $$ = new Node;
    $$->pushNonTerminal($1);
    $$->pushNonTerminal($3);
    $$->setValOp("||");
    $$->setValProd("<Expression> --> <Expression> || <Expression>");
    $$->setLocation(@1.first_line, @1.first_column);
    $$->setStructureType("expression_binary");
  }
  | expression MULT expression {
    $$ = new Node;
    $$->pushNonTerminal($1);
    $$->pushNonTerminal($3);
    $$->setValOp("*");
    $$->setValProd("<Expression> --> <Expression> * <Expression>");
    $$->setLocation(@1.first_line, @1.first_column);
    $$->setStructureType("expression_binary");
  }
  | expression DIV expression {
    $$ = new Node;
    $$->pushNonTerminal($1);
    $$->pushNonTerminal($3);
    $$->setValOp("/");
    $$->setValProd("<Expression> --> <Expression> / <Expression>");
    $$->setLocation(@1.first_line, @1.first_column);
    $$->setStructureType("expression_binary");
  }
  | expression REMAINDER expression  {
    $$ = new Node;
    $$->pushNonTerminal($1);
    $$->pushNonTerminal($3);
    $$->setValOp("%");
    $$->setValProd("<Expression> --> <Expression> % <Expression>");
    $$->setLocation(@1.first_line, @1.first_column);
    $$->setStructureType("expression_binary");
  }
  | expression ANDAND expression {
    $$ = new Node;
    $$->pushNonTerminal($1);
    $$->pushNonTerminal($3);
    $$->setValOp("&&");
    $$->setValProd("<Expression> --> <Expression> && <Expression>");
    $$->setLocation(@1.first_line, @1.first_column);
    $$->setStructureType("expression_binary");
  }
  | LP expression RP {
    $$ = new Node;
    $$->pushNonTerminal($2);
    $$->setValProd("<Expression> --> ( <Expression> )");
    $$->setLocation(@1.first_line, @1.first_column);
    $$->setStructureType("expression_leftrightpar");
  }
  ;


new_expression:
  NEW ID LP arg_list RP {
    $$ = new Node;
    //$$->pushNonTerminal($2);
    //$$->pushNonTerminal($4);
    $$->setValId($2->getValId());
    $$->setValType($4->getValType());
    $$->setValProd("<NewExpression> --> new identifier ( <ArgList> )");
    $$->setLocation(@1.first_line, @1.first_column);
    $$->setStructureType("new_expression_constructor");
  }
  | NEW INT exprsn_in_brackets multi_brackets { // FIXME: do something here as well
    $$ = new Node;
    $$->pushNonTerminal($3);
    $$->pushNonTerminal($4);
    $$->setValType("int");
    $$->setValProd("<NewExpression> --> new int <[ Expression ]>* <[ ]>+");
    $$->setLocation(@1.first_line, @1.first_column);
    $$->setStructureType("new_expression_twobrackets");
  }
  | NEW ID exprsn_in_brackets multi_brackets {
    $$ = new Node;
    $$->pushNonTerminal($3);
    $$->pushNonTerminal($4);
    $$->setValType($2->getValId());
    $$->setValProd("<NewExpression> --> new identifier <[ Expression ]>* <[ ]>*");
    $$->setLocation(@1.first_line, @1.first_column);
    $$->setStructureType("new_expression_twobrackets");
  }
  | NEW INT exprsn_in_brackets {
    $$ = new Node;
    $$->pushNonTerminal($3);
    $$->setValType("int");
    $$->setValProd("<NewExpression> --> new int <[ Expression ]>*");
    $$->setLocation(@1.first_line, @1.first_column);
    $$->setStructureType("new_expression_brackets");
  }
  | NEW ID exprsn_in_brackets {
    $$ = new Node;
    $$->pushNonTerminal($3);
    $$->setValType($2->getValId());
    $$->setValProd("<NewExpression> --> new identifier <[ Expression ]>*");
    $$->setLocation(@1.first_line, @1.first_column);
    $$->setStructureType("new_expression_brackets");
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
