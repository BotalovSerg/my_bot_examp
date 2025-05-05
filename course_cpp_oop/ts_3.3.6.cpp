#include <iostream>
#include <string>

class BankAccount
{
    std::string fio;
    long volume_rub{0};

public:
    const std::string &get_fio() const
    {
        return fio;
    }
    long get_volume_rub() const
    {
        return volume_rub;
    }
    BankAccount(const char *in_fio) : fio(in_fio) {}
    BankAccount(const char *in_fio, long v) : fio(in_fio), volume_rub(v) {}
    BankAccount &operator=(long v)
    {
        this->volume_rub = v;
        return *this;
    }
};

int main(void)
{
    BankAccount a1("Balakirev");
    BankAccount a2("Pushkin", 10000);
    a1 = 51200;
    return 0;
}