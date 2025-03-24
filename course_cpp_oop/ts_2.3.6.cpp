#include <iostream>
#include <string>

class Thing
{
    std::string name{""};
    double weignt{0};
    int price{0};

public:
    Thing() : name(""), weignt(0), price(0)
    {
        std::cout << "default constructor" << std::endl;
    }
    Thing(std::string str) : name(str)
    {
        std::cout << "constructor 1" << std::endl;
    }
    Thing(std::string str, double w, int p) : Thing(str)
    {
        this->weignt = w;
        this->price = p;
        std::cout << "constructor 3" << std::endl;
    }
    std::string get_name()
    {
        return name;
    }
    double get_weight()
    {
        return weignt;
    }
    int get_price()
    {
        return price;
    }
};

int main(void)
{
    Thing *ptr_th = new Thing("HP Omen", 2.3, 120000);

    // __ASSERT_TESTS__ // макроопределение для тестирования (не убирать и должно идти непосредственно перед return 0 или перед освобождением памяти)

    delete ptr_th;

    return 0;
}