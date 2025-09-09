#include <iostream>
#include <string>

class ValueError : public std::exception
{
protected:
    std::string msg;

public:
    ValueError(std::string m) noexcept : msg(m) {}
    virtual ~ValueError() {}
    const char *what() const noexcept override { return msg.c_str(); }
};

class Window
{
    int width, height;

public:
    Window(int width, int height)
    {
        if (width <= 0 || height <= 0)
        {
            throw ValueError("The value must be positive");
        }
        this->width = width;
        this->height = height;
    }
    void get_data(int &w, int &h) const
    {
        w = width;
        h = height;
    }
};

class Rect
{
    double width, height;

public:
    Rect(double width, double height)
    {
        if (width <= 0 || height <= 0)
        {
            throw ValueError("The value must be positive");
        }
        this->width = width;
        this->height = height;
    }
    void get_data(double &w, double &h) const
    {
        w = width;
        h = height;
    }
};

template <typename C, typename T = int>
T get_square(const C &obj)
{
    T w, h;
    obj.get_data(w, h);
    return w * h;
}


template <typename T>
T ar_sum(T *arr, size_t count, bool (*filter)(T))
{
    T res{0};

    for (size_t i = 0; i < count; i++)
    {
        if (filter(arr[i]))
        {
            res += arr[i];
        }
    }

    return res;
}


int main()
{
    double data[] = {-1, 2.5, -3, -4, 5.1, 6};

    double res = ar_sum<double>(
        data,
        std::size(data),
        [](double n)
        { return n > 0; });
    try
    {
        Window w{100, -5};
        int res_sq = get_square(w);
    }
    catch (const ValueError &e)
    {
        std::cout << e.what() << '\n';
    }

    // __ASSERT_TESTS__ // макроопределение для тестирования (не убирать и должно идти непосредственно перед return 0)

    return 0;
}