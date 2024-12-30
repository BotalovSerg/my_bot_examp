#include <stdio.h>
#define MAX_LENGTH 20

int sum_ar(const short *ar, size_t len, size_t indx)
{
    if (indx == len)
    {
        return 0;
    }
    else
    {
        return *ar + sum_ar(ar + 1, len, indx + 1);
    }
}

int main(void)
{
    short ar[MAX_LENGTH];
    int count = 0;
    while (count < MAX_LENGTH && scanf("%hd", &ar[count]) != EOF)
        count++;
    int result = sum_ar(ar, count, 0);
    printf("%d", result);

    return 0;
}