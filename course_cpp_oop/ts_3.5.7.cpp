#include <iostream>
#include <string>

struct BankAccount
{
    std::string fio; // ФИО счета
    long volume{0};  // объем средств на счете

    BankAccount() = default;
    BankAccount(const std::string &fio, long vol) : fio(fio), volume(vol) {}
    BankAccount &operator+=(long v)
    {
        this->volume += v;
        return *this;
    }
    BankAccount &operator-=(long v)
    {
        this->volume -= v;
        return *this;
    }
    BankAccount &operator*=(long v)
    {
        this->volume *= v;
        return *this;
    }
    BankAccount &operator/=(long v)
    {
        this->volume /= v;
        return *this;
    }
    BankAccount &operator%=(long v)
    {
        this->volume %= v;
        return *this;
    }
};

class Bank
{
    enum
    {
        max_accounts = 100
    }; // максимальное количество счетов
    BankAccount *acs{nullptr}; // массив из счетов
    size_t count{0};           // текущее количество счетов
public:
    Bank()
    {
        acs = new BankAccount[max_accounts];
    }
    Bank(BankAccount *lst, size_t size)
    {
        count = (size > max_accounts) ? max_accounts : size;

        acs = new BankAccount[max_accounts];
        for (int i = 0; i < count; ++i)
            acs[i] = lst[i];
    }
    ~Bank() { delete[] acs; }
    const BankAccount *get_accounts() const
    {
        return acs;
    }
    size_t get_count() const { return count; }
    Bank &operator+=(const BankAccount &new_act)
    {
        if (count + 1 < max_accounts)
        {
            this->acs[count++] = new_act;
            return *this;
        }
        return *this;
    }
    Bank &operator+(const BankAccount &new_act)
    {
        if (count + 1 < max_accounts)
        {
            this->acs[count++] = new_act;
            return *this;
        }
        return *this;
    }
    Bank &operator=(const Bank &other)
    {
        if (this == &other)
        {
            return *this;
        }

        delete[] this->acs;
        this->acs = new BankAccount[other.count];
        this->count = other.count;
        for (size_t i = 0; i < count; i++)
        {
            this->acs[i] = other.acs[i];
        }
        return *this;
    }
};

int main(void)
{

    Bank balbank;
    BankAccount ac("Sergey", 4320405);
    balbank += ac;          // добавляет в конец массива acs счет ac, если не превышено максимальное значение max_accounts
    balbank = balbank + ac; // добавляет в конец массива acs счет ac, если не превышено максимальное значение max_accounts
    ac += 1000;             // добавление на счет средств: volume += 1000; fio остается без изменений
    ac -= 1000;             // списание со счета средств: volume -= 1000; fio остается без изменений
    ac *= 1.5;              // увеличение средств на счете в 1.5 раза с отбрасыванием дробной части: volume *= 1.5; fio остается без изменений
    ac /= 2;                // уменьшение средств на счете в 2 раза с отбрасыванием дробной части: volume /= 2; fio остается без изменений
    ac %= 4;                // вычисление целого остатка от деления: volume %= 4; fio остается без изменений
    Bank open_b;
    open_b = balbank; // копирование счетов

    BankAccount contacts[4]{
        {"А. Дзюба", 43056},
        {"П. Гагарина", 1335395},
        {"О. Бузова", 0},
        {"Тимати", -546},
    };
    Bank my_bank{contacts, std::size(contacts)};
    return 0;
}