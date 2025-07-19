#include <iostream>

class Validator
{
public:
    virtual bool is_valid(int x) { return true; }
};

class PositiveValidator : public Validator
{
public:
    virtual bool is_valid(int x) { return x >= 0; }
};

class RangeValidator : public Validator
{
    int left, right;

public:
    RangeValidator(int l, int r) : left(l), right(r) {}
    virtual bool is_valid(int x)
    {
        return ((x >= left && x <= right) ? true : false);
    }
};

int main(void)
{
    PositiveValidator pv_1;
    RangeValidator rv_1{-5, 5};
    RangeValidator rv_2{-15, 10};
    Validator *vs[3]{&pv_1, &rv_1, &rv_2};
    int x;
    std::cin >> x;
    for (int i = 0; i < 3; i++)
    {
        std::cout << vs[i]->is_valid(x) << ((i == 2) ? '\n' : ' ');
    }

    return 0;
}