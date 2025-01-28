#include <iostream>
#include <string>
#include <cstring>

bool check_password(const char *password, const std::string &chars = "$%!?@#")
{
    if (std::strlen(password) < 8)
    {
        return false;
    }
    for (size_t i = 0; i < std::strlen(password); i++)
    {
        if (chars.find(password[i]) != std::string::npos)
        {
            return true;
        }
    }
    return false;
}

int main()
{
    std::string pwd_in;
    std::cin >> pwd_in;
    const char *cstr = pwd_in.c_str();

    if (check_password(cstr))
    {
        std::cout << "yes" << std::endl;
    }
    else
    {
        std::cout << "no" << std::endl;
    }

    return 0;
}