#include <iostream>
#include <iomanip>

using std::cin;
using std::cout;
using std::endl;
using std::fixed;
using std::setprecision;

double get_mean(const short *d, const size_t len)
{
    short s = 0;
    for (size_t i = 0; i < len; ++i)
    {
        s += d[i];
    }
    return (double)s / (double)len;
}
double get_mean(const int *d, const size_t len)
{
    int s = 0;
    for (size_t i = 0; i < len; ++i)
    {
        s += d[i];
    }
    return (double)s / (double)len;
}
double get_mean(const double *d, const size_t len)
{
    double s = 0;
    for (size_t i = 0; i < len; ++i)
    {
        s += d[i];
    }
    return s / (double)len;
}

int main()
{

    short arr[100];
    size_t count = 0;
    double res;
    while (cin >> arr[count])
    {
        ++count;
    }
    cout << fixed << setprecision(2) << get_mean(arr, count) << endl;

    return 0;
}
