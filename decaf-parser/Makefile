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

program6: program6.tab.c program6.tab.h program6_lex.cpp program6.cpp program6.hpp program6_typecheck.hpp
	$(CXX) $(CXXFLAGS) program6.cpp program6.tab.c program6_lex.cpp -o program6

program6.tab.c : program6.y program6.hpp
	$(YACC) $(YFLAGS) program6.y

program6_lex.cpp: program6.lpp program6.hpp
	$(LEXXX) $(LFLAGS) program6.lpp
