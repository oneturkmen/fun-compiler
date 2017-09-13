#include <iostream>
#include <iomanip>
#include <FlexLexer.h>

using namespace std;

int main () {

    yyFlexLexer theScanner;
    int rtn;

    // initialization code

    while ((rtn = theScanner.yylex()) != 0) {
      // loop code
    }

    return 0;
}
