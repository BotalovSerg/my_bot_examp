#include <iostream>
#include <string>
#include <cctype>

class ConvertToInt
{
public:
    ConvertToInt() : error_flag(false) {}

    int operator()(const char *str)
    {
        error_flag = false; // сбрасываем флаг ошибки при новом вызове
        if (str == nullptr)
        {
            error_flag = true;
            return 0;
        }

        // пропускаем возможные пробелы (по условию не указано, но можно добавить)
        // для строгости оставим как есть

        // Обработка знака
        int sign = 1;
        size_t index = 0;
        if (str[0] == '+')
        {
            index++;
        }
        else if (str[0] == '-')
        {
            sign = -1;
            index++;
        }

        long long result = 0;
        bool digit_found = false;

        while (str[index] != '\0')
        {
            char ch = str[index];

            if (ch >= '0' && ch <= '9')
            {
                digit_found = true;
                result = result * 10 + (ch - '0');
            }
            else if (ch == '.')
            {
                // Взять только целую часть, игнорируя дробную
                break;
            }
            else
            {
                // Нецифровой символ, кроме '+' и '-', вызывает ошибку
                error_flag = true;
                return 0;
            }
            index++;
        }

        if (!digit_found)
        {
            // Нет цифр, ошибка конвертации
            error_flag = true;
            return 0;
        }

        // Проверка на переполнение не требуется по условию, предполагается, что входные данные в пределах int

        int final_result = static_cast<int>(sign * result);
        return final_result;
    }

    bool is_error() const
    {
        return error_flag;
    }

private:
    bool error_flag; // флаг ошибки последней конвертации
};

int main()
{
    std::string digit;
    getline(std::cin, digit);
    const char *str = digit.c_str();

    ConvertToInt str_to_int;

    int res = str_to_int(str);

    std::cout << res << std::endl;

    return 0;
}