#include <iostream>
#include <string>

class BoxError : public std::exception
{
protected:
    std::string msg;

public:
    BoxError(std::string m) noexcept : msg(m) {}
    virtual ~BoxError() {}
    const char *what() const noexcept override { return msg.c_str(); }
};

class BoxLimitError : public BoxError
{
public:
    BoxLimitError(const std::string &m) noexcept : BoxError(m) {}
    virtual ~BoxLimitError() {}
};

class BoxCalcError : public BoxError
{
public:
    BoxCalcError(const std::string &m) noexcept : BoxError(m) {}
    virtual ~BoxCalcError() {}
};

class Box3D
{
    enum
    {
        limit_dim = 100
    };
    short a{0}, b{0}, c{0};

public:
    Box3D() {}
    Box3D(short a, short b, short c)
    {
        set_dims(a, b, c);
    }
    bool check_dim(short n)
    {
        if (n < 0 || n > limit_dim)
        {
            return false;
        }
        return true;
    }
    void get_dims(short &a, short &b, short &c)
    {
        a = this->a;
        b = this->b;
        c = this->c;
    }
    void set_dims(short a, short b, short c)
    {
        if (!check_dim(a) || !check_dim(b) || !check_dim(c))
        {
            throw BoxLimitError("Exceeding the size range.");
        }
        this->a = a;
        this->b = b;
        this->c = c;
    }
    Box3D operator+(const Box3D &other)
    {
        if (!check_dim(a + other.a) || !check_dim(b + other.b) || !check_dim(c + other.c))
        {
            throw BoxCalcError("Calculation: Exceeding the size range.");
        }

        return Box3D(a + other.a, b + other.b, c + other.c);
    }
    Box3D operator-(const Box3D &other)
    {
        if (!check_dim(a - other.a) || !check_dim(b - other.b) || !check_dim(c - other.c))
        {
            throw BoxCalcError("Calculation: Exceeding the size range.");
        }
        return Box3D(a - other.a, b - other.b, c - other.c);
    }
};

int main()
{
    try
    {
        Box3D box{5, -1, 10};
    }
    catch (BoxCalcError &e)
    {
        std::cout << e.what() << '\n';
    }
    catch (BoxLimitError &e)
    {
        std::cout << e.what() << '\n';
    }
    catch (BoxError &e)
    {
        std::cout << e.what() << '\n';
    }
    // __ASSERT_TESTS__ // макроопределение для тестирования (не убирать и должно идти непосредственно перед return 0)

    return 0;
}