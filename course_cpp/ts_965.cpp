#include <iostream>

using PTR_FUNC = bool (*)(int);

bool positive(int x)
{
    return x > 0 ? true : false;
}

bool all(const int *ar, size_t len, PTR_FUNC filter)
{
    for (size_t i = 0; i < len; ++i)
    {
        if (!filter(ar[i]))
        {
            return false;
        }
    }
    return true;
}

int main()
{
    int arr[] = {-2, -3, -1, -10, -15};
    bool res = all(arr, sizeof(arr) / sizeof(*arr), positive);
    return 0;
}