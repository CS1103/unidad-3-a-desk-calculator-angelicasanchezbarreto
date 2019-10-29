//
// Created by lica-pc on 10/29/19.
//

#include <iostream>
#ifndef CALCULATOR_TOKEN_H
#define CALCULATOR_TOKEN_H

using namespace std;

enum class Kind : char  {
    name, number, end,
    plus='+',
    minus='-',
    mul='*',
    div='/',
    print=';',
    assign='=',
    lp='(',
    rp=')',
    exp='^'
};


struct Token {
    Kind kind;
    string string_value;
    double number_value;
};

#endif //CALCULATOR_TOKEN_H
