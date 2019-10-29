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
    rp=')'
};


// A Token is a {kind-of-token,value} pair
// such as {number,123.45}
// where the 123.45 has been turned into a floating point value
struct Token {
    Kind kind;
    string string_value; //al leer un string lo guarda aqui
    double number_value; //al leer un numero(int ,double) lo guarda aqui
};

#endif //CALCULATOR_TOKEN_H
