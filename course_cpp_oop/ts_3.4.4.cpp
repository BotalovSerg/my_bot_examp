#include <iostream>

class Box3D
{
    short a{0}, b{0}, c{0};

public:
    Box3D() {}
    Box3D(short a, short b, short c) : a(a), b(b), c(c) {}
    void get_dims(short &a, short &b, short &c) const
    {
        a = this->a;
        b = this->b;
        c = this->c;
    }
    void set_dims(short a, short b, short c)
    {
        this->a = a;
        this->b = b;
        this->c = c;
    }
    operator int() const
    {
        return a * b * c;
    }
    class Item
    {
        Box3D *current_box{nullptr};
        int index{-1};
        int value_error{0};

    public:
        Item(Box3D *obj, int indx) : current_box(obj), index(indx) {}

        short operator=(int value)
        {
            if (value < 0 || index < 0 || index > 2)
            {
                return;
            }
            if (index == 0)
            {
                current_box->a = value;
                return value;
            }
            if (index == 1)
            {
                current_box->b = value;
                return value;
            }
            if (index == 2)
            {
                current_box->c = value;
                return value;
            }
        }
        operator short() const
        {
            if (index < 0 || index > 2)
            {
                return value_error;
            }
            if (index == 0)
            {
                return current_box->a;
            }
            if (index == 1)
            {
                return current_box->b;
            }
            if (index == 2)
            {
                return current_box->c;
            }
        }
    };
    Item operator[](int indx)
    {
        return Item(this, indx);
    }
};

int main(void)
{
    Box3D b;
    b[0] = 10;        // a = 10
    b[1] = 20;        // b = 20
    b[2] = 30;        // c = 30
    int volume = b;   // возвращается объем: a * b * c
    short dim = b[2]; // получение значения габарита по индексу indx
}