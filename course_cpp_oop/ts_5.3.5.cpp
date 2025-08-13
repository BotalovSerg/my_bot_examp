#include <iostream>
#include <string>

class ArrayInt
{
    int *data{nullptr};
    size_t size{0};

public:
    void set_data(int *d, size_t length)
    {
        data = new int[length];
        size = length;
        for (size_t i = 0; i < length; i++)
        {
            data[i] = d[i];
        }
    }
    int *get_data() { return data; }
    size_t get_size() const { return size; }
    ArrayInt() {}
    ArrayInt(int *d, size_t len)
    {
        set_data(d, len);
    }
    ~ArrayInt()
    {
        if (data)
        {
            delete[] data;
        }
    }
    int &operator[](int index)
    {
        if (index < 0 || index > size - 1)
        {
            throw "Incorrect index.";
        }
        return data[index];
    }
};

int main(void)
{
    int num[]{1, 2, 3, 4};
    ArrayInt data_ar(num, std::size(num));

    int val = data_ar[1];
    data_ar[1] = 5;

    data_ar[6] = 6;

    return 0;
}