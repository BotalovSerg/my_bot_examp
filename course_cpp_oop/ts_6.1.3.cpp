#include <iostream>
#include <cmath>

enum ar_operation
{
    ar_sum = 1, // сложение
    ar_sub = 2, // вычитание
    ar_mul = 3  // умножение
};

template <typename T>
T perimetr(T width, T height)
{
    return 2 * (width + height);
}

template <typename T>
T min_3(T a, T b, T c)
{
    return std::min(a, std::min(b, c));
}

template <typename T>
double hypot(T a, T b)
{
    return sqrt(pow(a, 2) + pow(b, 2));
}

template <typename AR>
AR ar_sum_positive(AR *list, size_t size)
{
    AR tmp = 0;
    for (size_t i = 0; i < size; i++)
    {
        if (list[i] > 0)
        {
            tmp += list[i];
        }
    }
    return tmp;
}

// template <typename T>
// T calc_data(T a, T b, ar_operation type = ar_sum)
// {
//     switch (type)
//     {
//     case ar_sum:
//         return a + b;
//     case ar_operation::ar_sub:
//         return a - b;
//     case ar_mul:
//         return a * b;
//     default:
//         throw "Invalid enum!";
//     }
// }

template <typename T>
T calc_data(T a, T b, ar_operation type = ar_sum)
{

    if (type == ar_sub)
    {
        return a - b;
    }
    else if (type == ar_mul)
    {
        return a * b;
    }

    return a + b;
}

class Complex
{
    int re{0}, im{0};

public:
    int real() const { return re; }
    int imag() const { return im; }
    void set_value(int real, int imag)
    {
        re = real;
        im = imag;
    }
    Complex(int re = 0, int im = 0) : re(re), im(im) {}
    Complex operator+(const Complex &other)
    {
        return Complex(re + other.re, im + other.im);
    }
    Complex operator-(const Complex &other)
    {
        return Complex(re - other.re, im - other.im);
    }
    Complex operator*(const Complex &other)
    {
        return Complex(re * other.re - im * other.im, re * other.im + other.re * im);
    }
};

int main(void)
{

    Complex c1;        // re = 0, im = 0
    Complex c2 = 5;    // re = 5, im = 0
    Complex c3(7, -4); // re = 7, im = -4

    Complex cm1(1, 2), cm2(10, 20);
    Complex res = cm1 + cm2; // cm1.re + cm2.re, cm1.im + cm2.im
    res = cm1 - cm2;         // cm1.re - cm2.re, cm1.im - cm2.im
    res = cm1 * cm2;         // cm1.re * cm2.re - cm1.im * cm2.im, cm1.re * cm2.im + cm2.re * cm1.im

    Complex cmp_1(-5, 23), cmp_2(14, 7);

    Complex res_1 = calc_data(cmp_1, cmp_2, ar_sub);
    double res_2 = calc_data(0.5, 10.4, ar_sum);
    int res_3 = calc_data(5, -11, ar_mul);

    // double p2 = perimetr(4, 7);
    // short p4 = perimetr<int>(4, 3.2);
    // unsigned p6 = perimetr(-1, 8);
    // int p1 = perimetr(1, 2);
    // long p3 = perimetr(4.5, 3.2);

    // int res_1 = min_3(1, -6, 10);
    // double res_2 = min_3(0.5, 0.3, 0.1);
    // char res_3 = min_3('a', 'b', '0');

    // double h1 = hypot(1, 0.5);
    // double h2 = hypot(6.3, 0.8);

    // float d1[] = {0.1f, 2.4f, 1.5f, -0.3f, 1.0f, -11.5f};
    // double d2[] = {-4.3, 0.8, 15.3, -0.01, -1.2, -6.5};
    // int d3[] = {6, 4, -1, -3, 0, 10, 8, -1, 2};

    // float s1 = ar_sum_positive(d1, std::size(d1));
    // double s2 = ar_sum_positive(d2, std::size(d2));
    // int s3 = ar_sum_positive(d3, std::size(d3));

    return 0;
}