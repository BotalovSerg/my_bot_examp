#include <iostream>

using type_sort = enum { sort_asc,
                         sort_desc };

int sort(short *ar, size_t len, type_sort type = sort_asc)
{
    int *to_copy_ar = new int[len];
    for (int i = 0; i < len; i++)
    {
        to_copy_ar[i] = ar[i];
    }
    int count = 0;
    if (type == sort_asc)
    {
        for (size_t i = 0; i < len - 1; i++)
        {
            for (size_t j = i + 1; j < len; j++)
            {
                if (ar[j] < ar[i])
                {
                    short tmp = ar[i];
                    ar[i] = ar[j];
                    ar[j] = tmp;
                }
            }
        }
    }
    else
    {
        for (size_t i = 0; i < len - 1; i++)
        {
            for (size_t j = i + 1; j < len; j++)
            {
                if (ar[j] > ar[i])
                {
                    short tmp = ar[i];
                    ar[i] = ar[j];
                    ar[j] = tmp;
                }
            }
        }
    }
    for (int i = 0; i < len; i++)
    {
        if (to_copy_ar[i] != ar[i])
        {
            count++;
        }
    }

    delete[] to_copy_ar;

    return count;
}

int main()
{

    short arr[100];
    size_t len = 0;
    while (std::cin >> arr[len])
    {
        len++;
    }

    std::cout << sort(arr, len) << std::endl;

    return 0;
}