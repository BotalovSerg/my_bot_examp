#include <iostream>

class LimitLength
{
    enum
    {
        min_length = -10,
        max_length = 10
    }; // границы допустимых значений
    int length{0}; // текущее значение
public:
    LimitLength(int len = 0)
    {
        if (len < min_length)
        {
            length = min_length;
        }
        else if (len > max_length)
        {
            length = max_length;
        }
        else
        {
            length = len;
        }
    }
    int operator++() { return ++length; }
    int operator++(int) { return length++; }
    int operator--() { return --length; }
    int operator--(int) { return length--; }
    int operator+=(int value)
    {
        length += value;
        return length;
    }
    int operator-=(int value)
    {
        length -= value;
        return length;
    }
    int operator*=(int value)
    {
        length *= value;
        return length;
    }
    int operator/=(int value)
    {
        length /= value;
        return length;
    }
    int get_length() const { return length; }
};

int main(void)
{

    LimitLength lm1 = -5;
    int a = lm1++;
    int b = ++lm1;
    int c = lm1--;
    int d = --lm1;
    int res_1 = lm1 += 5;
    int res_2 = lm1 -= 15;
    int res_3 = lm1 *= 2;
    int res_4 = lm1 /= 3;

    return 0;
}