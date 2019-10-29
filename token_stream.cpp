//
// Created by lica-pc on 10/17/19.
//

#include "token_stream.h"
#include "namespaces.h"
using namespace Parser; //para la funcion expr en la funcion calculate

#include <cctype>

//read a character, use that character to decide
//what kind of token needs to be compose
//read more characters when needed, and then return a Token

Token Token_stream::get() {
    char ch;
    do {
        if (!ip->get(ch)) return ct={Kind::end};
    } while (ch!='\n' && isspace(ch));
    switch (ch) {
        case ';':
        case '\n':
            return ct = {Kind::print};
        case '*':
        case '/':
        case '+':
        case '-':
        case '(':
        case ')':
        case '=':
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

