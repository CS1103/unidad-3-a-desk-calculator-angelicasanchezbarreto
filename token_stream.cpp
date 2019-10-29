//
// Created by lica-pc on 10/17/19.
//

#include "token_stream.h"
#include "namespaces.h"
using namespace Parser; //para la funcion expr en la funcion calculate

#include <cctype>

//llama al sgte token
//read a character, use that character to decide
//what kind of token needs to be compose
//read more characters when needed, and then return a Token
//representing the characters read
Token Token_stream::get() {
    char ch;
    // read individual characters
    do { // skip whitespace except ’\n’
        if (!ip->get(ch)) return ct={Kind::end}; //reads a single character from the input stream ∗ip into ch
        // get() does not skip whitespace the way >> does
        // The test if (!ip−>get(ch)) succeeds if no character can be read from cin
    } while (ch!='\n' && isspace(ch)); // The operator ! (not) is used because get() returns true in case of success
    //std isspace() provides the standard test for whitespace
    //returns a nonzero value if is a whitespace character and zero otherwise
    //is faster than testing for the individual whitespace characters
    //isdigit()//isalpha()//isalnum()
    switch (ch) {
        case ';': // end of expression; print
        case '\n':
            return ct = {Kind::print};
        case '*':
        case '/':
        case '+':
        case '-':
        case '(':
        case ')':
        case '=':
            // The static_cast: there is no implicit conversion from char to Kind
            // only some characters correspond to Kind values
            // so we have to ‘‘certify’’ that in this case ch does.
            return ct={static_cast<Kind>(ch)};
        case '0': case '1': case '2': case '3': case '4': case '5': case '6': case '7': case '8': case '9':
        case '.':
            ip->putback(ch); // put the first digit (or .) back into the input stream
            *ip >> ct.number_value; // read the number into ct
            ct.kind=Kind::number;
            return ct;
        default: // name, name =, or error
            if (isalpha(ch)) {
                ip->putback(ch);
                *ip>>ct.string_value; // put the first character back into the input stream
                ct.kind = Kind::name; // read the string into ct
                return ct;
            }
            Error::error("bad token");
            return ct={Kind::print};
    }
}

//llama al token mas reciente
Token &Token_stream::current() {
    return ct;
}


double Error::error(const string& s){
    no_of_Errors++;
    // cerr is an unbuffered output stream usually used to report errors
    cerr << "error: " << s << '\n';
    return 1;
}

void Driver::calculate() {
    for (;;) {
        ts.get();
        if (ts.current().kind == Kind::end) break;
        if (ts.current().kind == Kind::print) continue;
        cout << expr(false) << '\n';
    }
}
