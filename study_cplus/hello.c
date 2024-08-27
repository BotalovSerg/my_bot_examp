#include <stdio.h>

int main(void)
{
    int start_s = 37985;
    int in_time, b, d;

    ++(b);
    d++;
    --b;
    // (b++)++;
    // (d + 10)++;
    // --(b + d);
    // 10++;

    int h, m, s;
    scanf("%d; %d; %d", &h, &m, &s);
    in_time = h * 3600 + m * 60 + s;
    start_s += in_time;

    h = start_s / 3600;
    m = start_s % 3600 / 60;
    s = start_s % 60;
    printf("%02d:%02d:%02d\n", h, m, s);

    return 0;
}