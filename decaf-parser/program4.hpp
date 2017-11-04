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

using namespace std;


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
    Node *_left;
    Node *_right;
    // Vector for several expressions in NewExpression pattern
    vector <Node*> _children_assgn;

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
    void setLeft(Node *left)
    {
      _left = left;
    }

    void setRight(Node *right)
    {
      _right = right;
    }

    void setValOp(string oper)
    {
      _oper = oper;
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

    void setError()
    {
      _error = true;
    }

    string getValProd()
    {
      return _prod;
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
