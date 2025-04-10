#include <iostream>

class Array
{
    double *data{nullptr};
    size_t size{0};
    Array(size_t size) : size(size)
    {
        data = new double[size]{0};
    }
    Array(double *d, size_t length)
    {
        set_data(d, length);
    }

public:
    ~Array()
    {
        if (data)
        {
            delete[] data;
        }
    }
    void set_data(double *d, size_t length)
    {
        delete[] data;
        size = length;
        data = new double[size];

        for (size_t i = 0; i < size; ++i)
            data[i] = d[i];
    }

    double *get_data() { return data; }
    size_t get_size() { return size; }
    static Array *create(int size) { return new Array(size); }
    static Array *create(double *data, size_t size) { return new Array(data, size); }
};
