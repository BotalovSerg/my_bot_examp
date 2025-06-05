#include <iostream>
#include <string>
#include <stdlib.h>

class RandomPassword
{
    std::string psw_chars;
    int min_length, max_length;

public:
    RandomPassword(std::string psw_chars, int min_length, int max_length)
        : psw_chars(psw_chars), min_length(min_length), max_length(max_length) {}

    std::string operator()()
    {
        int len_psw = rand() % (max_length - min_length + 1) + min_length;
        std::string psw{""};
        int len_chars = psw_chars.length();
        for (int i = 0; i < len_psw; ++i)
        {
            psw += psw_chars[rand() % len_chars];
        }
        return psw;
    }
};

int main(void)
{
    RandomPassword rnd("qwertyuiopasdfghjklzxcvbnm0123456789!@#$%&*", 5, 15);
    std::string psw_1 = rnd(); // psw_1: hqt5!v@gk
    std::string psw_2 = rnd(); // psw_2: vmdp&wgs*#qd
    return 0;
}