
#include "token_stream.cpp"
#include "parser.cpp"
using namespace std;
using namespace Table;
using namespace Error;
using namespace Driver;

//to do setup and error reporting
//returns zero if the program terminates normally
//and nonzero otherwise

int main() {
    table["pi"] = 3.1415926535897932385;
    table["e"] = 2.7182818284590452354;
    calculate();
    return no_of_Errors;
    return 0;
}

