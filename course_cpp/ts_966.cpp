#include <iostream>

using PTR_FUNC = bool (*)(double);

bool any(const double *ar, size_t len, PTR_FUNC filter)
{
    for (size_t i = 0; i < len; i++)
    {
        if (filter(ar[i]))
        {
            return true;
        }
    }
    return false;
}

bool range_out(double x)
{
    return x < -0.5 || x > 0.5 ? true : false;
}

int main(void)
{
    double arr[] = {0.1, 0.2, 0.3, -0.4, 1.4};
    bool res = any(arr, sizeof(arr) / sizeof(*arr), range_out);
    return 0;
}