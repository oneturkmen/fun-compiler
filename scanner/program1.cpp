#include <iostream>
#include <iomanip>
#include <FlexLexer.h>

using namespace std;

int main () {

    yyFlexLexer theScanner;
    int rtn;

    // initialization code

    while ((rtn = theScanner.yylex()) != 0) {
      cout << "Line";
      cout << setw(10) << "Column";
      cout << setw(10) << "Type";
      cout << setw(10) << "Length";
      cout << setw(10) << "Value" << endl;
    }

    return 0;
}
