#include <iostream>

class Wallet
{
    long volume{0};

public:
    Wallet(long v = 0) : volume(v)
    {
    }
    void set_volume(long volume)
    {
        this->volume = volume;
    }
    long get_volume()
    {
        return volume;
    }
};

int main(void)
{

    Wallet wt1{1000}, wt2;

    return 0;
}