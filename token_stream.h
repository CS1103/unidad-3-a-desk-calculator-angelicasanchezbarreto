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
    Token get(); // read and return next token
    Token& current(); // most recently read token
    void set_input(istream& s) { close(); ip = &s; owns=false; }
    void set_input(istream* p) { close(); ip = p; owns = true; }
private:
    void close() { if (owns) delete ip; }

    //pointer to an input stream
    //initialize the token_stream
    //from where the token_stream gets the characters
    istream* ip;

    //does the Token_stream own the istream?
    //indicating ownership of the input stream
    bool owns;

    //current token
    //I chose Kind::end as the initial value for ct so
    //that a program that misuses current()
    // will not get a value that wasn’t on the input stream.
    Token ct {Kind::end};
};

Token_stream ts (cin);


#endif //CALCULATOR_PARSER_H
