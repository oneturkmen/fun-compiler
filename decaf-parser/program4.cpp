/**
  Program 4, program4.cpp
  Purpose: driver (main) file

  @author Batyr Nuryyev
  @date   11/01/2017
*/
#include <iostream>
#include <iomanip>
#include "program4.hpp"
#include "program4.tab.h"
#include <FlexLexer.h>
using namespace std;

/* -- -- -- -- -- -- -- -- */
yyFlexLexer scanner;
Node *tree;

/* -- -- -- MAIN -- -- -- */

int main() {
  yyparse();

  // to be done ...
  if (tree == NULL)
  {
    cout << endl;
    cout << "--  :( SRY Cannot print the tree        --" << endl;
    cout << "--    Possible reasons:                 --" << endl;
    cout << "-- 1) Errors in bison/flex              --" << endl;
    cout << "-- 2) Lex could not recognize character --" << endl;
    cout << "-- 3) Empty input                       --" << endl;
  }
  else {
    cout << endl << "-- PRINTING THE TREE --" << endl;
    //cout << "tree strucure: " << tree->getValProd();
    tree->print(&cout);
  }

  return 0;
}
