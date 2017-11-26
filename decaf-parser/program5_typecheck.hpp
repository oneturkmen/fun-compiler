/**
  Program 5, program5_typecheck.hpp
  Purpose: two stages of type checking

  @author Batyr Nuryyev
  @date   11/26/2017
*/


#ifndef  TP_CHECK_CPP
#define TP_CHECK_CPP

#include "program5.hpp"
#include <vector>
#include <string>
#include <map>

// SECOND STAGE
void checkTypeTree(Node *root, vector <string> &errors)
{
  auto current_node_structure = root->getStructureType();
  auto current_symbol_table   = root->symbol_table;

  if (current_node_structure == "program") {
    for (auto c : root->_children_assgn)
    {
      checkTypeTree(c, errors);
    }
  }
  else if (current_node_structure == "class_decl")
  {
    checkTypeTree(root->_children_assgn[0], errors);
  }
  else if (current_node_structure == "class_body")
  {
    /* No need to process <var_decl> -> already done in the first phase */
    for (auto c : root->_children_assgn)
    {
      checkTypeTree(c, errors);
    }
  }
  else if (current_node_structure == "constructor_declmore")
  {
    for (auto c : root->_children_assgn)
    {
      checkTypeTree(c, errors);
    }
  }
  else if (current_node_structure == "method_declmore")
  {
    for (auto c : root->_children_assgn)
    {
      checkTypeTree(c, errors);
    }
  }
  else if (current_node_structure == "constructor_decl")
  {
    checkTypeTree(root->_children_assgn[1], errors); // type check only <block>; parameter_list already processed
  }
  else if (current_node_structure == "method_decl")
  {
    checkTypeTree(root->_children_assgn[1], errors); // type check only <block>; parameter_list already processed
  }
  else if (current_node_structure == "block")
  {
    /* No need to process <local_var_decl> -> already done in the first phase */
    for (auto c : root->_children_assgn)
    {
      checkTypeTree(c, errors);
    }
  }
  else if (current_node_structure == "statements")
  {
    for (auto c : root->_children_assgn)
    {
      checkTypeTree(c, errors);
    }
  }
  else if (current_node_structure == "statement_assignment")
  {
    /* <stmt> --> <name> = <expression> */
    /* type (name) == type (expression) */
    if (root->_children_assgn[0]->getValType() == "")
    {
      checkTypeTree(root->_children_assgn[0], errors);
    }
    if (root->_children_assgn[1]->getValType() == "")
    {
      checkTypeTree(root->_children_assgn[1], errors);
    }

    auto lvalue = root->_children_assgn[0]->getValType();
    auto rvalue = root->_children_assgn[1]->getValType();

    if (lvalue.substr(0,3) != "int" && lvalue != "" && rvalue == "null")
    {
      // do nothing ... I mean "null" can be assigned to any class type
    }
    else if (lvalue != rvalue)
    {
      errors.push_back(string("ERR: ") +
                       to_string(root->getLine()) + ":" +
                       to_string(root->getColumn()) +
                       " --> <" + lvalue + "> and <" + rvalue + "> mismatch");
    }
    else if (lvalue == "" && rvalue == "")
    {
      errors.push_back(string("ERR: ") +
                       to_string(root->getLine()) + ":" +
                       to_string(root->getColumn()) +
                       " --> both rvalue and lvalue are not assigned type");
    }
  }
  else if (current_node_structure == "statement_methodcall")
  {
    auto name_of_method = root->_children_assgn[0]->getValId();
    auto arguments_list = root->_children_assgn[1]->_children_assgn;

    //string fun_def_type = current_symbol_table->deepLookup(string("method_decl_") + name_of_method);
    string function_arglist_type;
    string function_return_type;

    if (name_of_method == "")
    {
      checkTypeTree(root->_children_assgn[0], errors);
      name_of_method = root->_children_assgn[0]->getValId();
    }

    if (name_of_method == "")
    {
      errors.push_back(string("ERR: ") +
                       to_string(root->getLine()) + ":" +
                       to_string(root->getColumn()) +
                       " --> function <" + name_of_method + "> not declared");
      return;
    }

    string function_type = root->_children_assgn[0]->getValType();

    for (int i = 0; i < static_cast<int>(function_type.size()-1); ++i)
    {
      if (function_type[i] == '-')
      {
        function_arglist_type = function_type.substr(i+2, function_type.size()-i+1);
        function_return_type  = function_type.substr(0, i-2);
        break;
      }
    }

    string arguments_type_rvalue = "";

    for (auto argument : arguments_list)
    {
      if (argument->getStructureType() != "expression_number")
      {
        checkTypeTree(argument, errors);
      }
      arguments_type_rvalue.append(string(argument->getValType()) + " x ");
    }
    arguments_type_rvalue = arguments_type_rvalue.substr(0, arguments_type_rvalue.size()-3);

    arguments_type_rvalue = arguments_type_rvalue == "" ? "void" : arguments_type_rvalue;

    if (function_arglist_type != arguments_type_rvalue)
    {
      errors.push_back(string("ERR: ") +
                       to_string(root->getLine()) + ":" +
                       to_string(root->getColumn()) +
                       " --> not enough arguments for <" + name_of_method + ">");
    }

  }
  else if (current_node_structure == "statement_conditionalstmt")
  {
    checkTypeTree(root->_children_assgn[0], errors);
  }
  else if (current_node_structure == "statement_print")
  {
    for (auto argument : root->_children_assgn[0]->_children_assgn)
    {
      if (argument->getStructureType() != "expression_number")
      {
        checkTypeTree(argument, errors);
      }
    }
  }
  else if (current_node_structure == "statement_while")
  {
    auto expression = root->_children_assgn[0];

    if (expression->getStructureType() != "expression_number")
    {
      checkTypeTree(expression, errors);
    }

    if (expression->getValType() != "int")
    {
      cout << "ERR: " << endl;
      errors.push_back(string("ERR: ") +
                       to_string(root->getLine()) + ":" +
                       to_string(root->getColumn()) +
                       " --> in <while> statement, expression must be type of <int>");
    }

    checkTypeTree(root->_children_assgn[1], errors);
  }
  else if (current_node_structure == "statement_return")
  { // validate return_type and method type
    // 1. get current method! scope
    // 2. get its type (e.g. int <- int x A x B)
    // 3. compare!
    checkTypeTree(root->_children_assgn[0], errors);

    auto method_scope = root->symbol_table->getCurrentMethodType();

    if (method_scope == "")
    {
      errors.push_back(string("ERR: ") +
                       to_string(root->getLine()) + ":" +
                       to_string(root->getColumn()) +
                       " --> <return> can only be used in the <method> scope");
    }
    else
    {
      for (int i = 0; i < static_cast<int>(method_scope.size()); ++i)
      {
        if (method_scope[i] == '<')
        {
          method_scope = method_scope.substr(0, i-1);
          break;
        }
      }

      auto return_type = root->_children_assgn[0]->getValType();

      if (return_type != method_scope)
      {
        errors.push_back(string("ERR: ") +
                         to_string(root->getLine()) + ":" +
                         to_string(root->getColumn()) +
                         " --> <return> and <method> types differ");
      }
    }
  }
  else if (current_node_structure == "optional_expression")
  {
    if (root->_children_assgn.size() >= 1)
    {
      if (root->_children_assgn[0]->getStructureType() == "expression_number")
      {
        root->setValType("int");
      }
      else
      {
        checkTypeTree(root->_children_assgn[0], errors);
        root->setValType(root->_children_assgn[0]->getValType());
      }
    }
    else
    {
      root->setValType("void");
    }
  }
  else if (current_node_structure == "statement_block")
  {
    checkTypeTree(root->_children_assgn[0], errors);
  }
  else if (current_node_structure == "conditional_statement")
  {
    // 1. check if exp.type == number
    // 2. if not, err
    // 3. if ok, type check the statement
    auto condition = root->_children_assgn[0];

    if (condition->getStructureType() != "expression_number")
    {
      checkTypeTree(condition, errors);
    }

    if (condition->getValType() != "int")
    {
      errors.push_back(string("ERR: ") +
                       to_string(root->getLine()) + ":" +
                       to_string(root->getColumn()) +
                       " --> in conditional statement, expression must be of type <int>");
    }

    for (auto it = root->_children_assgn.begin() + 1;
         it != root->_children_assgn.end(); ++it)
    {
      checkTypeTree(*it, errors);
    }
  }
  // Here comes <name>
  else if (current_node_structure == "name_id")
  {
    auto found_var_decl       = current_symbol_table->deepLookup("var_decl_" + root->getValId());
    auto found_local_var_decl = current_symbol_table->deepLookup("local_var_decl_" + root->getValId());

    if (found_var_decl == "" && found_local_var_decl == "")
    {
      errors.push_back(string("ERR: ") +
                       to_string(root->getLine()) + ":" +
                       to_string(root->getColumn()) +
                       " --> variable <" + root->getValId() + "> not declared");
    }
    else
    {
      root->setValType(found_var_decl == "" ? found_local_var_decl : found_var_decl);
    }
  }
  else if (current_node_structure == "name_this")
  {
    // Do nothing ...
    auto type_of_this = root->symbol_table->getCurrentClass()->getScopeName();
    root->setValType(type_of_this);
  }
  else if (current_node_structure == "name_iddotid")
  {
    auto first  = root->_children_assgn[0]->getValId();
    auto second = root->_children_assgn[1]->getValId();

    auto found_var_decl       = current_symbol_table->deepLookup("var_decl_" + first);
    auto found_local_var_decl = current_symbol_table->deepLookup("local_var_decl_" + first);

    if (found_var_decl == "" && found_local_var_decl == "")
    {
      errors.push_back(string("ERR: ") +
                       to_string(root->getLine()) + ":" +
                       to_string(root->getColumn()) +
                       " --> <" + first + "> not declared");
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
        errors.push_back(string("ERR: ") +
                         to_string(root->getLine()) + ":" +
                         to_string(root->getColumn()) +
                         " --> custom class <" + second + "> not declared");
      }
      else
      {
        string custom_decl_type = current_symbol_table->globalClassLookup(target_class, string("var_decl_")+second);
        string custom_meth_type = current_symbol_table->globalClassLookup(root->_children_assgn[0]->getValType(), string("method_decl_")+second);

        if (custom_decl_type == "" && custom_meth_type == "")
        {
          errors.push_back(string("ERR: ") +
                           to_string(root->getLine()) + ":" +
                           to_string(root->getColumn()) +
                           " --> no variable <" + second + "> found in class <"+
                           target_class + ">");
        }
        else
        {
          cout << string("Setting the type for <") + custom_decl_type + ">" << endl;
          root->setValType(custom_decl_type == "" ? custom_meth_type : custom_decl_type);
          root->setValId(second);
        }
      }
    }
  }
  else if (current_node_structure == "name_dotid") // non-terminating
  {
    auto first = root->_children_assgn[0];
    auto second = root->_children_assgn[1]->getValId();

    if (first->getValId() == "")
    {
      checkTypeTree(root->_children_assgn[0], errors);
    }

    if (first->getValId() == "this")
    {
      auto class_st = current_symbol_table->getCurrentClass();
      first->setValType(class_st->getScopeName());
      auto second_exists = class_st->lookup(string("var_decl_") + second);

      if (second_exists == "")
      {
        errors.push_back(string("ERR: ") +
                         to_string(root->getLine()) + ":" +
                         to_string(root->getColumn()) +
                         " --> no class member <" + second + "> exists");
      }
    }

    if (first->getValType() == "int" || first->getValType() == "void")
    {
      errors.push_back(string("ERR: ") +
                       to_string(root->getLine()) + ":" +
                       to_string(root->getColumn()) +
                       " --> must be of type <class>, not <" + first->getValType() + "> exists");
    }
    else
    {
      string custom_decl_type = current_symbol_table->globalClassLookup(first->getValType(), string("var_decl_")+second);
      string custom_meth_type = current_symbol_table->globalClassLookup(first->getValType(), string("method_decl_")+second);

      if (custom_decl_type == "" && custom_meth_type == "")
      {
        errors.push_back(string("ERR: ") +
                         to_string(root->getLine()) + ":" +
                         to_string(root->getColumn()) +
                         " --> no variable <" + second + "> found in class <" +
                         first->getValType() + ">");
      }
      else
      {
        root->setValType(custom_decl_type == "" ? custom_meth_type : custom_decl_type);
        root->setValId(second);
      }
    }
  }
  else if (current_node_structure == "name_lsexprs_other")
  {
    int numb_of_brackets = static_cast<int>(root->_children_assgn.size());

    auto type_of_id  = current_symbol_table->deepLookup(string("local_var_decl_") + root->getValId());
    auto type_of_id2 = current_symbol_table->deepLookup(string("var_decl_") + root->getValId());

    string target_type   = type_of_id == "" ? type_of_id2 : type_of_id;
    int target_type_size = static_cast<int>(target_type.size());

    if (target_type.substr(0, 3) != "int")
    {
      errors.push_back(string("ERR: ") +
                       to_string(root->getLine()) + ":" +
                       to_string(root->getColumn()) +
                       " --> type of <" + root->getValId() + "> is not of <int array>");
    }
    else if (((target_type_size - 4) / 2) < numb_of_brackets)
    {
      errors.push_back(string("ERR: ") +
                       to_string(root->getLine()) + ":" +
                       to_string(root->getColumn()) +
                       " --> type of <" + root->getValId() + "> is invalid");
    }
    else
    {
      // Gotta skip first child - the identifier
      for (auto child : root->_children_assgn)
      {
        if (child->getStructureType() != "expression_number" &&
            child->getStructureType() != "expression_null")
        {
          checkTypeTree(child, errors);

          if (child->getValType() != "int")
          {
            errors.push_back(string("ERR: ") +
                             to_string(root->getLine()) + ":" +
                             to_string(root->getColumn()) +
                             " --> must have <int> when accessing array <" +
                             root->getValId() + ">");
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
    checkTypeTree(root->_children_assgn[0], errors);
    root->setValType(root->_children_assgn[0]->getValType());
  }
  else if (current_node_structure == "expression_number")
  {
    // Nothing to be done here ....
  }
  else if (current_node_structure == "expression_null")
  {
    // Nothing to be done here ....
  }
  else if (current_node_structure == "expression_methodcall")
  {
    auto name_of_method = root->_children_assgn[0]->getValId();
    auto arguments_list = root->_children_assgn[1]->_children_assgn;

    //string fun_def_type = current_symbol_table->deepLookup(string("method_decl_") + name_of_method);
    string function_arglist_type;
    string function_return_type;

    if (name_of_method == "")
    {
      checkTypeTree(root->_children_assgn[0], errors);
      name_of_method = root->_children_assgn[0]->getValId();
      cout << "type  " << root->_children_assgn[0]->getValType() << endl;
    }

    if (name_of_method == "")
    {
      errors.push_back(string("ERR: ") +
                       to_string(root->getLine()) + ":" +
                       to_string(root->getColumn()) +
                       " --> function <" + name_of_method + "> not declared");
      return;
    }

    string function_type = root->_children_assgn[0]->getValType();

    for (int i = 0; i < static_cast<int>(function_type.size()-1); ++i)
    {
      if (function_type[i] == '-')
      {
        function_arglist_type = function_type.substr(i+2, function_type.size()-i+1);
        function_return_type  = function_type.substr(0, i-2);
        break;
      }
    }

    string arguments_type_rvalue = "";

    for (auto argument : arguments_list)
    {
      if (argument->getStructureType() != "expression_number")
      {
        checkTypeTree(argument, errors);
      }
      arguments_type_rvalue.append(string(argument->getValType()) + " x ");
    }
    arguments_type_rvalue = arguments_type_rvalue.substr(0, arguments_type_rvalue.size()-3);

    arguments_type_rvalue = arguments_type_rvalue == "" ? "void" : arguments_type_rvalue;

    if (function_arglist_type != arguments_type_rvalue)
    {
      errors.push_back(string("ERR: ") +
                       to_string(root->getLine()) + ":" +
                       to_string(root->getColumn()) +
                       " --> not enough arguments for <" + name_of_method + ">");
    }
    else
    {
      root->setValType(function_return_type);
    }
  }
  else if (current_node_structure == "expression_read")
  {
    // Nothing to be done here ...
  }
  else if (current_node_structure == "expression_newexpression")
  {
    checkTypeTree(root->_children_assgn[0], errors);
    root->setValType(root->_children_assgn[0]->getValType());
  }
  else if (current_node_structure == "expression_unary")
  {
    if (root->_children_assgn[0]->getStructureType() != "expression_number")
    {
      checkTypeTree(root->_children_assgn[0], errors);
    }

    root->setValType(root->_children_assgn[0]->getValType());

    if (root->getValType() != "int")
    {
      errors.push_back(string("ERR: ") +
                       to_string(root->getLine()) + ":" +
                       to_string(root->getColumn()) +
                       " --> operand must be <int> in unary \"+/-\" expression");
    }
  }
  else if (current_node_structure == "expression_unary_rel")
  {
    if (root->_children_assgn[0]->getStructureType() != "expression_number")
    {
      checkTypeTree(root->_children_assgn[0], errors);
    }

    root->setValType(root->_children_assgn[0]->getValType());

    if (root->getValType() != "int")
    {
      errors.push_back(string("ERR: ") +
                       to_string(root->getLine()) + ":" +
                       to_string(root->getColumn()) +
                       " --> operand must be <int> in unary \"+/-\" expression");
    }
  }
  else if (current_node_structure == "expression_binary")
  {
    auto first  = root->_children_assgn[0];
    auto second = root->_children_assgn[1];

    if (first->getStructureType() != "expression_number")
    {
      checkTypeTree(first, errors);
    }
    if (second->getStructureType() != "expression_number")
    {
      checkTypeTree(second, errors);
    }

    if (first->getValType() != "int")
    {
      errors.push_back(string("ERR: ") +
                       to_string(root->getLine()) + ":" +
                       to_string(root->getColumn()) +
                       " --> in binary expression 1st operand is not <int>");
    }
    else if (second->getValType() != "int")
    {
      errors.push_back(string("ERR: ") +
                       to_string(root->getLine()) + ":" +
                       to_string(root->getColumn()) +
                       " --> in binary expression 2nd operand is not <int>");
    }
    else
    {
      root->setValType("int");
    }
  }
  else if (current_node_structure == "expression_leftrightpar")
  {
    if (root->_children_assgn[0]->getStructureType() != "expression_number")
    {
      checkTypeTree(root->_children_assgn[0], errors);
    }

    if (root->_children_assgn[0]->getValType() != "int")
    {
      errors.push_back(string("ERR: ") +
                       to_string(root->getLine()) + ":" +
                       to_string(root->getColumn()) +
                       " --> <int> required in brackets expression");
    }
    else
    {
      root->setValType(root->_children_assgn[0]->getValType());
    }
  }
  else if (current_node_structure == "new_expression_constructor")
  {
    auto id   = root->getValId();
    auto call_args = root->getValType();

    auto constructor_type = current_symbol_table->globalClassLookup(id, string("constructor_decl_") + id);
    string constructor_args;
    string constructor_class;

    for (int i = 0; i < static_cast<int>(constructor_type.size()-1); ++i)
    {
      if (constructor_type[i] == '-')
      {
        constructor_args = constructor_type.substr(i+2, constructor_type.size()-i+1);
        constructor_class = constructor_type.substr(0, i-2);
        break;
      }
    }

    if (constructor_args != call_args)
    {
      errors.push_back(string("ERR: ") +
                       to_string(root->getLine()) + ":" +
                       to_string(root->getColumn()) +
                       " --> invalid constructor call of class <" +
                       constructor_class + ">");
    }
    else
    {
      root->setValType(constructor_class);
    }

  }
  else if (current_node_structure == "new_expression_twobrackets")
  {
    auto exprs_in_brackets = root->_children_assgn[0]->_children_assgn;
    int number_of_brackets = static_cast<int>(exprs_in_brackets.size());

    auto multi_brackets    = root->_children_assgn[1]->getValType();
    auto current_node_type = root->getValType();

    for (auto child : exprs_in_brackets)
    {
      if (child->getStructureType() != "expression_number" &&
          child->getStructureType() != "expression_null")
      {
        checkTypeTree(child, errors);

        if (child->getValType() != "int")
        {
          errors.push_back(string("ERR: ") +
                           to_string(root->getLine()) + ":" +
                           to_string(root->getColumn()) +
                           " --> must have <int> when accessing array");
        }
      }
    }

    if (current_node_type != "int")
    {
      auto type_of_id  = current_symbol_table->deepLookup(string("local_var_decl_") + root->getValType());
      auto type_of_id2 = current_symbol_table->deepLookup(string("var_decl_") + root->getValType());
      current_node_type= type_of_id == "" ? type_of_id2 : type_of_id;

      root->setValType(current_node_type);
    }
    else
    {
      string final_type = "";
      final_type = "int";

      if (number_of_brackets >= 1 || multi_brackets != "")
      {
        final_type.append(" ");

        for (int i = 0; i < number_of_brackets; ++i)
        {
          final_type.append("[]");
        }

        final_type.append(multi_brackets);
      }


      root->setValType(final_type);
    }

  }
  else if (current_node_structure == "new_expression_brackets")
  {
    auto exprs_in_brackets = root->_children_assgn[0]->_children_assgn;
    int number_of_brackets = static_cast<int>(exprs_in_brackets.size());

    auto current_node_type = root->getValType();

    for (auto child : exprs_in_brackets)
    {
      if (child->getStructureType() != "expression_number" &&
          child->getStructureType() != "expression_null")
      {
        checkTypeTree(child, errors);

        if (child->getValType() != "int")
        {
          errors.push_back(string("ERR: ") +
                           to_string(root->getLine()) + ":" +
                           to_string(root->getColumn()) +
                           " --> must have <int> when accessing array");
        }
      }
    }

    if (current_node_type != "int")
    {
      auto type_of_id  = current_symbol_table->deepLookup(string("local_var_decl_") + root->getValType());
      auto type_of_id2 = current_symbol_table->deepLookup(string("var_decl_") + root->getValType());
      current_node_type= type_of_id == "" ? type_of_id2 : type_of_id;

      root->setValType(current_node_type);
    }
    else
    {
      string final_type = "int";

      if (number_of_brackets >= 1)
      {
        final_type.append(" ");

        for (int i = 0; i < number_of_brackets; ++i)
        {
          final_type.append("[]");
        }
      }
      root->setValType(final_type);
    }

  }

}

// SECOND STATE
void buildTypeTree(Node *root, vector <string> &errors)
{
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
        (*it)->symbol_table->insert(string("local_var_decl_" + parameter->getValId()), parameter->getValType());
      }
    }
    else if (current_node_structure == "class_body")
    {
      (*it)->symbol_table = root->symbol_table;
    }
    else if (current_node_structure == "block")
    {
      (*it)->symbol_table = root->symbol_table;
    }
    else if (current_node_structure == "var_decl")
    {
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
    else
    {
      (*it)->symbol_table = root->symbol_table;
    }
    //(*it)->setSymbolTableAddress(scope_sym_table);

    if ((*it)->_children_assgn.size() >= 1)
    {
      buildTypeTree(*it, errors);
    }
    else
    {
      // Nothing to be done here ...
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
    root->symbol_table->dumpSymbolTable();

    auto children = root->_children_assgn;
    for (auto child : children)
    {
      dumpTable(child);
    }
  }
}



#endif
