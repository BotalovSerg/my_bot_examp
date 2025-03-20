#include <iostream>

class IntOperator
{
    int *data{nullptr};
    int size{0};

public:
    IntOperator(int arr[] = nullptr, int size = 0) : data(arr), size(size)
    {
        for (int i = 0; i < size; i++)
        {
            data[i] = arr[i];
        }
    }
    ~IntOperator()
    {
        if (size)
        {
            for (int i = 0; i < size; i++)
            {
                data[i] = 0;
            }
        }
    }
    int sum()
    {
        int s = 0;
        for (int i = 0; i < size; i++)
        {
            s += data[i];
        }
        return s;
    }
    double average()
    {
        if (size == 0)
        {
            return 0;
        }
        return static_cast<double>(sum()) / size;
    }
    int max()
    {
        int max_current = data[0];
        for (int i = 1; i < size; i++)
        {
            if (max_current < data[i])
            {
                max_current = data[i];
            }
        }
        return max_current;
    }
    int min()
    {
        int min_current = data[0];
        for (int i = 1; i < size; i++)
        {
            if (min_current > data[i])
            {
                min_current = data[i];
            }
        }
        return min_current;
    }
};

int main(void)
{
    int dt[] = {4, -5, 2, 10, 7, 22};

    IntOperator op_1;
    IntOperator op_2(dt, std::size(dt));

    return 0;
}