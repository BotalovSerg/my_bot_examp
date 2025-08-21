#include <iostream>
#include <string>
using std::cin;
using std::cout;
using std::string;

class ExceptionConvert
{
    string msg;

public:
    ExceptionConvert(const char *msg) : msg(msg)
    {
    }
    const string &to_msg() const
    {
        return msg;
    }
};

class ConvertToInt
{
    const char *check_str(const char *p_beg)
    {
        while (*p_beg && *p_beg != '.')
        {
            if (*p_beg < '0' || *p_beg > '9')
                throw ExceptionConvert("Conversion error");
            ++p_beg;
        }
        const char *p_end = p_beg;
        if (*p_end)
            p_beg++;
        while (*p_beg)
        { // точка может быть только одна
            if (*p_beg < '0' || *p_beg > '9')
                throw ExceptionConvert("Conversion error");
            ++p_beg;
        }
        return p_end;
    }

public:
    int operator()(const char *p_beg)
    {
        int res{};
        bool is_neg{};
        if (*p_beg == '+')
            ++p_beg;
        if (*p_beg == '-')
        {
            is_neg = true;
            ++p_beg;
        }
        const char *p_end = check_str(p_beg);
        while (p_beg < p_end)
        {
            res *= 10;
            res += *p_beg - '0';
            ++p_beg;
        }
        return is_neg ? -res : res;
    }
};

int main()
{
    string digit;
    getline(cin, digit);
    const char *str = digit.c_str();
    ConvertToInt str_to_int;
    try
    {
        cout << str_to_int(str);
    }
    catch (const ExceptionConvert &exc)
    {
        cout << exc.to_msg();
    }
    // __ASSERT_TESTS__ // макроопределение для тестирования
    return 0;
}