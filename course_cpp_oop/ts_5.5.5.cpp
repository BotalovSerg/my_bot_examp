#include <iostream>
#include <string>

class VectorError : public std::exception
{
protected:
    std::string msg;

public:
    VectorError(const std::string &error) noexcept : msg(error)
    {
    }
    virtual ~VectorError() {}

    const char *what() const noexcept override { return msg.data(); }
};

class VectorErrorNegativeCoord : public VectorError
{

public:
    VectorErrorNegativeCoord() noexcept : VectorError("Negative coordinate value.") {}
    VectorErrorNegativeCoord(std::string m) noexcept : VectorError(m) {}
    virtual ~VectorErrorNegativeCoord() {}
};

class Vector
{
    int x{0}, y{0};

public:
    Vector() {}
    Vector(int x, int y)
    {
        if (x < 0 || y < 0)
        {
            throw VectorErrorNegativeCoord("Constructor: Negative coordinate value.");
        }
        set_xy(x, y);
    }
    int get_x() const { return x; }
    int get_y() const { return y; }
    void set_xy(int x, int y)
    {
        if (x < 0 || y < 0)
        {
            throw VectorErrorNegativeCoord();
        }

        this->x = x;
        this->y = y;
    }
};

int main()
{
    int x, y;
    std::cin >> x >> y;

    try
    {
        Vector v{x, y};
        std::cout << x << " " << y << std::endl;
    }
    catch (const VectorErrorNegativeCoord &e)
    {
        std::cout << e.what() << '\n';
    }

    // __ASSERT_TESTS__ // макроопределение для тестирования (не убирать и должно идти непосредственно перед return 0)

    return 0;
}