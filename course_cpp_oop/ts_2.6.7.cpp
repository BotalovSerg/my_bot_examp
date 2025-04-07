#include <iostream>

class Thing
{
    long id{0};
    int price{0};
    double weight{0.0};

    bool check_price(int x);
    bool check_weight(double x);

public:
    void get_info(long &id, int &price, double &weight);
    Thing() = default;
    Thing(long id, int price, double weight) : id(id)
    {
        if (check_price(price))
        {
            this->price = price;
        }
        else
        {
            this->price = 0;
        }
        if (check_weight(weight))
        {
            this->weight = weight;
        }
        else
        {
            this->weight = 0;
        }
    }
};

bool Thing::check_price(int x)
{
    return x >= 0;
}

bool Thing::check_weight(double x)
{
    return x >= 0;
}

void Thing::get_info(long &id, int &price, double &weight)
{
    id = this->id;
    price = this->price;
    weight = this->weight;
}

int main(void)
{
    Thing th{5, 53403, 87.4};

    // __ASSERT_TESTS__ // макроопределение для тестирования (не убирать и должно идти непосредственно перед return 0 или перед освобождением памяти)

    return 0;
}