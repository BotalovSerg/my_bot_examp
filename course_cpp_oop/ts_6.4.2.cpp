#include <iostream>

template <typename T>
class GraphInterface
{
public:
    virtual void get_coords(T &x0, T &y0, T &x1, T &y1) const = 0;
    virtual void set_coords(T x0, T y0, T x1, T y1) = 0;
    virtual void draw() const = 0;
    virtual ~GraphInterface() {}
};

template <typename T>
class Ellipse : public GraphInterface<T>
{
    T x0{0}, y0{0}, x1{0}, y1{0};

public:
    virtual void get_coords(T &x0, T &y0, T &x1, T &y1) const
    {
        x0 = this->x0;
        y0 = this->y0;
        x1 = this->x1;
        y1 = this->y1;
    }
    virtual void set_coords(T x0, T y0, T x1, T y1)
    {
        this->x0 = x0;
        this->y0 = y0;
        this->x1 = x1;
        this->y1 = y1;
    }
    virtual void draw() const
    {
        std::cout << x0 << " " << y0 << " "
                  << x1 << " " << y1 << std::endl;
    }
    Ellipse(T x0 = 0, T y0 = 0, T x1 = 0, T y1 = 0) : x0(x0), y0(y0), x1(x1), y1(y1) {}
};

int main()
{
    // GraphInterface<short> *lst[]{
    //     new Ellipse<short>(-5, 10, 0, 11),
    //     new Ellipse<short>(5, 2, -4, -3),
    //     new Ellipse<short>(1, 5, 10, 22)};

    Ellipse<double> e1; // все координаты нулевые
    Ellipse<int> e2(1, 2, 3, 4);

    Ellipse<short> *el1 = new Ellipse<short>{-5, 10, 0, 11};
    Ellipse<short> *el2 = new Ellipse<short>{5, 2, -4, -3};
    Ellipse<short> *el3 = new Ellipse<short>{1, 5, 10, 22};

    GraphInterface<short> *lst[] = {el1, el2, el3};

    for (size_t i = 0; i < 3; i++)
    {
        lst[i]->draw();
    }

    // __ASSERT_TESTS__ // макроопределение для тестирования (не убирать и должно идти непосредственно перед return 0)

    for (size_t i = 0; i < 3; i++)
    {
        delete lst[i];
    }

    return 0;
}