#include <iostream>

class SquareValue
{
    unsigned value{0};

public:
    SquareValue() {}
    SquareValue(int v)
    {
        value = v * v;
    }
    operator unsigned() { return value; }
    SquareValue &operator=(int v)
    {
        this->value = v * v;
        return *this;
    }
};

int main(void)
{

    SquareValue v1;       // value = 0
    SquareValue v2 = 10;  // value = 100 (квадрат числа: 10*10 = 100)
    SquareValue v3 = -50; // value = 2500 (квадрат числа: (-50)*(-50) = 2500)

    v1 = -11;          // value = 121 (присваивается квадрат числа)
    v2 = 7;            // value = 49
    unsigned res = v3; // возвращает значение поля value

    SquareValue objSq{9};
    SquareValue &lnk_sq = objSq;
    SquareValue &&lnk_r_sq = std::move(objSq);
    return 0;
}