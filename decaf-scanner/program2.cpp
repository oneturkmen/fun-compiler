#include <iostream>
#include <iomanip>
#include <FlexLexer.h>
using namespace std;

/* -- -- -- -- -- -- -- -- */
int column;
char err_char;

void printMetaRow() {
  cout << "Line";
  cout << setw(10) << "Column";
  cout << setw(10) << "Token";
  cout << setw(10) << "Value";
  cout << endl;
}

/* -- -- -- MAIN -- -- -- */

int main() {

  yyFlexLexer theScanner;
  int rtn;

  // initialization code
  bool init = 0;
  int error_count = 0;

  int type;

  // start parsing

  while ((rtn=theScanner.yylex()) != 0) {

    if (!init) {
      printMetaRow();
      init = 1;
    }

    // skip newlines and whitespaces
    if (rtn == 1) continue;
    if (rtn == 10) continue;

    // calculate the correct column number
    int correct_column_no = abs(column - theScanner.YYLeng()) + 1;

    // print results
    cout << setw(8)  << left << theScanner.lineno();
    cout << setw(11) << left << correct_column_no;
    cout << setw(10) << left << rtn - 1;

    // do not print keyword
    if (error_count >= 20) {
      cout << "Too many errors! Terminating." << endl;
      return 0;
    }
    else if (rtn == 8) {
      cout << setw(12) << left << " ";
    }
    // print error and character that starts it
    else if (rtn == 1000) {
      error_count++;
      cout << left << err_char << theScanner.YYText();
    }
    // everything else
    else {
      cout << setw(12) << left << theScanner.YYText();
    }

    cout << endl;
  }

  return 0;
}
