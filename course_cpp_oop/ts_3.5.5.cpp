#include <iostream>
#include <string>

class BankAccount
{
private:
    std::string fio;
    long volume_rub{0};

public:
    BankAccount(const char *in_fio) : fio(in_fio) {}
    BankAccount(const char *in_fio, long v) : fio(in_fio), volume_rub(v) {}

    const std::string &get_fio() const
    {
        return fio;
    }
    long get_volume_rub() const
    {
        return volume_rub;
    }
    BankAccount &operator=(long volume)
    {
        this->volume_rub = volume;
        return *this;
    }
    BankAccount &operator+=(long volume)
    {
        this->volume_rub += volume;
        return *this;
    }
    BankAccount &operator-=(long volume)
    {
        this->volume_rub -= volume;
        return *this;
    }
    BankAccount &operator+=(const BankAccount &other)
    {
        this->volume_rub += other.volume_rub;
        return *this;
    }
    BankAccount &operator-=(const BankAccount &other)
    {
        this->volume_rub -= other.volume_rub;
        return *this;
    }
};

int main(void)
{
    BankAccount a("Старостин"), b("Балакирев"), c("Царев");
    a = 123000; // volume_rub = 123000 (поле fio не меняется)
    b = 12000;
    b += 8000; // volume_rub = 20000 (поле fio не меняется)
    c = 54000;
    c -= 11000; // volume_rub = 43000 (поле fio не меняется)
    a += b;     // volume_rub = 123000 + 20000 = 143000 (поле fio не меняется)
    a -= c;     // volume_rub = 143000 - 43000 = 100000 (поле fio не меняется)
    return 0;
}
