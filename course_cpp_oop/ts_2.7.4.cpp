#include <iostream>

class Point
{
    static int MIN_COORD;
    static int MAX_COORD;
    int x{0}, y{0};

    bool check_coord(int coord)
    {
        return coord >= MIN_COORD && coord <= MAX_COORD;
    }

public:
    static void set_bounds(int left, int right)
    {
        MIN_COORD = left;
        MAX_COORD = right;
    }
    static void get_bounds(int &left, int &right)
    {
        left = MIN_COORD;
        right = MAX_COORD;
    }
    void set_coords(int x, int y)
    {
        if (check_coord(x) && check_coord(y))
        {
            this->x = x;
            this->y = y;
        }
    }
    int get_x() { return x; }
    int get_y() { return y; }
    Point() = default;
    Point(int x, int y)
    {
        set_coords(x, y);
    }
};

int Point::MIN_COORD = 0;
int Point::MAX_COORD = 10;

int main(void)
{
    Point::set_bounds(-100, 100);
    Point pt{-5, 7};

    // __ASSERT_TESTS__ 
    
    return 0;
}