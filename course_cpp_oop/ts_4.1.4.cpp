#include <iostream>

class ValidatorInteger
{
private:
    int err_no{0};

public:
    ValidatorInteger() = default;
    int get_errno() const { return err_no; }
    bool is_valid(int x) const { return true; }; // проверка условия для значения x (сама проверка реализуется в дочерних классах)
};

class ValidatorRange : public ValidatorInteger
{
    int min_value{0}, max_value{0};

public:
    ValidatorRange(int min_v, int max_v)
        : min_value(min_v), max_value(max_v) {}

    bool is_valid(int x) const
    {
        return x >= min_value && x <= max_value;
    }
};

class ValidatorPositive : public ValidatorInteger
{
public:
    ValidatorPositive() = default;
    bool is_valid(int x) const { return x >= 0; }
};

int main(void)
{

    ValidatorRange vr{-5, 7};
    ValidatorPositive v_positive;

    int x;
    std::cin >> x;

    std::cout << vr.is_valid(x)
              << " " << v_positive.is_valid(x)
              << std::endl;

    return 0;
}