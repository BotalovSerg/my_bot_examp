#include <iostream>

class Clock
{
protected:
    unsigned time_current{0};

public:
    Clock() {}
    Clock(unsigned tc) : time_current(tc) {}
    void set_time(unsigned tm) { time_current = tm; }          // заносит в поле time_current значение tm
    unsigned get_hours() const { return time_current / 3600; } // возвращает количество часов в time_current
    unsigned get_minutes() const
    {
        return time_current % 3600 / 60;
    } // возвращает количество минут в time_current (за вычетом часов)
    unsigned get_seconds() const { return time_current % 60; } // возвращает количество секунд в time_current (за вычетом часов и минут)
};

class ClockShow : public Clock
{

public:
    enum time_format
    {
        tm_hhmmss = 1,
        tm_hms = 2,
        tm_ssmmhh = 3,
        tm_smh = 4
    };
    void show_time() const
    {
        switch (format)
        {
        case tm_hhmmss:
            std::printf("%2u:%2u:%2u\n",
                        get_hours(), get_minutes(), get_seconds());
            break;
        case tm_hms:
            std::printf("%u:%u:%u\n",
                        get_hours(), get_minutes(), get_seconds());
            break;
        case tm_ssmmhh:
            std::printf("%2u:%2u:%2u\n",
                        get_seconds(), get_minutes(), get_hours());
            break;
        case tm_smh:
            std::printf("%u:%u:%u\n",
                        get_seconds(), get_minutes(), get_hours());
            break;
        default:
            break;
        }
    }
    ClockShow(unsigned tc = 0, time_format tf = tm_hhmmss)
    {
        this->time_current = tc;
        this->format = tf;
    }

private:
    time_format format{tm_hhmmss};
};

int main(void)
{
    unsigned tc;
    std::cin >> tc;
    ClockShow clock{tc, ClockShow::tm_hms};

    clock.show_time();
    return 0;
}