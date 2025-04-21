#include <iostream>

class ColorRGB
{
    unsigned char r{0}, g{0}, b{0};

public:
    unsigned get_color() { return r + g * 256 + b * 65536; }
    ColorRGB(unsigned char r = 0, unsigned char g = 0, unsigned char b = 0)
    {
        this->r = r;
        this->g = g;
        this->b = b;
    }
    friend ColorRGB operator+(const ColorRGB &right, const ColorRGB &left);
};

ColorRGB operator+(const ColorRGB &right, const ColorRGB &left)
{
    unsigned char r = (right.r + left.r) > 255 ? 255 : (right.r + left.r);
    unsigned char g = (right.g + left.g) > 255 ? 255 : (right.g + left.g);
    unsigned char b = (right.b + left.b) > 255 ? 255 : (right.b + left.b);

    return ColorRGB(r, g, b);
}

int main(void)
{
    ColorRGB clr_1(100, 100, 100), clr_2(255, 0, 80);
    ColorRGB res = clr_1 + clr_2;
    return 0;
}