#include <iostream>

class Complex
{
    short re{0}, im{0};

public:
    Complex(int re) : re(re), im(0) {}
    Complex(short re = 0, short im = 0) : re(re), im(im) {}
    Complex(const Complex &other)
    {
        this->re = static_cast<short>(std::abs(other.re));
        this->im = static_cast<short>(std::abs(other.im));
    }
    short real()
    {
        return re;
    }
    short imag()
    {
        return im;
    }
};

int main(void)
{

    Complex digit{-4, 7};
    Complex res{digit};
    Complex d; // re=0, im=0
    Complex d = 5; // re=5, im=0
    Complex d(1, -6); // re=1, im=-6

    return 0;
}