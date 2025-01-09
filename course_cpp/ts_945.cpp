#include <iostream>

#define MAX_SIZE 20

namespace array_alg
{
    typedef enum
    {
        sort_asc,
        sort_desc
    } TYPE_SORT;

    void sorted_int(int *ar, size_t len_ar, TYPE_SORT type)
    {
        if (type == sort_asc)
        {
            for (size_t i = 0; i < len_ar - 1; i++)
            {
                for (int j = i + 1; j < len_ar; j++)
                {
                    if (ar[i] > ar[j])
                    {
                        int tmp = ar[i];
                        ar[i] = ar[j];
                        ar[j] = tmp;
                    }
                }
            }
        }
        else if (type == sort_desc)
        {
            for (size_t i = 0; i < len_ar - 1; i++)
            {

                for (int j = i + 1; j < len_ar; j++)
                {
                    if (ar[i] < ar[j])
                    {
                        int tmp = ar[i];
                        ar[i] = ar[j];
                        ar[j] = tmp;
                    }
                }
            }
        }
    }
}

int main(void)
{
    int count = 0;
    int arr[MAX_SIZE];

    while (std::cin >> arr[count] && count < MAX_SIZE)
    {
        count++;
    }

    array_alg::sorted_int(arr, count, array_alg::sort_desc);

    for (int i = 0; i < count; i++)
    {
        std::cout << arr[i] << ' ';
    }
    std::cout << std::endl;

    return 0;
}