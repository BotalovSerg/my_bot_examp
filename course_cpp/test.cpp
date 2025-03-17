#include <iostream>

class StringData
{
    enum
    {
        max_length = 512
    };
    char str_data[max_length]{0};
    int length{0};

public:
    StringData() {}
    StringData(const char *data)
    {
        int i = 0;
        for (; i < max_length - 1 && data[i] != '\0'; ++i)
            str_data[i] = data[i];
        str_data[i] = '\0';
        length = i + 1;
    }
};

int main()
{
    StringData s1;
    StringData s2 = "Hello, C++";
    StringData *ptr_s3 = new StringData("Hello, Balakirev");

    delete ptr_s3;
    return 0;
}