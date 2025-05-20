#include <iostream>

class Line
{
    short x0{0}, y0{0}, x1{0}, y1{0};
    int color{0};

public:
    Line() {}
    Line(short x0, short y0, short x1, short y1) : x0(x0), y0(y0), x1(x1), y1(y1) {}
    Line(const Line &other)
    {
        this->set_coords(other.x0, other.y0, other.x1, other.y1);
    }
    int get_color() const { return color; }
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
    void set_color(int color)
    {
        this->color = color;
    }
    Line &operator+=(const Line &other)
    {
        this->x0 += other.x0;
        this->y0 += other.y0;
        this->x1 += other.x1;
        this->y1 += other.y1;
        return *this;
    }
    Line &operator-=(const Line &other)
    {
        this->x0 -= other.x0;
        this->y0 -= other.y0;
        this->x1 -= other.x1;
        this->y1 -= other.y1;
        return *this;
    }
    Line &operator*=(const Line &other)
    {
        this->x0 *= other.x0;
        this->y0 *= other.y0;
        this->x1 *= other.x1;
        this->y1 *= other.y1;
        return *this;
    }
    Line operator+(const Line other)
    {
        Line temp(
            this->x0 + other.x0,
            this->y0 + other.y0,
            this->x1 + other.x1,
            this->y1 + other.y1);
        return temp;
    }
    const Line &operator=(const Line &other)
    {
        if (this == &other)
            return other;
        this->x0 = other.x0;
        this->y0 = other.y0;
        this->x1 = other.x1;
        this->y1 = other.y1;
        return *this;
    }
};

int main(void)
{
    Line ln_1, ln_2(1, 2, 3, 4);
    Line ln_new(1, 1, 2, 2);
    ln_1 = ln_2;              // копирование только координат x0, y0, x1, y1 (поле color не копируется)
    ln_new += ln_1;           // суммирование только для координат для объекта ln_new (поле color без изменений)
    ln_1 -= ln_2;             // вычитание только для координат для объекта ln_1 (поле color без изменений)
    ln_new *= ln_2;           // умножение только для координат для объекта ln_new (поле color без изменений)
    Line res = ln_new + ln_2; // сложение соответствующих координат объектов ln_new, ln_2 и присваивание результата объекту res
    return 0;
}