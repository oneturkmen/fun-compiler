#include <FlexLexer.h>

int main () {
    
    yyFlexLexer theScanner;
    int rtn;
    
    // initialization code
    
    while ((rtn = theScanner.yylex()) != 0) {
        // loop code goes here        
    }
    
    // more code
    
    return 0;
}
