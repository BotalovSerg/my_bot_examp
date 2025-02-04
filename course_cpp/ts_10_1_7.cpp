#include <iostream>
#include <cstring>
#include <cstdio>

struct tag_time
{
    unsigned char hours;
    unsigned char minutes;
    unsigned char seconds;

    char *get_time(char *str, size_t max_lenght)
    {
        sprintf(str, "%02d:%02d:%02d", hours, minutes, seconds);
        return str;
    }
    static tag_time sum_time(const tag_time &t1, const tag_time &t2)
    {
        unsigned char overflow;
        tag_time tm_sum;
        if ((t1.seconds + t2.seconds) / 60)
        {
            overflow = (t1.seconds + t2.seconds) / 60;
            tm_sum.seconds = (t1.seconds + t2.seconds) % 60;
        }
        else
        {
            overflow = 0;
            tm_sum.seconds = (t1.seconds + t2.seconds) % 60;
        }
        if ((t1.minutes + t2.minutes + overflow) / 60)
        {
            overflow = (t1.minutes + t2.minutes + overflow) / 60;
            tm_sum.minutes = (t1.minutes + t2.minutes + overflow) % 60;
        }
        else
        {
            overflow = 0;
            tm_sum.minutes = (t1.minutes + t2.minutes + overflow) % 60;
        }
        tm_sum.hours = t1.hours + t2.hours + overflow;
        return tm_sum;
    }
};

int main(void)
{
    tag_time tm1, tm2, time_res;
    char str[10];
    scanf("%hhu %hhu %hhu %hhu %hhu %hhu",
          &tm1.hours,
          &tm1.minutes,
          &tm1.seconds,
          &tm2.hours,
          &tm2.minutes,
          &tm2.seconds);

    time_res = tag_time::sum_time(tm1, tm2);

    std::cout << time_res.get_time(str, sizeof(str)) << std::endl;

    //__ASSERT_TESTS__ // макроопределение для тестирования (не убирать и должно идти непосредственно перед return 0)
    return 0;
}