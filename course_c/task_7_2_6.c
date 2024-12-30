#include <stdio.h>

int is_prime(int a)
{
    if (a == 2)
    {
        return 1;
    }
    for (int i = 2; i < a / 2; ++i)
    {
        if (a % i == 0)
        {
            return 0;
        }
    }
    return 1;
}

int main(void)
{
    int n, number = 2;
    scanf("%d", &n);
    while (n != 1)
    {
        if (n % number == 0 && is_prime(number))
        {
            n = n / number;
            printf("%d ", number);
            number = 2;
        }
        else
        {
            ++number;
        }
    }
    return 0;
}
