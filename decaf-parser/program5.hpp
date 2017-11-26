/**
  Program 5, program5.hpp
  Purpose: tree and error reports class definitions

  @author Batyr Nuryyev
  @date   11/26/2017
*/


#ifndef OHMYLIFE
#define OHMYLIFE

#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>

using namespace std;

typedef unordered_map <string, string> map_s_to_s;

// FIXME : just a draft - to be edited.
class SymbolTable {
  public:
    // { Name -> Type } mapping
    unordered_map <string, string> in_symbol_table;
    string scope_type;
    string scope_name;
    bool if_printed = false;
    SymbolTable *prev;
    vector < SymbolTable* > classes_sts;
    int num_of_statement_blocks = 0;


    SymbolTable() { }

    ~SymbolTable() { }

    // initialize a prev symbol table
    SymbolTable(SymbolTable *parent)
    {
      prev = parent;
    }

    // insert a variable/method declar
    bool insert(string name, string type)
    {
      if (type == "statement_block") ++num_of_statement_blocks;

      in_symbol_table.insert({name, type});

      return 1;
    }

    // FIXME
    // lookup a value of a key in the table
    string lookup(string key)
    {
      auto value = in_symbol_table.find(key);

      if (value != in_symbol_table.end())
      {
        return value->second;
      }
      else
      {
        return "";
      }
    }

    string deepLookup(string key)
    {
      auto value = in_symbol_table.find(key);

      if (value != in_symbol_table.end())
      {
        return value->second;
      }
      else
      {
        if (prev != NULL)
        {
          return prev->deepLookup(key);
        }
        else
        {
          return "";
        }
      }
    }

    // TODO : Do I really need it?
    // string deepLookup(string key, string target_scope_type)
    // {
    //   if (target_scope_type == scope_type)
    //   {
    //     string x = c->lookup(string("var_decl_") + key);
    //   }
    //   else if (prev == NULL)
    //   {
    //     return "";
    //   }
    //   else
    //   {
    //     prev->deepLookup(key, target_scope_type);
    //   }
    // }
    SymbolTable* getCurrentClass()
    {
      if (scope_type == "class_decl")
      {
        return this;
      }
      else if (prev == NULL)
      {
        return NULL;
      }
      else
      {
        return prev->getCurrentClass();
      }
    }

    string getCurrentMethodType()
    {
      if (scope_type != "method_decl")
      {
        return "";
      }
      else
      {
        // We will always have prev, i.e. !NULL
        auto method = prev->lookup("method_decl_" + scope_name);

        return method;
      }
    }


    string globalClassLookup(string class_id, string target_entry)
    {
      if (scope_name == "global" && scope_type == "program")
      {
        string x = "";
        for (auto c : classes_sts)
        {
          if (class_id == c->getScopeName())
          {
            x = c->lookup(target_entry);
          }
          if (x != "") return x;
        }
        return "";
      }
      else
      {
        return prev->globalClassLookup(class_id, target_entry);
      }
    }

    // FIXME: DOES NOT PRESERVE THE ORDER IN WHICH ELEMENTS ARE INSERTED
    void dumpSymbolTable()
    {
      if (!if_printed)
      {
        auto it = this->in_symbol_table.begin();

        if (scope_name == "")
        {
          cout << scope_type << endl;
        }
        else
        {
          cout << scope_name << " " << scope_type << endl;
        }

        for (; it != this->in_symbol_table.end(); ++it)
        {
          cout << "   " << it->first << " " << it->second << endl;
        }
        cout << endl;
        if_printed = true;
      }
      else return;
    }

    // other custom function
    void setScopeDefinition(string name, string type)
    {
      scope_name = name;
      scope_type = type;
    }

    void setScopeType(string type)
    {
      scope_type = type;
    }

    void setScopeName(string name)
    {
      scope_name = name;
    }

    string getScopeName()
    {
      return scope_name;
    }

    string getScopeType()
    {
      return scope_type;
    }

    int getNumStmBlocks()
    {
      return num_of_statement_blocks;
    }

    SymbolTable *getParent()
    {
      return prev;
    }


};


struct ReportSyntaxError {
  int column;
  int line;
};


// Lexical error handler
struct ReportError {
  int column = 1;
  int line = 1;

  void addColumn(int l)
  {
    column += l;
  }

  void addLine(int l)
  {
    line += l;
  }

  int getColumnNo()
  {
    return column;
  }

  int getLineNo()
  {
    return line;
  }

};



// Node
class Node {
  public:
    string _prod = "";
    bool   _error = false;
    bool   _is_scope = false;
    string _unary_op = "";
    string _oper = "";
    string _iden = "";
    string _numb = "";
    string _keyw = "";
    string _type = "";
    string _structure_type = "";
    string _return_type = "";
    int _line, _column;
    SymbolTable *symbol_table;
    // Vector for several expressions in NewExpression pattern
    vector <Node*> _children_assgn;

    // - - - - - - - - - - - - - - - - - - - - - - - - -

    // Initialization constructors
    Node()
    { }

    Node(string prod)
      : _prod(prod) { }

    ~Node()
    { }

    // Custom class methods
    void setValOp(string oper)
    {
      _oper = oper;
    }

    void setValType(string type)
    {
      this->_type = type;
    }

    void setValNum(string numb)
    {
      _numb = numb;
    }

    void setValId(string iden)
    {
      this->_iden = iden;
    }

    void setValProd(string prod)
    {
      _prod = prod;
    }

    void setValKeyw(string keyw)
    {
      _keyw = keyw;
    }

    void setNodeScopeType()
    {
      _is_scope = true;
    }

    void setReturnType(string return_type)
    {
      _return_type = return_type;
    }

    void setUnaryOperator(string op)
    {
      _unary_op = op;
    }

    void pushNonTerminal(Node *n)
    {
      _children_assgn.push_back(n);
      return;
    }

    void setStructureType(string structype)
    {
      _structure_type = structype;
    }

    void setSymbolTableAddress(SymbolTable *st)
    {
      symbol_table = st;
    }

    void setLocation(int line, int col)
    {
      _line = line;
      _column = col;
    }

    void setError()
    {
      _error = true;
    }

    bool isItScope()
    {
      return _is_scope;
    }

    string getUnaryOperator()
    {
      return _unary_op;
    }

    int getLine()
    {
      return _line;
    }

    int getColumn()
    {
      return _column;
    }

    string getStructureType()
    {
      return _structure_type;
    }

    string getReturnType()
    {
      return _return_type;
    }

    string getValProd()
    {
      return _prod;
    }

    string getValType()
    {
      return this->_type;
    }

    string getValId()
    {
      return this->_iden;
    }

    string getValNum()
    {
      return _numb;
    }

    string getValOp()
    {
      return _oper;
    }

    bool ifError()
    {
      return _error;
    }

    void print(ostream *out = 0)
    {
      //if (_prod == "") return;

      if (_prod != "") {
        *out << _prod;
        *out << endl;
      }

      /**
       * So, what does the following snippet execute?
       *
       * 1. Check if node has something inside its vector
       * 2. If it does, go and print every node's production inside
       *    vector
       * 3. Then, while printing certain node in vector,
       *  recursively check if the printed node has left or right nodes
       *      3.1 If it does, go print left and right.
       *      3.2 If it does NOT, exit.
       *
       * Example:
       *
       *                  Node A (vector = { A1, A2, A3 })
       *               |           |           |           |
       * Recursively  A1          A2          A3          A4
       *             /  \        /  \        /  \        /  \.
       *          NILL SMTH   NULL SMTH   NULL NULL   NULL NULL
       */
      if (!_children_assgn.empty())
      {
        auto it = _children_assgn.begin();
        while (it != _children_assgn.end())
        {
          if (*it) {
            (*it)->print(out);
          }
          ++it;
        }
      }

      return;
    }
};


#endif
