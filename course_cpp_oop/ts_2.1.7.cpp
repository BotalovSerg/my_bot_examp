#include <iostream>

class TriangleChecker
{
    int a, b, c;

public:
    TriangleChecker(int a = 0, int b = 0, int c = 0) : a(a), b(b), c(c)
    {
    }
    int is_triangle()
    {
        if (a <= 0 || b <= 0 || c <= 0)
        {
            return 1;
        }
        if (a > b + c || b > a + c || c > a + b)
        {
            return 2;
        }
        return 3;
    }
};