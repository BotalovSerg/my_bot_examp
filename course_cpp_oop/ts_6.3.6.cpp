#include <iostream>

template <typename T = int>
class Array
{
    T *data{nullptr};
    size_t size{0};

public:
    Array() = default;
    Array(T *d, size_t size) : size(size)
    {
        data = new T[size];
        for (size_t i = 0; i < size; i++)
        {
            data[i] = d[i];
        }
    }
    Array(const Array &other)
    {
        delete[] data;
        size = other.size;
        data = new T[size];
        for (size_t i = 0; i < size; i++)
        {
            data[i] = other.data[i];
        }
    }

    ~Array() { delete[] data; }

    Array operator+(const Array &right)
    {
        size_t new_size = this->size + right.size;
        T *new_data = new T[new_size];

        for (size_t i = 0; i < this->size; i++)
        {
            new_data[i] = this->data[i];
        }
        for (size_t i = this->size, j = 0; i < new_size; i++, j++)
        {
            new_data[i] = right.data[j];
        }

        Array array_obj(new_data, new_size);

        return array_obj;
    }
    const Array &operator=(const Array &right)
    {
        delete[] data;
        size = right.size;
        data = new T[size];
        for (size_t i = 0; i < size; i++)
        {
            data[i] = right.data[i];
        }

        return *this;
    }

    const T *get_data() const { return data; }
    size_t get_length() const { return size; }
};

int main(void)
{
    int numbers[]{1, 2, 3, 4};
    Array a1(numbers, std::size(numbers));

    Array q2(a1);

    Array q1 = a1 + q2;

    return 0;
}