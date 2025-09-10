#include <iostream>
#include <cmath>

template <typename T>
void ar_sort(T *arr, size_t count, bool (*filter)(T a, T b))
{
    for (size_t i = 0; i < count - 1; i++)
    {
        for (size_t j = i + 1; j < count; j++)
        {
            if (filter(arr[j], arr[i]))
            {
                T tmp = arr[j];
                arr[j] = arr[i];
                arr[i] = tmp;
            }
        }
    }
}

int main()
{
    int data[] = {5, -3, 10, 0, 33, 7, -12};

    ar_sort<int>(
        data,
        std::size(data), [](int a, int b)
        { return fabs(a) < fabs(b); });

    // __ASSERT_TESTS__

    return 0;
}