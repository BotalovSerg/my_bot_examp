#include <iostream>
#include <cstring>

class Flower
{
    char name[100] = {0};
    int price{0};

public:
    void get_data(char *name, int &price)
    {
        strcpy(name, this->name);
        price = this->price;
    }
    Flower(const char *name, int price)
    {
        strcpy(this->name, name);
        this->price = price;
    }
    Flower(const Flower &other) = delete;
};

int main(void)
{
    Flower flower("FFFF", 120);

    // __ASSERT_TESTS__

    return 0;
}