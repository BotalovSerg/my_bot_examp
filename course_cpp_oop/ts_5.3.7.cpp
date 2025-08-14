#include <iostream>

class Wallet
{
    enum
    {
        wallet_limit = 1000000
    }; // лимит денег в кошельке
    long volume{0}; // количество денег в кошельке
    bool check_volume(long vol)
    {
        if (vol >= 0 && vol <= wallet_limit)
        {
            return true;
        }
        throw "Value is out of bounds.";
    }

public:
    Wallet(long v = 0)
    {
        if (check_volume(v))
        {
            volume = v;
        }
    }
    long get_volume() const { return volume; }
    Wallet &operator=(long new_v)
    {
        if (check_volume(new_v))
        {
            this->volume = new_v;
        }
        return *this;
    }
    Wallet &operator+=(long v)
    {
        if (check_volume(volume + v))
        {
            this->volume += v;
        }
        return *this;
    }
    Wallet &operator-=(long v)
    {
        if (check_volume(volume - v))
        {
            this->volume -= v;
        }
        return *this;
    }
    operator long() { return volume; }
    Wallet operator+(Wallet &ohter)
    {
        if (check_volume(volume + ohter.volume))
        {
        }
        return Wallet(volume + ohter.volume);
    }
};

int main(void)
{
    Wallet w{5};
    Wallet w2{100};
    try
    {
        Wallet wl = w + w2;
        wl = 10 + w;
        wl = w2 + 5;
        wl = 100 + 600;
    }
    catch (const char *e)
    {
        std::cout << e << '\n';
    }
    std::cout << w.get_volume() << '\n';
    return 0;
}