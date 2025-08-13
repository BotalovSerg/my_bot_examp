#include <iostream>
#include <string>

class Validator
{
protected:
    std::string msg_ex;

public:
    virtual bool is_valid(int x, bool exception = true) const = 0;
    virtual ~Validator() {}
};

class ValidatorRange : public Validator
{
    int min_value{0}, max_value{0};

public:
    ValidatorRange(std::string msg, int min_v, int max_v)
    {
        this->msg_ex = msg;
        this->min_value = min_v;
        this->max_value = max_v;
    }
    virtual bool is_valid(int x, bool exception = true) const override
    {
        if (x >= min_value && x <= max_value)
        {
            return true;
        }
        else
        {
            if (exception)
            {
                throw msg_ex;
            }
            return false;
        }
    }
};

int main(void)
{
    ValidatorRange vr{"Value is outside the range [0; 15]", 0, 15};

    try
    {
        int x;
        std::cin >> x;
        vr.is_valid(x);
    }
    catch (const std::string &e)
    {
        std::cout << e << '\n';
    }

    // __ASSERT_TESTS__ // макроопределение для тестирования (не убирать и должно идти непосредственно перед return 0 или перед освобождением памяти)

    return 0;
}