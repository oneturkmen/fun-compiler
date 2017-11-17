/**
  Program 4, program4.hpp
  Purpose: tree and error reports class definitions

  @author Batyr Nuryyev
  @date   11/01/2017
*/


#ifndef OHMYLIFE
#define OHMYLIFE

#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>

using namespace std;


// FIXME : just a draft - to be edited.
class SymbolTable {  
  public:
    // { Name -> Type } mapping
    unordered_map <string, string> symbol_table;
    string associated_type;
    SymbolTable *prev;


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
      auto found = symbol_table.find(name);

      cout << "Processing insertion into ST ..." << endl;

      if (found != symbol_table.end())
      {
        cerr << "Element is already in the system ..." << endl;
        return 0;
      }
      else
      {

        cout << "Insertion successful!" << endl;

        symbol_table.insert({name, type});
        return 1;
      }
    }

    // FIXME
    // lookup a value of a key in the table
    string lookup(string key)
    {
      auto value = symbol_table.find(key);

      cout << "Processing lookup ..." << endl;

      if (value != symbol_table.end())
      {
        cout << "Found: " << value->second << endl;
      }
      else
      {
        if (prev != NULL) {

          cout << "Checking parent symbol table ..." << endl;

          return prev->lookup(key);
        }
        else {
          cerr << "Element not found ..." << endl;
          return "";
        }
      }
    }

    // other custom function
    void setType(string type)
    {
      associated_type = type;
    }

    string getType()
    {
      return associated_type;
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
    string _oper;
    string _iden;
    string _numb;
    string _keyw;
    string _type;
    string _structure_type;
    Node *_left;
    Node *_right;
    SymbolTable *symbol_table;
    // Vector for several expressions in NewExpression pattern
    vector <Node*> _children_assgn;

    // - - - - - - - - - - - - - - - - - - - - - - - - -

    // Initialization constructors
    Node()
    { }

    Node(Node *left, Node *right)
      : _left(left), _right(right) { }

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
      _type = type;
    }

    void setValNum(string numb)
    {
      _numb = numb;
    }

    void setValId(string iden)
    {
      _iden = iden;
    }

    void setValProd(string prod)
    {
      _prod = prod;
    }

    void setValKeyw(string keyw)
    {
      _keyw = keyw;
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

    void setError()
    {
      _error = true;
    }

    string getStructureType()
    {
      return _structure_type;
    }

    string getValProd()
    {
      return _prod;
    }

    string getValType()
    {
      return _type;
    }

    string getValId()
    {
      return _iden;
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

          // Print every production rule
          // Mostly expression because of NewExpression rule
          // if ((*it)->getValProd() != "") {
          //   *out << (*it)->getValProd();
          //   *out << endl;
          // }
          if (*it) {
            (*it)->print(out);
          }
          //
          // if ((*it)->_left) ((*it)->_left)->print(out);
          // if ((*it)->_right) ((*it)->_right)->print(out);

          ++it;
        }
      }

      return;
    }
};


#endif
