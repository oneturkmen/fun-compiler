#include <iostream>
#include <iomanip>
#include <FlexLexer.h>
using namespace std;

/* -- -- -- -- -- -- -- -- */

int column;

void printMetaRow() {
  std::cout << "Line";
  std::cout << std::setw(10) << "Column";
  std::cout << std::setw(10) << "Type";
  std::cout << std::setw(10) << "Length";
  std::cout << std::setw(10) << "Value" << std::endl;
}

/* -- -- -- MAIN -- -- -- */

int main() {

  yyFlexLexer theScanner;
  int rtn;

  // initialization code
  bool init = 0;

  int type;

  // start parsing

  while ((rtn=theScanner.yylex()) != 0) {

    if (!init) {
      printMetaRow();
      init = 1;
    }

    // skip newlines
    if (rtn - 1 == 8) continue;

    // calculate the correct column number
    int correct_column_no = abs(column - theScanner.YYLeng()) + 1;

    // print results
    cout << std::setw(8)  << left << theScanner.lineno();
    cout << std::setw(12) << left << correct_column_no;
    cout << std::setw(8)  << left << rtn - 1;
    cout << std::setw(11) << left << theScanner.YYLeng();
    cout << std::setw(10) << left << theScanner.YYText();

    cout << endl;
  }

  return 0;
}
