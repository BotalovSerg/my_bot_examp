#include <iostream>
#include <cmath>

template <typename A, typename B, typename C>
auto tr_square(A a, B b, C c)
{
    auto p = (a + b + c) / 2.0;
    return sqrt(p * (p - a) * (p - b) * (p - c));
}

class Point
{
    double x{0}, y{0};

public:
    Point(double x = 0, double y = 0) : x(x), y(y)
    {
    }
    void get_coords(double &x, double &y) const
    {
        x = this->x;
        y = this->y;
    }
};

class Vector
{
    int x{0}, y{0};

public:
    Vector(int x = 0, int y = 0) : x(x), y(y)
    {
    }
    void get_coords(int &x, int &y) const
    {
        x = this->x;
        y = this->y;
    }
};

template <typename O, typename T = double>
T sum_coords(const O &obj)
{
    T x, y;
    obj.get_coords(x, y);
    return x + y;
}

int main()
{
    auto res_1 = tr_square(10, 6, 8);
    auto res_2 = tr_square(5.3, 2.7, 7);
    auto res_3 = tr_square(90, 'a', 55.4);

    Point p{10.5, -4.7};
    double sm1 = sum_coords<Point>(p);

    Vector v{132, 55};
    int sm2 = sum_coords<Vector, int>(v);

    // __ASSERT_TESTS__

    return 0;
}