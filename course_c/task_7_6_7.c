#include <stdio.h>

struct tag_time
{
    unsigned char hours;
    unsigned char minutes;
    unsigned char seconds;
};

int main(void)
{
    struct tag_time tm1, tm2, tm_sum;
    unsigned char overflow;
    scanf("%hhu %hhu %hhu %hhu %hhu %hhu",
          &tm1.hours,
          &tm1.minutes,
          &tm1.seconds,
          &tm2.hours,
          &tm2.minutes,
          &tm2.seconds);

    if ((tm1.seconds + tm2.seconds) / 60)
    {
        overflow = (tm1.seconds + tm2.seconds) / 60;
        tm_sum.seconds = (tm1.seconds + tm2.seconds) % 60;
    }
    else
    {
        overflow = 0;
        tm_sum.seconds = (tm1.seconds + tm2.seconds) % 60;
    }
    if ((tm1.minutes + tm2.minutes + overflow) / 60)
    {
        overflow = (tm1.minutes + tm2.minutes + overflow) / 60;
        tm_sum.minutes = (tm1.minutes + tm2.minutes + overflow) % 60;
    }
    else
    {
        overflow = 0;
        tm_sum.minutes = (tm1.minutes + tm2.minutes + overflow) % 60;
    }
    tm_sum.hours = tm1.hours + tm2.hours + overflow;

    printf("%02d:%02d:%02d", tm_sum.hours, tm_sum.minutes, tm_sum.seconds);

    // __ASSERT_TESTS__ // макроопределение для тестирования (не убирать и должно идти непосредственно перед return 0)
    return 0;
}