#include <iostream>

template <typename T>
class Vector2D
{
    T x{0}, y{0};

public:
    T get_x() const { return x; }
    T get_y() const { return y; }
    void set_xy(T a, T b)
    {
        x = a;
        y = b;
    }
    Vector2D() {}
    Vector2D(T a, T b) : x(a), y(b) {}
};

int main()
{
    Vector2D<int> v1;
    Vector2D v2(1, 2);

    Vector2D<double> vector(-54.2, 10.8);


    // __ASSERT_TESTS__
    return 0;
}