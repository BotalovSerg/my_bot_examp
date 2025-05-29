#include <iostream>

class LineDouble
{
private:
    double x0{0}, y0{0}, x1{0}, y1{0};

public:
    LineDouble() {};
    LineDouble(double a, double b, double c, double d) : x0(a), y0(b), x1(c), y1(d) {};

    void set_coords(double a, double b, double c, double d)
    {
        x0 = a;
        y0 = b;
        x1 = c;
        y1 = d;
    }
    void get_coords(double &a, double &b, double &c, double &d) const
    {
        a = x0;
        b = y0;
        c = x1;
        d = y1;
    }
    LineDouble operator+(const LineDouble &other)
    {
        LineDouble obj(
            this->x0 + other.x0,
            this->y0 + other.y0,
            this->x1 + other.x1,
            this->y1 + other.y1);
        return obj;
    }
    LineDouble &operator+=(double value)
    {
        this->x0 += value;
        this->y0 += value;
        this->x1 += value;
        this->y1 += value;

        return *this;
    }
    LineDouble &operator-=(double value)
    {
        this->x0 -= value;
        this->y0 -= value;
        this->x1 -= value;
        this->y1 -= value;

        return *this;
    }
    LineDouble &operator+=(const LineDouble &other)
    {
        this->x0 += other.x0;
        this->y0 += other.y0;
        this->x1 += other.x1;
        this->y1 += other.y1;
        return *this;
    }
    LineDouble &operator-=(const LineDouble &other)
    {
        this->x0 -= other.x0;
        this->y0 -= other.y0;
        this->x1 -= other.x1;
        this->y1 -= other.y1;
        return *this;
    }
    void operator++()
    {
        this->x0 += 0.1;
        this->y0 += 0.1;
        this->x1 += 0.1;
        this->y1 += 0.1;
    }
    void operator++(int) { ++(*this); }
    void operator--()
    {
        this->x0 -= 0.1;
        this->y0 -= 0.1;
        this->x1 -= 0.1;
        this->y1 -= 0.1;
    }
    void operator--(int) { --(*this); }
};

int main(void)
{
    LineDouble ln1(1, 2, 3, 4), ln2(10, 20, 30, 40);
    LineDouble ln = ln1 + ln2;   // сложение соответствующих координат между собой (объекты ln1, ln2 не меняются)
    LineDouble r_1 = ln1 += 1.5; // к каждой координате прибавляется значение 1.5
    LineDouble r_2 = ln2 -= 0.1; // от каждой координаты вычитается значение 0.1
    LineDouble r_3 = ln2 += ln1; // сумма соответствующих координат с сохранением результата в объекте ln2
    LineDouble r_4 = ln1 -= ln2; // разность соответствующих координат с сохранением результата в объекте ln1
    ln1++;                       // увеличение каждой координаты на 0.1
    ++ln1;                       // увеличение каждой координаты на 0.1
    ln2--;                       // уменьшение каждой координаты на 0.1
    --ln2;                       // уменьшение каждой координаты на 0.1
    return 0;
}
