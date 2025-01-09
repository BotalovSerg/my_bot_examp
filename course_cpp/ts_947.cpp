#include <iostream>

#define MAX_SIZE 20

namespace array_alg
{
    typedef int (*PTR_FILTER_FUNC)(int);
    size_t add_int(int *src, size_t start, size_t max_len_src, const int *dest, size_t len_dest, PTR_FILTER_FUNC func)
    {
        for (size_t i = 0; i < len_dest; i++)
        {
            if (func(dest[i]) && start < max_len_src)
            {
                src[start] = dest[i];
                start++;
            }
        }
        return start;
    }

    namespace filter_func
    {
        int mark_positive(int mark)
        {
            return mark >= 4 ? 1 : 0;
        }
    }
}

int main()
{
    int marks[100] = {3, 2, 5, 4, 3};
    int ar[MAX_SIZE];
    size_t count = 0, count_marks = 5;

    while (std::cin >> ar[count] && count < MAX_SIZE)
    {
        count++;
    }
    count_marks = array_alg::add_int(marks, count_marks, 100, ar, count, array_alg::filter_func::mark_positive);

    for (size_t i = 0; i < count_marks; i++)
    {
        std::cout << marks[i] << ' ';
    }
    std::cout << std::endl;

    return 0;
}