#include <iostream>

class Rectangle
{
private:
    short x0{0}, y0{0}, x1{0}, y1{0};
    int border_color{0};
    int fill_color{255};

public:
    Rectangle() = default;
    Rectangle(short var_1, short var_2, short var_3, short var_4) : x0(var_1), y0(var_2), x1(var_3), y1(var_4) {}
    int get_border_color() const
    {
        return this->border_color;
    }
    int get_fill_color() const
    {
        return this->fill_color;
    }
    void get_coords(short &x0, short &y0, short &x1, short &y1) const
    {
        x0 = this->x0;
        y0 = this->y0;
        x1 = this->x1;
        y1 = this->y1;
    }
    void set_coords(short x0, short y0, short x1, short y1)
    {
        this->x0 = x0;
        this->y0 = y0;
        this->x1 = x1;
        this->y1 = y1;
    }
    void set_border_color(int color)
    {
        this->border_color = color;
    }
    void set_fill_color(int color)
    {
        this->fill_color = color;
    }
    Rectangle &operator=(const Rectangle &other)
    {
        if (this == &other)
        {
            return *this;
        }
        if (border_color == other.border_color)
        {
            return *this;
        }
        if (fill_color == other.fill_color)
        {
            return *this;
        }
        x0 = other.x0;
        y0 = other.y0;
        x1 = other.x1;
        y1 = other.y1;

        return *this;
    }
};