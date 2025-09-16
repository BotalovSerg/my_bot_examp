#include <iostream>
#include <cstring>

template <typename T1, typename T2>
class Thing
{
    static inline T1 acc_uid{0};
    T1 uid{0};
    T2 name;
    int price{0};
    double weight{0.0};

public:
    Thing(T2 name, int price, double weight) : name(name), price(price), weight(weight)
    {
        uid = acc_uid++;
    }

    T1 get_uid() const { return uid; }
    T2 get_name() const { return name; }
    void get_data(int &price, double &weight)
    {
        price = this->price;
        weight = this->weight;
    }
};

template <typename T1>
class Thing<T1, char *>
{
    static inline T1 acc_uid{0};
    T1 uid{0};
    char name[100]{0};
    int price{0};
    double weight{0.0};

public:
    Thing(const char *name, int price, double weight)
    {
        strcpy(this->name, name);
        this->price = price;
        this->weight = weight;
        uid = acc_uid++;
    }

    T1 get_uid() const { return uid; }
    const char *get_name() const { return name; }
    void get_data(int &price, double &weight)
    {
        price = this->price;
        weight = this->weight;
    }
};

int main()
{
    Thing<int, char *> th{"Templates in C++", 2000, 0.13};

    // __ASSERT_TESTS__

    return 0;
}