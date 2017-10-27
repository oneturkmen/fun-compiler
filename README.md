# fun-compiler
Repository for COSC 4785 Compiler Construction course at University of Wyoming

List and purpose of each assignment (listed in order):

1. Play and experiment with *flex* to introduce yourself with it.
2. Implement the scanner for **Decaf**\* using **Flex**\*\*,
3. Implement the grammar (only part of it) for **Decaf** using **Bison**\*\*\*.

### Scanner

Run in order:

1. `flex++ --warn program1.lpp`
2. `g++ --dbgg program1.cpp program1_lex.cpp`
3. `./a.out`

### Parser

Run in order:

1. `bison --report=state -W -d program3.y`
2. `flex++ --warn program3.lpp`
3. `g++ -ggdb -std=c++11 -Wall program3.cpp program3_lex.cpp program3.tab.c -o program3`
4. `./program3`

### Notes

\*     : **Decaf** is the strongly-typed object-oriented language with support for inheritance and encapsulation.

\*\*   : **Flex** is the lexical analyzer (.l or .lpp file extension)

\*\*\* : **Bison** is the syntactic analyzer, formerly know as **yacc** (.y or .yy file extension). Compatible with **yacc**.
