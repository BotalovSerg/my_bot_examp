#include <iostream>

class LengthValueError : public std::exception
{
protected:
    std::string msg;

public:
    LengthValueError(std::string m) noexcept : msg(m) {}
    virtual ~LengthValueError() {}
    const char *what() const noexcept override { return msg.c_str(); }
};

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

template <typename T = short>
class Triangle
{
    T a{0}, b{0}, c{0};

public:
    void get_abc(T &a, T &b, T &c) const
    {
        a = this->a;
        b = this->b;
        c = this->c;
    }
    void set_abc(T a, T b, T c)
    {
        if (a < 0 || b < 0 || c < 0)
        {
            throw LengthValueError("Length must be a positive number.");
        }

        this->a = a;
        this->b = b;
        this->c = c;
    }
    Triangle() {}
    Triangle(T a, T b, T c)
    {
        set_abc(a, b, c);
    }
};

template <typename T>
struct Point
{
    T x{0}, y{0};
    Point(T x = 0, T y = 0) : x(x), y(y) {}
};

template <typename D>
class Line
{
    Point<D> sp, ep;

public:
    Point<D> get_sp() const { return sp; }
    Point<D> get_ep() const { return ep; }
    void set_coords(Point<D> p1, Point<D> p2)
    {
        sp = p1;
        ep = p2;
    }
    Line() {}
    Line(Point<D> sp, Point<D> ep) : sp(sp), ep(ep) {}
    Line(D x0, D y0, D x1, D y1) : Point<D>(x0, y0), Point<D>(x1, y1) {}
};

int main()
{
    Line<unsigned> line(Point<unsigned>(1, 2), Point<unsigned>(11, 54));

    Vector2D<int> v1;
    Vector2D v2(1, 2);

    Vector2D<double> vector(-54.2, 10.8);

    Triangle tr1; // T = short; a = b = c = 0
    Triangle<int> tr2(1, 2, 3);

    try
    {
        Triangle<int> tr(7, -4, 10);
    }
    catch (const LengthValueError &e)
    {
        std::cout << e.what() << '\n';
    }

    // __ASSERT_TESTS__
    return 0;
}