#include <iostream>

class Operator
{
    int type{0};
    short operation{-1};
    Operator() = default;
    Operator(Operator &other)
    {
        type = other.type;
        operation = other.operation;
    }

public:
    void set_state(int t, short o)
    {
        type = t;
        operation = o;
    }
    void get_state(int &t, short &o)
    {
        t = type;
        o = operation;
    }
    static Operator *create();
};

Operator *Operator::create()
{
    Operator *ptr = new Operator;
    return ptr;
}
