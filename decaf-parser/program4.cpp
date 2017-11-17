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

// building type tree
// INFO  : SHITTIES ALGORITHM I COULD COME UP WITH.
// REFACTOR AND THINK OF BETTER THINGS
void buildTypeTree(Node *root)
{
  //FIXME: think about this algorithm

  if ((root->symbol_table) == NULL)
  {
     root->symbol_table = new SymbolTable(NULL);
  }

  auto it = root->_children_assgn.begin();

  for (; it != root->_children_assgn.end(); it++)
  {
    // SWITCH CASE. DEFAULT IS ASSIGNING SAME SYMBOL_TABLE.
    if ((*it)->getStructureType() == "class_decl")
    {
      cout << "Processing class declaration ..." << endl;
      (*it)->symbol_table = new SymbolTable(root->symbol_table);
      root->symbol_table->insert((*it)->getValId(), "class");
    }
    else if ((*it)->getStructureType() == "class_body")
    {
      cout << "Processing class body ..." << endl;
      (*it)->symbol_table = root->symbol_table;
    }
    else if ((*it)->getStructureType() == "var_decl")
    {
      cout << "Processing variable declaration ..." << endl;
      (*it)->symbol_table = root->symbol_table;
      (*it)->symbol_table->insert((*it)->getValId(), (*it)->getValType());
    }
    //(*it)->setSymbolTableAddress(scope_sym_table);

    if ((*it)->_children_assgn.size() >= 1)
    {
      buildTypeTree(*it);
    }
    else
    {
      cout << "DONE ..." << endl;
    }
  }
}


// Insert everything that needs to be inserted
// bool processOne(Node *root)
// {
//   cout << "Starting PS 1 ..." << endl;
//
//   if (root == NULL)
//   {
//     cout << "PS 1 ==> Root is null" << endl;
//     return 0;
//   }
//   else
//   {
//     SymbolTable *type_tree = buildTypeTree(root);
//   }
//
// }


// // Do the type checking
// bool processTwo()
// {
//   return true;
// }
//
//
// // Starter of type checking
// void semantic_analysis(Node *root)
// {
//   cout << "Starting semantic analysis ..." << endl;
//   bool one = processOne(root);
//   bool two = processTwo(root);
//   cout << "Finishing semantic analysis ..." << endl;
//   if (one && two)
//   {
//     cout << "Semantic analysis SUCCESSFUL" << endl;
//     return;
//   }
//   else
//   {
//     cout << "Semantic analysis FAILED" << endl;
//     return;
//   }
// }

void dumpTable(Node *root)
{
  if (root->getStructureType() == "var_decl") return;
  if (root->getStructureType() == "class_body") return;

  if (root == NULL)
  {
    return;
  }
  else
  {
    auto map_it = root->symbol_table->symbol_table.begin();

    for (; map_it != root->symbol_table->symbol_table.end(); ++map_it)
    {
      cout << map_it->first << " " << map_it->second << endl;
    }

    if (root->_children_assgn.size() >= 1)
    {
      auto it = root->_children_assgn.begin();
      for (; it != root->_children_assgn.end(); ++it)
      {
        dumpTable(*it);
      }
    }
  }
}


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

    cout << endl << "-- -- -- -- -- -- -- --" << endl;
    cout << "-- Checking the type --" << endl;


    // TEST TEST TEST TEST CAUTION WARNING
    Node *BIG_ROOT     = new Node;
    Node *CLASS_DECL   = new Node;
    Node *CLASS_BODY   = new Node;
    Node *VAR_DECLR_1  = new Node;
    Node *VAR_DECLR_2  = new Node;
    Node *VAR_DECLR_3  = new Node;

    CLASS_DECL->setStructureType("class_decl");
    CLASS_DECL->setValId("Foo");

    CLASS_BODY->setStructureType("class_body");

    VAR_DECLR_1->setStructureType("var_decl");
    VAR_DECLR_2->setStructureType("var_decl");
    VAR_DECLR_3->setStructureType("var_decl");

    VAR_DECLR_1->setValType("int");
    VAR_DECLR_2->setValType("int");
    VAR_DECLR_3->setValType("string");

    VAR_DECLR_1->setValId("foovar");
    VAR_DECLR_2->setValId("barvar");
    VAR_DECLR_3->setValId("dervar");


    BIG_ROOT->pushNonTerminal(CLASS_DECL);
    CLASS_DECL->pushNonTerminal(CLASS_BODY);
    CLASS_BODY->pushNonTerminal(VAR_DECLR_1);
    CLASS_BODY->pushNonTerminal(VAR_DECLR_2);
    CLASS_BODY->pushNonTerminal(VAR_DECLR_3);

    buildTypeTree(BIG_ROOT);
    dumpTable(BIG_ROOT);

  }

  return 0;
}
