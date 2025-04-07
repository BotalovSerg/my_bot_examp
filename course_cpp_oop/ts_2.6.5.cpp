#include <iostream>

class Wallet
{
    int volume{0};
    bool check_volume(int x);

public:
    void add(int vol);
    int get_volume();
    Wallet(int vol) : volume(vol) {}
};

bool Wallet::check_volume(int x)
{
    return x >= 0;
}

void Wallet::add(int vol)
{
    if (check_volume(vol))
    {
        volume += vol;
    }
}

int Wallet::get_volume()
{
    return volume;
}

int main(void)
{
    Wallet wallet(544653);
    int vl = wallet.get_volume();
    return 0;
}