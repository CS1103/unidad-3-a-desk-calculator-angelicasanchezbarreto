//
// Created by lica-pc on 10/29/19.
//

double Parser::term(bool get)
{
    double left = prim(get);
    for (;;) { //infinite loop (while(true))
        switch (ts.current().kind) { //se ejecuta mientras se encuentren * o /
            case Kind::mul:
                left *= prim(true);
                break;
            case Kind::exp:
                left *=prim(true);
                break;
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
    double left = term(get);
    for (;;) {
        switch (ts.current().kind) {
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

double Parser::prim(bool get)
{
    if (get) ts.get();
    switch (ts.current().kind) {
        case Kind::number:
        {
            double v = ts.current().number_value;
            ts.get();
            return v;
        }
        case Kind::name:
        {
            double& v = Table::table[ts.current().string_value];
            if (ts.get().kind == Kind::assign) v = expr(true);
            return v;
        }
        case Kind::minus:
            return -prim(true);
        case Kind::lp:
        {
            auto e = expr(true);
            if (ts.current().kind != Kind::rp) return Error::error("')' expected");
            ts.get();
            return e;
        }
        default:
            return Error::error("primary expected");
    }
}
