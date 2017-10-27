/**
  Program 3, program3.cpp
  Purpose: driver (main) file

  @author Batyr Nuryyev
  @date   10/27/2017
*/
#include <iostream>
#include <iomanip>
#include "program3.hpp"
#include "program3.tab.h"
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
    cout << "Error occured when trying to print the tree" << endl;
  }
  else {
    cout << "-- PRINTING THE TREE --" << endl;
    //cout << "tree strucure: " << tree->getValProd();
    tree->print(&cout);
  }

  return 0;
}
