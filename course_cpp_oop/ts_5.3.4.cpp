#include <iostream>

int sum_ar(short *ar, size_t size);

int main(void)
{
    int sm;
    try
    {
        short ar[]{-1, 0, 10, 5, 3, 2};
        sm = sum_ar(ar, std::size(ar));
    }
    catch (const char *exc)
    {
        std::cout << exc << '\n';
    }

    std::cout << sm << '\n';
    // __ASSERT_TESTS__ // макроопределение для тестирования (не убирать и должно идти непосредственно перед return 0 или перед освобождением памяти)

    return 0;
}

int sum_ar(short *ar, size_t size)
{
    if (size == 0)
    {
        throw "Array length is zero.";
    }
    int sum = 0;
    for (size_t i = 0; i < size; i++)
    {
        sum += ar[i];
    }

    return sum;
}
