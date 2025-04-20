#include <iostream>
#include <cstring>

class StringChars
{
    char *buffer{nullptr};
    size_t length{0};

public:
    char *to_str() const { return buffer; }
    size_t get_length() const { return length; }
    StringChars(const char *str) : length(strlen(str))
    {
        buffer = new char[length];
        strcpy(buffer, str);
    }
    StringChars(const StringChars &other)
    {
        this->length = other.length;
        buffer = new char[length];
        strcpy(buffer, other.buffer);
    }
    ~StringChars()
    {
        if (buffer)
        {
            delete[] buffer;
        }
    }
    StringChars operator+(const StringChars &obj)
    {
        size_t len_obj = this->length + obj.length;
        char *new_str = new char[len_obj];
        strcat(new_str, this->buffer);
        strcat(new_str, obj.buffer);
        return StringChars(new_str);
    }
};

int main(void)
{
    StringChars *ptr_str1 = new StringChars("Language");
    StringChars *ptr_str2 = new StringChars(" C++");
    StringChars res = (*ptr_str1) + (*ptr_str2);

    delete ptr_str1;
    delete ptr_str2;
    
    return 0;
}