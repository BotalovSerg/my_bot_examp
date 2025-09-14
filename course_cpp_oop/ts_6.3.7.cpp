#include <iostream>
#include <memory>

template <typename T>
class Object
{
    T data{0};
    std::shared_ptr<Object> next{nullptr};

public:
    Object(T d) : data(d), next(nullptr)
    {
    }

    const T &get_data() const { return data; }
    std::shared_ptr<Object> &get_next() { return next; }
};

template <typename D>
class Stack
{
    using shared_obj_ptr = std::shared_ptr<Object<D>>;

    shared_obj_ptr top{nullptr};

public:
    shared_obj_ptr get_top() { return top; }

    void push(const D &data)
    {
        shared_obj_ptr node = std::make_shared<Object<D>>(data);
        node->get_next() = top;
        top = node;
    }

    shared_obj_ptr pop()
    {
        if (!top)
            return nullptr;
        shared_obj_ptr ptr = top;
        top = top->get_next();
        return ptr;
    }
};

class Complex
{
    double im{0}, re{0};

public:
    Complex() : im(0), re(0)
    {
    }
    Complex(int imag, int real = 0) : im(imag), re(real)
    {
    }
    Complex(const Complex &other) : im(other.im), re(other.re)
    {
        puts("Copy");
    }
};

void func(Complex cmp) {}
void func_lnk(Complex &cmp) {}
void func_ptr(Complex *cmp) {}

int main(void)
{

    Complex d;
    Complex *r = new Complex(d);

    return 0;
}