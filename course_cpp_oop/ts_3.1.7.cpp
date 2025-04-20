#include <iostream>

class Rectangle
{
    int x0{0}, y0{0}, x1{0}, y1{0};

public:
    void get_coords(int &x0, int &y0, int &x1, int &y1) const
    {
        x0 = this->x0;
        y0 = this->y0;
        x1 = this->x1;
        y1 = this->y1;
    }
    void set_coords(int x0, int y0, int x1, int y1)
    {
        this->x0 = x0;
        this->y0 = y0;
        this->x1 = x1;
        this->y1 = y1;
    }
    Rectangle(int x0 = 0, int y0 = 0, int x1 = 0, int y1 = 0) : x0(x0), y0(y0), x1(x1), y1(y1) {}
    Rectangle operator+(const Rectangle &obj)
    {
        int x0 = std::min(this->x0, obj.x0);
        int y0 = std::min(this->y0, obj.y0);
        int x1 = std::max(this->x1, obj.x1);
        int y1 = std::max(this->y1, obj.y1);

        return Rectangle(x0, y0, x1, y1);
    }
};

int main(void)
{
    Rectangle rect_1{-5, 0, 10, 12}, rect_2{1, -2, 7, 14};
    Rectangle res = rect_1 + rect_2;
}