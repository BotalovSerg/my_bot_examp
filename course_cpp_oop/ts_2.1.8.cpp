#include <iostream>

struct Point
{
    short x, y;
};

class Line
{
    short x0, y0, x1, y1;

public:
    Line(short a = 0, short b = 0, short c = 0, short d = 0) : x0(a), y0(b), x1(c), y1(d) {}
    Line(Point sp, Point ep)
    {
        x0 = sp.x;
        y0 = sp.y;
        x1 = ep.x;
        y1 = ep.y;
    }
    void set_coords(short a, short b, short c, short d)
    {
        x0 = a;
        y0 = b;
        x1 = c;
        y1 = d;
    }
    void set_coords(Point sp, Point ep)
    {
        x0 = sp.x;
        y0 = sp.y;
        x1 = ep.x;
        y1 = ep.y;
    }
    Point get_start()
    {
        Point p{x0, y0};
        return p;
    }
    Point get_end()
    {
        Point p{x1, y1};
        return p;
    }
};
int main(void)
{
    Point sp, ep;
    short a, b, c, d;

    std::cin >> a >> b >> c >> d;
    std::cin >> sp.x >> sp.y >> ep.x >> ep.y;

    Line *ptr_ln1 = new Line(a, b, c, d);
    Line *ptr_ln2 = new Line(sp, ep);

    Point r_s1 = ptr_ln1->get_start();
    Point r_e1 = ptr_ln1->get_end();
    Point r_s2 = ptr_ln2->get_start();
    Point r_e2 = ptr_ln2->get_end();

    printf("%hd %hd %hd %hd %hd %hd %hd %hd", r_s1.x, r_s1.y, r_e1.x, r_e1.y, r_s2.x, r_s2.y, r_e2.x, r_e2.y);

    // __ASSERT_TESTS__ // макроопределение для тестирования (не убирать и должно идти непосредственно перед return 0 или перед освобождением памяти)

    delete ptr_ln1;
    delete ptr_ln2;

    return 0;
}