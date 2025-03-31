#include <iostream>

class Figure
{
    int x0{0}, y0{0}, x1{0}, y1{0};

    Figure(const Figure &other) = default;
    const Figure &operator=(Figure &other)
    {
        x0 = other.x0;
        y0 = other.y0;
        x1 = other.x1;
        y1 = other.y1;
    }

public:
    Figure(int a = 0, int b = 0, int c = 0, int d = 0) : x0(a), y0(b), x1(c), y1(d) {}
    void get_data(int &x0, int &y0, int &x1, int &y1)
    {
        x0 = this->x0;
        y0 = this->y0;
        x1 = this->x1;
        y1 = this->y1;
    }
};

int main(void)
{
    Figure fig(-4, 2, 11, 7);
    return 0;
}