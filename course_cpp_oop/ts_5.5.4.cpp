#include <iostream>
#include <string>

class ArrayException
{
protected:
    std::string msg;

public:
    const char *what() const noexcept { return msg.c_str(); }
    ArrayException(const char *m) noexcept : msg(m) {}
    ArrayException(const ArrayException &other) noexcept : msg(other.msg) {}
    virtual ~ArrayException() {}
};

int main(void)
{
    try
    {
        throw ArrayException("Main exception");
    }
    catch (const ArrayException &e)
    {
        std::cout << e.what() << '\n';
    }

    return 0;
}