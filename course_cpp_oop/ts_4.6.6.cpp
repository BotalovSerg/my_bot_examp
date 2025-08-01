#include <iostream>
#include <string>

class BankAccount
{
    std::string fio;    // владелец счета
    long volume_rub{0}; // объем средств в рублях
public:
    const std::string &get_fio() const { return fio; }
    long get_volume_rub() const { return volume_rub; }
    BankAccount(std::string fio, long balance = 0)
        : fio(fio), volume_rub(balance) {}

    operator long()
    {
        return this->volume_rub;
    }

    void operator=(long value)
    {
        this->volume_rub = value;
    }
    BankAccount *operator+=(long value)
    {
        this->volume_rub += value;
        return this;
    }
    BankAccount *operator-=(long value)
    {
        this->volume_rub -= value;
        return this;
    }
};

int main(void)
{
    BankAccount a("Старостин"), b("Балакирев"), c("Царев");
    a = 123000;
    b = 12000;
    b += 8000;
    c = 54000;
    c -= 11000;
    a += b;
    a -= c;

    return 0;
}