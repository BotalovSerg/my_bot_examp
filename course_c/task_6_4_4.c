#include <stdio.h>
#include <string.h>

int to_csv(char str[], const double arr[], int len)
{
    char f[10] = "%.2lf";
    for (int i = 0; i < len; ++i)
    {
        char tmp[10] = {0};
        sprintf(tmp, f, arr[i]);
        strcat(str, tmp);
        (i == len - 1) ? strcat(str, "") : strcat(str, "; ");
    }

    return len;
}

int main(void)
{
    char result[100] = "csv: ";
    double num_dou[20] = {0};
    double *p = num_dou;
    int cnt = 0;
    while (scanf("%lf", p) != EOF)
    {
        ++p;
        ++cnt;
    }
    to_csv(result, num_dou, cnt);
    puts(result);

    return 0;
}