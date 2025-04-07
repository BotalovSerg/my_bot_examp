#include <iostream>

class Clock
{
    unsigned tm{0};

public:
    unsigned get_time();
    Clock(unsigned tm = 0) : tm(tm) {}
};

unsigned Clock::get_time()
{
    return tm;
}

int main(void)
{
    Clock *ptr_cl = new Clock(12643);
    unsigned res = ptr_cl->get_time();
    delete ptr_cl;
    return 0;
}