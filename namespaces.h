//
// Created by lica-pc on 10/29/19.
//

#ifndef CALCULATOR_NAMESPACES_H
#define CALCULATOR_NAMESPACES_H


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


namespace Parser {
    double term(bool);
    double expr(bool);
    double prim(bool);
}


#endif //CALCULATOR_NAMESPACES_H
