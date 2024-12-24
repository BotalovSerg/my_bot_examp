#include <stdio.h>

typedef enum
{
    param_int = 1,
    param_double = 2
} TYPE_PARAM;

typedef union
{
    int data_i;
    double data_d;
} DATA;

DATA sum_ar(DATA arr[], size_t cnt_elem, TYPE_PARAM type)
{
    DATA res;
    if (type == param_int)
    {
        res.data_i = 0;
        for (size_t i = 0; i < cnt_elem; ++i)
        {
            res.data_i += arr[i].data_i;
        }
        return res;
    }
    res.data_d = 0;
    for (size_t i = 0; i < cnt_elem; ++i)
    {
        res.data_d += arr[i].data_d;
    }
    return res;
}

int main(void)
{
    DATA res_1, res_2;
    res_1 = sum_ar((DATA[]){{1}, {2}, {3}, {4}, {5}}, 5, 1);
    res_2 = sum_ar((DATA[]){{.data_d = 1.1}, {.data_d = 2.2}, {.data_d = 3.3}, {.data_d = 4.4}, {.data_d = 5.5}}, 5, 2);

    return 0;
}
