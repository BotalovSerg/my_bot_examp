#include <iostream>
#include <iomanip>

class Clock
{
    unsigned time_current;

public:
    void set_time(unsigned tm)
    {
        this->time_current = tm;
    }
    unsigned get_hours()
    {
        return time_current / 3600;
    }
    unsigned get_minutes()
    {
        return time_current % 3600 / 60;
    }
    unsigned get_seconds()
    {
        return time_current % 3600 % 60;
    }
};

int main(void)
{
    unsigned tm;
    std::cin >> tm;
    Clock *ptr_cl = new Clock;
    ptr_cl->set_time(tm);

    std::cout << std::setfill('0') << std::setw(2) << ptr_cl->get_hours() << ":"
              << std::setfill('0') << std::setw(2) << ptr_cl->get_minutes() << ":"
              << std::setfill('0') << std::setw(2) << ptr_cl->get_seconds() << std::endl;

    delete ptr_cl;
    return 0;
}