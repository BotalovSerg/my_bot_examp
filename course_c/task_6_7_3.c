#include <stdio.h>
#define MAX_LENGTH 20

size_t range_to_ar(int *ptr_a, size_t max_len, int from, int to, size_t count)
{
    if (from <= to && count < max_len)
    {
        *ptr_a = from;
        count = count + 1;
        range_to_ar(++ptr_a, max_len, from + 1, to, count);
    }
    else
    {
        return count;
    }
}

int main(void)
{
    int max_rec;
    int ar[MAX_LENGTH];
    scanf("%d", &max_rec);

    size_t cnt = range_to_ar(ar, MAX_LENGTH, 1, max_rec, 0);

    for (int i = 0; i < cnt; ++i)
    {
        printf("%d ", ar[i]);
    }

    return 0;
}