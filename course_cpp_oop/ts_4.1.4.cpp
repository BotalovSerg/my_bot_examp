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
    bool is_valid(int x) const
    {
        return x >= min_value && x <= max_value;
    }
};