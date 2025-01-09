#include <iostream>

#define MAX_SIZE 20

namespace array_alg
{
    void remove_item(size_t indx, size_t *len_ar, int arr[])
    {
        for (size_t i = indx; i < *len_ar - 1; i++)
        {
            arr[i] = arr[i + 1];
        }
        (*len_ar)--;
    }
    typedef int (*PTR_FILTER_FUNC)(int);
    size_t filter_int(int *ar, size_t len_ar, PTR_FILTER_FUNC func)
    {
        for (size_t i = 0; i < len_ar;)
        {
            if (func(ar[i]))
            {
                i++;
            }
            else
            {
                remove_item(i, &len_ar, ar);
            }
        }
        return len_ar;
    }
    namespace filter_func
    {
        int even(int n)
        {
            return n % 2 == 0 ? 1 : 0;
        }
    }
}

int main(void)
{
    int len_arr = 0;
    int arr[MAX_SIZE];

    while (std::cin >> arr[len_arr] && len_arr < MAX_SIZE)
    {
        len_arr++;
    }

    size_t count = array_alg::filter_int(arr, len_arr, array_alg::filter_func::even);

    for (size_t i = 0; i < count; i++)
    {
        std::cout << arr[i] << ' ';
    }
    std::cout << std::endl;

    return 0;
}