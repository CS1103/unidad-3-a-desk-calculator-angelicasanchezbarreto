//
// Created by lica-pc on 10/29/19.
//

double Parser::term(bool get)
{
    double left = prim(get); // multiply and divide
    for (;;) { //infinite loop (while(true))
        switch (ts.current().kind) { //se ejecuta mientras se encuentren * o /
            case Kind::mul:
                left *= prim(true);
                break; //salir del switch
            case Kind::div:
                if (auto d = prim(true)) {
                    left /= d;
                    break;
                }
                return Error::error("divide by 0");
            default:
                return left;
        }
    }
}


double Parser::expr(bool get)
{
    double left = term(get); // add and subtract
    for (;;) { //infinite loop (while(true))
        switch (ts.current().kind) { //se ejecuta mientras se encuentren + o -
            case Kind::plus:
                left += term(true);
                break;
            case Kind::minus:
                left -= term(true);
                break;
            default:
                return left;
        }
    }
}



// handling a primary is much like expr() and term()
// except that because we are getting lower in the call hierarchy
// a bit of real work is being done and no loop is necessary
double Parser::prim(bool get) // handle primar ies
{
    if (get) ts.get(); // read next token
    switch (ts.current().kind) {
        case Kind::number: // floating-point constant
        {
            double v = ts.current().number_value;
            ts.get();
            return v;
        }
        case Kind::name:
        {
            double& v = Table::table[ts.current().string_value]; // find the corresponding
            if (ts.get().kind == Kind::assign) v = expr(true); // ’=’ seen: assignment
            return v;
        }
        case Kind::minus: // unary minus
            return -prim(true);
        case Kind::lp:
        {
            auto e = expr(true);
            if (ts.current().kind != Kind::rp) return Error::error("')' expected");
            ts.get(); // eat ’)’
            return e;
        }
        default:
            return Error::error("primary expected");
    }
}