/**
  Program 4, program4.cpp
  Purpose: driver (main) file

  @author Batyr Nuryyev
  @date   11/01/2017
*/
#include <iostream>
#include <string>
#include <iomanip>
#include <map>
#include "program4.hpp"
#include "program4.tab.h"
#include <FlexLexer.h>
using namespace std;

/* -- -- -- -- -- -- -- -- */
yyFlexLexer scanner;
Node *tree;

/* -- -- -- MAIN -- -- -- */


void checkTypeTree(Node *root)
{
  auto current_node_structure = root->getStructureType();
  auto current_symbol_table   = root->symbol_table;

  if (current_node_structure == "program") {
    cout << "Processing PROGRAM --> <CLASS>* " << endl;
    for (auto c : root->_children_assgn)
    {
      checkTypeTree(c);
    }
  }
  else if (current_node_structure == "class_decl")
  {
    cout << "Processing CLASS --> class ID { <CLASS_BODY> } " << endl;
    checkTypeTree(root->_children_assgn[0]);
  }
  else if (current_node_structure == "class_body")
  {
    /* No need to process <var_decl> -> already done in the first phase */
    cout << "Processing CLASS_BODY --> <VAR_DECL>* <CONSTRUCTOR_DECL>* <METHOD_DECL>*" << endl;
    for (auto c : root->_children_assgn)
    {
      checkTypeTree(c);
    }
  }
  else if (current_node_structure == "constructor_declmore")
  {
    cout << "Processing <constructor_declmore> --> <constructor_decl>*" << endl;
    for (auto c : root->_children_assgn)
    {
      checkTypeTree(c);
    }
  }
  else if (current_node_structure == "method_declmore")
  {
    cout << "Processing <method_declmore> --> <method_decl>*" << endl;
    for (auto c : root->_children_assgn)
    {
      checkTypeTree(c);
    }
  }
  else if (current_node_structure == "constructor_decl")
  {
    cout << "Processing <constructor_decl> --> ID ( <parameter_list> ) <block>" << endl;
    checkTypeTree(root->_children_assgn[1]); // type check only <block>; parameter_list already processed
  }
  else if (current_node_structure == "method_decl")
  {
    cout << "Processing <method_decl> --> type ID LP <parameter_list> RP <block>" << endl;
    checkTypeTree(root->_children_assgn[1]); // type check only <block>; parameter_list already processed
  }
  else if (current_node_structure == "block")
  {
    /* No need to process <local_var_decl> -> already done in the first phase */
    cout << "Processing <block> --> { <local_var_declmore> <statements> }" << endl;
    for (auto c : root->_children_assgn)
    {
      checkTypeTree(c);
    }
  }
  else if (current_node_structure == "statements")
  {
    cout << "Processing <statements> --> <statement>*" << endl;
    for (auto c : root->_children_assgn)
    {
      checkTypeTree(c);
    }
  }
  else if (current_node_structure == "statement_assignment")
  {
    /* <stmt> --> <name> = <expression> */
    /* type (name) == type (expression) */
    cout << "Processing <statement_assignment>" << endl;
    if (root->_children_assgn[0]->getValType() == "" &&
        root->_children_assgn[1]->getValType() == "")
    {
      cout << "  Neither <name> and <expression> have types ..." << endl;
      checkTypeTree(root->_children_assgn[0]);
      checkTypeTree(root->_children_assgn[1]);
    }

    auto lvalue = root->_children_assgn[0]->getValType();
    auto rvalue = root->_children_assgn[1]->getValType();

    if (lvalue != rvalue)
    {
      cout << "ERR: type mismatch in statement assignment" << endl;
      cout << "ERR: lvalue -> " << lvalue << endl;
      cout << "ERR: rvalue -> " << rvalue << endl;
    }

    // FIXME: GOTTA VALIDATE AND CHECK TYPES HERE ...
    /* if ... */
  }
  else if (current_node_structure == "statement_methodcall")
  {
    cout << "Processing <statement_methodcall>" << endl;
  }
  else if (current_node_structure == "statement_conditionalstmt")
  {
    cout << "Processing <statement_conditionalstmt>" << endl;
  }
  else if (current_node_structure == "statement_print")
  {
    cout << "Processing <statement_print>" << endl;
  }
  else if (current_node_structure == "statement_while")
  {
    cout << "Processing <statement_while>" << endl;
  }
  else if (current_node_structure == "statement_return")
  { // validate return_type and method type
    cout << "Processing <statement_return>" << endl;
  }
  else if (current_node_structure == "statement_block")
  {
    cout << "Processing <statement_block>" << endl;
  }
  // Here comes <name>
  else if (current_node_structure == "name_id")
  {
    cout << "Processing <name_id>" << endl;
    auto found_var_decl       = current_symbol_table->deepLookup("var_decl_" + root->getValId());
    auto found_local_var_decl = current_symbol_table->deepLookup("local_var_decl_" + root->getValId());

    if (found_var_decl == "" && found_local_var_decl == "")
    {
      cout << string("ERR: Variable <") +  root->getValId() + "> not declared" << endl;
    }
    else
    {
      root->setValType(found_var_decl == "" ? found_local_var_decl : found_var_decl);
    }
  }
  else if (current_node_structure == "name_this")
  {
    cout << "Processing <name_this>" << endl;
  }
  else if (current_node_structure == "name_iddotid")
  {
    cout << "Processing <name_iddotid>" << endl;
    auto first  = root->_children_assgn[0]->getValId();
    auto second = root->_children_assgn[1]->getValId();

    auto found_var_decl       = current_symbol_table->deepLookup("var_decl_" + first);
    auto found_local_var_decl = current_symbol_table->deepLookup("local_var_decl_" + first);

    if (found_var_decl == "" && found_local_var_decl == "")
    {
      cout << string("ERR: <") + first + "> not declared" << endl;
    }
    else
    {
      // 1. Deep lookup the class (type) name
      // 2. Check if it has the var_decl of second
      // 3. If yes, assign the type of second to the id.id
      string target_class = found_var_decl == "" ? found_local_var_decl : found_var_decl;
      string if_class_exists = current_symbol_table->deepLookup("class_" + target_class);

      if (if_class_exists == "")
      {
        cout << string("ERR: custom class <") + second + "> not declared" << endl;
      }
      else
      {
        string custom_decl_type = current_symbol_table->globalClassLookup(target_class, second);

        if (custom_decl_type == "")
        {
          cout << string("ERR: no variable <") + second + "> found in class <" + target_class + ">" << endl;
        }
        else
        {
          cout << string("Setting the type for <") + custom_decl_type + ">" << endl;
          root->setValType(custom_decl_type);
        }
      }
    }
  }
  else if (current_node_structure == "name_dotid") // non-terminating
  {
    cout << "Processing <name_dotid>" << endl;
    auto first = root->_children_assgn[0];
    auto second = root->_children_assgn[1]->getValId();

    if (first->getValId() == "")
    {
      checkTypeTree(root->_children_assgn[0]);
    }

    if (first->getValId() == "this")
    {
      auto class_st = root->symbol_table->getCurrentClass();
      auto second_exists = class_st->lookup(string("var_decl_") + second);

      if (second_exists == "")
      {
        cout << string("ERR: no class member <") + second + "> exists" << endl;
      }
    }

    if (first->getValType() == "int" || first->getValType() == "void")
    {
      cout << "ERR: must be of type <class>, not <" << first->getValType() << ">" << endl;
    }
    else
    {
      string custom_decl_type = current_symbol_table->globalClassLookup(first->getValType(), second);

      if (custom_decl_type == "")
      {
        cout << string("ERR: no variable <") + second + "> found in class <" + first->getValType() + ">" << endl;
      }
      else
      {
        cout << string("Setting the type for <") + custom_decl_type + ">" << endl;
        root->setValType(custom_decl_type);
      }
    }
  }
  else if (current_node_structure == "name_lsexprs_other")
  {
    cout << "Processing <name_lsexprs_other>" << endl;
    int numb_of_brackets = static_cast<int>(root->_children_assgn.size());

    auto type_of_id  = root->symbol_table->lookup(string("local_var_decl_") + root->getValId());
    auto type_of_id2 = root->symbol_table->deepLookup(string("var_decl_") + root->getValId());

    string target_type   = type_of_id == "" ? type_of_id2 : type_of_id;
    int target_type_size = static_cast<int>(target_type.size());

    if (target_type.substr(0, 3) != "int")
    {
      cout << string("ERR: type of <") + root->getValId() + "> is not of <int array>" << endl;
    }
    else if (((target_type_size - 4) / 2) < numb_of_brackets)
    {
      cout << string("ERR: type of <") + root->getValId() + "> is invalid" << endl;
    }
    else
    {
      // Gotta skip first child - the identifier
      for (auto child : root->_children_assgn)
      {
        if (child->getStructureType() != "expression_number" &&
            child->getStructureType() != "expression_null")
        {
          checkTypeTree(child);

          if (child->getValType() != "int")
          {
            cout << string("ERR: must have <int> when accessing array <") + root->getValId() + ">" << endl;
          }
        }
      }

      string current_node_type = "int";

      if (((target_type_size-4)/2)-numb_of_brackets) current_node_type.append(" ");

      for (int i = 0; i < ((target_type_size-4)/2)-numb_of_brackets; ++i)
      {
        current_node_type.append("[]");
      }

      root->setValType(current_node_type);
    }

  }
  // Here comes expressions
  else if (current_node_structure == "expression_name")
  {
    cout << "Processing <expression_name>" << endl;
    checkTypeTree(root->_children_assgn[0]);
    root->setValType(root->_children_assgn[0]->getValType());
  }
  else if (current_node_structure == "expression_number")
  {
    cout << "Processing <expression_number>" << endl;
    // Nothing to be done here ....
  }
  else if (current_node_structure == "expression_null")
  {
    cout << "Processing <expression_null>" << endl;
    // Nothing to be done here ....
  }
  else if (current_node_structure == "expression_methodcall")
  {
    cout << "Processing <expression_methodcall>" << endl;

    auto name_of_method = root->_children_assgn[0]->getValId();
    auto arguments_list = root->_children_assgn[1]->_children_assgn;

    string fun_def_type = root->symbol_table->deepLookup(string("method_decl_") + name_of_method);
    string function_arglist_type;
    string function_return_type;

    for (int i = 0; i < static_cast<int>(fun_def_type.size()-1); ++i)
    {
      if (fun_def_type[i] == '-')
      {
        function_arglist_type = fun_def_type.substr(i+2, fun_def_type.size()-i+1);
        function_return_type  = fun_def_type.substr(0, i-2);
        break;
      }
    }

    string arguments_type_rvalue = "";

    for (auto argument : arguments_list)
    {
      if (argument->getStructureType() != "expression_number")
      {
        checkTypeTree(argument);
      }
      arguments_type_rvalue.append(string(argument->getValType()) + " x ");
    }
    arguments_type_rvalue = arguments_type_rvalue.substr(0, arguments_type_rvalue.size()-3);
    cout << arguments_type_rvalue << endl;
    cout << function_arglist_type << endl;
    cout << function_return_type << endl;

    arguments_type_rvalue = arguments_type_rvalue == "" ? "void" : arguments_type_rvalue;

    if (function_arglist_type != arguments_type_rvalue)
    {
      cout << string("ERR: not enough arguments for function <") + name_of_method + ">" << endl;
    }
    else
    {
      root->setValType(function_return_type);
    }
  }
  else if (current_node_structure == "expression_read")
  {
    cout << "Processing <expression_read>" << endl;
  }
  else if (current_node_structure == "expression_newexpression")
  {
    cout << "Processing <expression_newexpression>" << endl;
  }
  else if (current_node_structure == "expression_unary")
  {
    cout << "Processing <expression_unary>" << endl;
  }
  else if (current_node_structure == "expression_unary_rel")
  {
    cout << "Processing <expression_unary_rel>" << endl;
  }
  else if (current_node_structure == "expression_binary_rel")
  {
    cout << "Processing <expression_binary_rel>" << endl;
  }
  else if (current_node_structure == "expression_binary_a")
  {
    cout << "Processing <expression_binary_a>" << endl;
  }
  else if (current_node_structure == "expression_binary_log")
  {
    cout << "Processing <expression_binary_log>" << endl;
  }
  else if (current_node_structure == "expression_leftrightpar")
  {
    cout << "Processing <expression_leftrightpar>" << endl;
  }

}

// building type tree
// INFO  : SHITTIES ALGORITHM I COULD COME UP WITH.
// REFACTOR AND THINK OF BETTER THINGS
void buildTypeTree(Node *root, vector <string> &errors)
{
  //FIXME: think about this algorithm

  if ((root->getStructureType()) == "program")
  {
    root->symbol_table = new SymbolTable();
    root->symbol_table->setScopeDefinition("global", "program");
    root->setNodeScopeType();
  }

  auto it = root->_children_assgn.begin();

  for (; it != root->_children_assgn.end(); it++)
  {
    // SWITCH CASE. DEFAULT IS ASSIGNING SAME SYMBOL_TABLE.
    string current_node_structure = (*it)->getStructureType();

    if (current_node_structure == "class_decl")
    {
      cout << "Processing class declaration ..." << (*it)->getValId() << endl;
      (*it)->symbol_table = new SymbolTable(root->symbol_table);
      (*it)->symbol_table->setScopeDefinition((*it)->getValId(), current_node_structure);
      (*it)->setNodeScopeType();

      if (root->symbol_table->getScopeName() == "global" &&
          root->symbol_table->getScopeType() == "program")
      {
        root->symbol_table->classes_sts.push_back((*it)->symbol_table);
      }

      auto found = root->symbol_table->lookup("class_" + (*it)->getValId());

      if (found != "")
      {
        errors.push_back(string("ERR: Class <") + (*it)->getValId() + "> declaration conflict");
      }
      else
      {
        root->symbol_table->insert("class_" + (*it)->getValId(), "class");
      }
    }
    else if (current_node_structure == "method_decl")
    {
      cout << "Processing method declaration ..." << endl;
      (*it)->symbol_table = new SymbolTable(root->symbol_table);
      (*it)->symbol_table->setScopeDefinition((*it)->getValId(), "method_decl");
      (*it)->setNodeScopeType();

      // Checking if the custom ID type exists
      // if ((*it)->getValType() != "int" && (*it)->getValType() != "void")
      // {
      //   auto custom_key = root->symbol_table->deepLookup(string("class_") + (*it)->getReturnType());
      //
      //   if (custom_key == "") {
      //     errors.push_back(string("ERR: Type <") + (*it)->getReturnType() + "> does not exist");
      //   }
      // }

      auto found = root->symbol_table->lookup("method_decl_" + (*it)->getValId());

      if (found != "")
      {
        errors.push_back(string("ERR: Method <") + (*it)->getValId() + "> declaration conflict");
      }
      else
      {
        root->symbol_table->insert("method_decl_" + (*it)->getValId(), (*it)->getValType());
      }
    }
    else if (current_node_structure == "constructor_decl")
    {
      cout << "Processing constructor declaration ..." << endl;

      if ((*it)->getValId() != (root->symbol_table->getScopeName()))
      {
        errors.push_back(string("ERR: Invalid constructor name for class <" + root->symbol_table->getScopeName() + ">"));
      }

      (*it)->symbol_table = new SymbolTable(root->symbol_table);
      (*it)->symbol_table->setScopeDefinition((*it)->getValId(), current_node_structure);
      (*it)->setNodeScopeType();

      auto found = root->symbol_table->lookup("constructor_decl_" + (*it)->getValId());

      if (found != "")
      {
        errors.push_back(string("ERR: Constructor of <") + (*it)->getValId() + "> declaration conflict");
      }
      else
      {
        root->symbol_table->insert("constructor_decl_" + (*it)->getValId(), (*it)->getValType());
      }
    }
    else if (current_node_structure == "statement_block") // statement -> block
    {
      cout << "Processing statement block ..." << endl;
      (*it)->symbol_table = new SymbolTable(root->symbol_table);
      (*it)->symbol_table->setScopeDefinition("", current_node_structure);
      (*it)->setNodeScopeType();

      int number_of_stmnts_in_scope = root->symbol_table->getNumStmBlocks();

      root->symbol_table->insert("statement_block_" + to_string(number_of_stmnts_in_scope), "statement_block");
    }
    else if (current_node_structure == "parameter_list")
    {
      vector <Node *> parameters = (*it)->_children_assgn;
      map <string, string> l_map_parameters; // ID -> Type

      for (auto &parameter : parameters)
      {
        auto found = l_map_parameters.find(parameter->getValId());

        if (found != l_map_parameters.end())
        {
          errors.push_back("ERR: Parameter with the same name");
          return;
        }
        else
        {
          l_map_parameters.insert({ parameter->getValId(), parameter->getValType() });
        }
      }

      (*it)->symbol_table = root->symbol_table;

      for (auto &parameter : parameters)
      {
        (*it)->symbol_table->insert(parameter->getValId(), parameter->getValType());
      }
    }
    else if (current_node_structure == "class_body")
    {
      cout << "Processing class body ..." << endl;
      (*it)->symbol_table = root->symbol_table;
    }
    else if (current_node_structure == "block")
    {
      cout << "Processing block ..." << endl;
      (*it)->symbol_table = root->symbol_table;
    }
    else if (current_node_structure == "var_decl")
    {
      cout << "Processing variable declaration ..." << endl;
      (*it)->symbol_table = root->symbol_table;

      // Checking if the custom ID type exists
      // if ((*it)->getValType() != "int" && (*it)->getValType() != "void")
      // {
      //   auto custom_key = root->symbol_table->deepLookup(string("class_") + (*it)->getValType());
      //
      //   if (custom_key == "") {
      //     errors.push_back(string("ERR: Type <") + (*it)->getValType() + "> does not exist");
      //   }
      // }

      auto found = (*it)->symbol_table->lookup("var_decl_" + (*it)->getValId());

      if (found != "")
      {
        errors.push_back(string("ERR: Variable <") + (*it)->getValId() + "> declaration conflict");
      }
      else if ((*it)->getValType() == "void")
      {
        errors.push_back(string("ERR: Ambiguous use of keyword in <") + (*it)->getValId() + ">");
      }
      else
      {
        (*it)->symbol_table->insert("var_decl_" + (*it)->getValId(), (*it)->getValType());
      }
    }
    else if (current_node_structure == "local_var_decl")
    {
      cout << "Processing local variable declaration ..." << endl;
      (*it)->symbol_table = root->symbol_table;

      // Checking if the custom ID type exists. Take substring, because there may be something else.
      // if (((*it)->getValType()).substr(0,3) != "int" && (*it)->getValType() != "void")
      // {
      //   auto custom_key = root->symbol_table->deepLookup(string("class_") + (*it)->getValType());
      //
      //   if (custom_key == "") {
      //     errors.push_back(string("ERR: Type <") + (*it)->getValType() + "> does not exist");
      //   }
      // }

      auto found = (*it)->symbol_table->lookup("local_var_decl_" + (*it)->getValId());

      if (found != "")
      {
        errors.push_back(string("ERR: Local variable <") + (*it)->getValId() + "> declaration conflict");
      }
      else if ((*it)->getValType() == "void")
      {
        errors.push_back(string("ERR: Ambiguous use of keyword in <") + (*it)->getValId() + ">");
      }
      else
      {
        (*it)->symbol_table->insert("local_var_decl_" + (*it)->getValId(), (*it)->getValType());
      }
    }
    else {
      cout << "Processing other : " << (*it)->getStructureType() << endl;
      (*it)->symbol_table = root->symbol_table;
    }
    //(*it)->setSymbolTableAddress(scope_sym_table);

    if ((*it)->_children_assgn.size() >= 1)
    {
      buildTypeTree(*it, errors);
    }
    else
    {
      cout << "DONE ..." << endl;
    }
  }
}


void dumpTable(Node *root)
{
  if (root == NULL)
  {
    return;
  }
  else
  {
    string node_strct = root->getStructureType();

    // if (node_strct == "class_decl"
    //     || node_strct == "method_decl"
    //     || node_strct == "constructor_decl"
    //     || node_strct == "statement_block"
    //     || node_strct == "block"
    //     || node_strct == "program")
    //{

    // cout << endl << " -- INFO ABOUT NODE -- " << endl;
    // cout << "structure type: " << root->getStructureType() << endl;
    // cout << "id " << root->getValId() << endl;
    // cout << "its children =>  ";
    //
    // for (auto x = root->_children_assgn.begin(); x != root->_children_assgn.end(); ++x)
    // {
    //   cout << "id " << (*x)->getValId() << " <> structure " << (*x)->getStructureType() << " ;;; ";
    // }
    // cout << endl << " -- END INFO -- " << endl;

    if (root->isItScope()) {
      root->symbol_table->dumpSymbolTable();
    }

    if (root->_children_assgn.size() >= 1)
    {
      auto it = root->_children_assgn.begin();
      for (; it != root->_children_assgn.end(); ++it)
      {
        dumpTable(*it);
      }
    }
    //}
    //else {
//      return;
    //s}
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
    Node *CLASS_DECL_1 = new Node;
    Node *CLASS_BODY_1 = new Node;
    Node *CLASS_DECL_2 = new Node;
    Node *CLASS_BODY_2 = new Node;
    Node *VAR_DECLR_1  = new Node;
    Node *VAR_DECLR_2  = new Node;
    Node *VAR_DECLR_3  = new Node;

    Node *METHOD_DECL_1       = new Node;
    Node *METHOD_1_BLOCK      = new Node;
    Node *METHOD_1_STMT_BLOCK = new Node;
    Node *LOCAL_VAR_DECL_1    = new Node;

    METHOD_DECL_1->setValId("fooMethod");
    METHOD_DECL_1->setValType("void");
    METHOD_DECL_1->setStructureType("method_decl");

    METHOD_1_BLOCK->setStructureType("block");
    METHOD_1_STMT_BLOCK->setStructureType("statement_block");

    LOCAL_VAR_DECL_1->setStructureType("local_var_decl");
    LOCAL_VAR_DECL_1->setValId("localMethod1Decl");
    LOCAL_VAR_DECL_1->setValType("int");

    BIG_ROOT->setStructureType("program");

    CLASS_DECL_1->setStructureType("class_decl");
    CLASS_DECL_2->setStructureType("class_decl");

    CLASS_DECL_1->setValId("Foo");
    CLASS_DECL_2->setValId("Bar");

    CLASS_BODY_1->setStructureType("class_body");
    CLASS_BODY_2->setStructureType("class_body");

    VAR_DECLR_1->setStructureType("var_decl");
    VAR_DECLR_2->setStructureType("var_decl");
    VAR_DECLR_3->setStructureType("var_decl");

    VAR_DECLR_1->setValType("int");
    VAR_DECLR_2->setValType("int");
    VAR_DECLR_3->setValType("string");

    VAR_DECLR_1->setValId("foovar");
    VAR_DECLR_2->setValId("barvar");
    VAR_DECLR_3->setValId("dervar");

    BIG_ROOT->pushNonTerminal(CLASS_DECL_1);
    BIG_ROOT->pushNonTerminal(CLASS_DECL_2);

    CLASS_DECL_1->pushNonTerminal(CLASS_BODY_1);
    CLASS_DECL_2->pushNonTerminal(CLASS_BODY_2);

    CLASS_BODY_1->pushNonTerminal(VAR_DECLR_1);
    CLASS_BODY_1->pushNonTerminal(VAR_DECLR_2);
    CLASS_BODY_1->pushNonTerminal(VAR_DECLR_3);

    CLASS_BODY_2->pushNonTerminal(METHOD_DECL_1);
    METHOD_DECL_1->pushNonTerminal(METHOD_1_BLOCK);
    METHOD_1_BLOCK->pushNonTerminal(METHOD_1_STMT_BLOCK);
    METHOD_1_STMT_BLOCK->pushNonTerminal(LOCAL_VAR_DECL_1);


    vector <string> first_phase_errors;

    buildTypeTree(tree, first_phase_errors);

    if (first_phase_errors.size() >= 1)
    {
      for (const auto &error : first_phase_errors)
      {
        cout << error << endl;
      }
    }
    else {
      cout << endl;
      cout << " -- -- STARTING SECOND PHASE => Type Checking -- -- ";
      cout << endl;
      checkTypeTree(tree);

      cout << endl;
      cout << " -- -- Dumping the symbol tables -- -- ";
      cout << endl;
      dumpTable(tree);
    }


  }

  return 0;
}
