//
// Created by lica-pc on 10/29/19.
//

#ifndef CALCULATOR_NAMESPACES_H
#define CALCULATOR_NAMESPACES_H

//when table is indexed by a string , the resulting value is the string
//Example: radius = 6378.388;
//double& v = table["radius"];
// ... expr() calculates the value to be assigned ...
//v = 6378.388;
namespace Table {
    map<string,double> table;
}

namespace Error {
    int no_of_Errors;
    double error(const string& s);
}


namespace Driver {
    void calculate();
}


//Each parser function takes a bool argument called get
//indicating whether the function needs to call
//Token_stream::get() to get the next token.
//Each parser function evaluates ‘‘its’’
//expression and returns the value.
namespace Parser {
    double term(bool); //suma y resta
    double expr(bool);
    double prim(bool);
}


#endif //CALCULATOR_NAMESPACES_H
