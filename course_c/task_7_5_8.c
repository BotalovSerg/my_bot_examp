#include <stdio.h>

typedef enum
{
    _do = 1,
    _re = 2,
    _mi = 3,
    _fa = 4,
    _sol = 5,
    _la = 6,
    _si = 7
} NOTES;

int get_major(NOTES n)
{
    if (n == _do || n == _sol || n == _mi)
    {
        return 1;
    }
    return 0;
}

int main(void)
{
    int arr[5];
    int *p = arr;
    int n;
    while (scanf("%d", &n) == 1)
    {
        *p = n;
        ++p;
    }
    for (size_t i = 0; i < 5; i++)
    {
        if (get_major(arr[i]))
        {
            printf("%d ", arr[i]);
        }
    }

    return 0;
}