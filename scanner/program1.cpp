#include <iostream>
#include <FlexLexer.h>

using namespace std;

int main () {
    cout << "/* message */" << '\n';
    yyFlexLexer theScanner;
    int rtn;

    // initialization code

    while ((rtn = theScanner.yylex()) != 0) {}

    return 0;
}
