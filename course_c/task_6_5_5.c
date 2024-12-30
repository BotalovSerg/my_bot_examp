#include <stdio.h>

int is_odd(int n)
{
    return n % 2 != 0;
}

int is_positive(int n)
{
    return n > 0;
}

int is_negative(int n)
{
    return n < 0;
}

int defit(int n)
{
    return 1;
}

int sum_ar(const int *ar, size_t len_ar, int (*filter)(int))
{
    int result = 0;
    for (int i = 0; i < len_ar; ++i)
    {
        if (filter(ar[i]))
        {
            result += ar[i];
        }
    }
    return result;
}

int main(void)
{
    int (*funcs[4])(int) = {is_odd, is_positive, is_negative, defit};
    int marks[20] = {0};

    int item = 0;
    scanf("%d", &item); // выбор критерия суммирования

    int x, cnt = 0;
    while ((scanf("%d", &x) == 1) && cnt < 20)
    {
        marks[cnt] = x;
        cnt++;
    }

    int sum = 0; // переменная для хранения суммы
    switch (item)
    {
    case 1:
        sum = sum_ar(marks, cnt, funcs[0]);
        break;
    case 2:
        sum = sum_ar(marks, cnt, funcs[1]);
        break;
    case 3:
        sum = sum_ar(marks, cnt, funcs[2]);
        break;
    default:
        sum = sum_ar(marks, cnt, funcs[3]);
    }

    printf("%d", sum);

    return 0;
}