# Compiler front-end for the Decaf Language

Decaf is a strongly-typed, object-oriented language with support for inheritance and encapsulation. It has many similarities with C/C++/Java.

Built lexical analyzer, parser, type checker for the *Compiler Construction I* class at University of Wyoming.

### Check it out!

Run in order, manually:

1. `bison --report=state -W -d program3.y`
2. `flex++ --warn program3.lpp`
3. `g++ -ggdb -std=c++11 -Wall program3.cpp program3_lex.cpp program3.tab.c -o program3`
4. `./program3`

Or, with a Makefile

`make`

### Notes

\*     : **Decaf** is the strongly-typed object-oriented language with support for inheritance and encapsulation.

\*\*   : **Flex** is the lexical analyzer (.l or .lpp file extension)

\*\*\* : **Bison** is the syntactic analyzer, formerly know as **yacc** (.y or .yy file extension). Compatible with **yacc**.
