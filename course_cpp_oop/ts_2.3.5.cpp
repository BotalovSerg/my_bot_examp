#include <iostream>

class StringBuffer
{
    enum
    {
        max_size = 1024
    };
    char *buffer{nullptr};
    int size{0};

public:
    StringBuffer(const char *str)
    {
        size = 0;
        while (str[size] != '\0' && size < max_size - 1)
            size++;

        buffer = new char[size + 1];
        for (int i = 0; i < size; ++i)
            buffer[i] = str[i];

        buffer[size] = '\0';
    }
    StringBuffer(const StringBuffer &other)
    {
        size = other.size;
        buffer = new char[size + 1];
        for (int i = 0; i < size; ++i)
            buffer[i] = other.buffer[i];

        buffer[size] = '\0';
    }
    ~StringBuffer()
    {
        delete[] buffer;
    }

    const char *get_data() { return buffer; }
    int get_size() { return size; }
};

int main(void)
{
    StringBuffer str("Hello");
    StringBuffer data{str};
    return 0;
}