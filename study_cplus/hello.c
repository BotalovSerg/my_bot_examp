#include <stdio.h>
#include "func.h"

int main(void)
{
    int a = 7, b = 77, i = -1, res;
    res = sum_two(a, b);

    printf("sum = %d\ni = %d\n", res, abs_int(i));

    return 0;
}