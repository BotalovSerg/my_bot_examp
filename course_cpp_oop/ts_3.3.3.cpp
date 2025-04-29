#include <iostream>

class Array
{
    int *data{nullptr};
    size_t size{0};

public:
    void set_data(int *d, size_t length)
    {
        delete[] data;
        size = length;
        data = new int[size];

        for (size_t i = 0; i < size; ++i)
            data[i] = d[i];
    }

    int *get_data() { return data; }
    size_t get_size() const { return size; }
    Array() {}
    Array(int *d, size_t len)
    {
        set_data(d, len);
    }
    ~Array()
    {
        if (data)
        {
            delete[] data;
        }
    }
    Array(const Array &obj)
    {
        set_data(obj.data, obj.size);
    }

    const Array &operator=(const Array &other)
    {
        if (this == &other)
        {
            return other;
        }
        size = other.size;
        delete[] data;
        data = new int[size];

        for (size_t i = 0; i < size; ++i)
        {
            data[i] = other.data[i];
        }

        return *this;
    }
    Array operator+(const Array &r)
    {
        size_t new_size = this->size + r.size;
        int *tmp = new int[new_size];
        size_t i = 0;
        for (; i < this->size; i++)
        {
            tmp[i] = this->data[i];
        }
        for (size_t j = 0; j < r.size; i++, j++)
        {
            tmp[i] = r.data[j];
        }
        Array arr{tmp, new_size};
        delete[] tmp;
        return arr;

    }
};

int main(void)
{
    int d[] = {1, 2, 3};
    int d1[] = {4, 5, 6};

    Array ar(d, std::size(d));
    Array ar1(d1, std::size(d1));

    Array res_1;
    res_1 = ar1 + ar;
    Array res_2 = ar1 + ar + res_1;
    return 0;
}