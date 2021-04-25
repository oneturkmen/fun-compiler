#
# $Author: Batyr Nuryyev$
# $Date  : Dec 8, 2017$
#
#
###############################################################

CXX=g++
CXXFLAGS=-ggdb -std=c++11 -Wall
YACC=bison
YFLAGS=--report=state -W -d
LEX=flex
LEXXX=flex++
LFLAGS=--warn

main: main.tab.c main.tab.h main_lex.cpp main.cpp main.hpp typechecker.hpp
	$(CXX) $(CXXFLAGS) main.cpp main.tab.c main_lex.cpp -o main

main.tab.c : main.y main.hpp
	$(YACC) $(YFLAGS) main.y

main_lex.cpp: main.lpp main.hpp
	$(LEXXX) $(LFLAGS) main.lpp
