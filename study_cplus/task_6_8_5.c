#include <stdio.h>
#include <stdarg.h>

double sumf(const char *format, ...)
{
    double s = 0;
    va_list arg;
    va_start(arg, format);
    for (; *format != '\0'; ++format)
    {
        if ('+' == *format)
        {
            s += va_arg(arg, double);
        }
        else
        {
            va_arg(arg, double);
        }
    }
    va_end(arg);
    return s;
}

int main(void)
{
    double res = sumf("++ + +", 1.0, 2.0, 3.0, 4.0, 5.0, 6.0);
    printf("%.2f ", res);

    return 0;
}