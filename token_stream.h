//
// Created by lica-pc on 10/17/19.
//246 pag
//399

#include <iostream>
#include <map>
#include "token.h"

using namespace std;

#ifndef CALCULATOR_PARSER_H
#define CALCULATOR_PARSER_H


//encapsulates the reading of characters and their
//composition into Tokens.

//it turns streams of characters
class Token_stream {
public:
    explicit Token_stream(istream& s) : ip{&s}, owns{false} { }
    explicit Token_stream(istream* p) : ip{p}, owns{true} { }
    ~Token_stream() { close(); }
    Token get();
    Token& current();
    void set_input(istream& s) { close(); ip = &s; owns=false; }
    void set_input(istream* p) { close(); ip = p; owns = true; }


private:
    void close() { if (owns) delete ip; }
    istream* ip;
    bool owns;
    Token ct {Kind::end};
};

Token_stream ts (cin);


#endif //CALCULATOR_PARSER_H
