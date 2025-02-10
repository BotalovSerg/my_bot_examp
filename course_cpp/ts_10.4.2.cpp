#include <iostream>
#include <cstring>

struct thing
{
    unsigned long id;
    char name[50];
    unsigned int price;
    double weight;
    thing()
    {
        char *name = "";
        this->id = ++thing::count;
        this->price = 0;
        this->weight = 0;
        strncpy(this->name, name, sizeof(this->name));
    }
    thing(char *name, unsigned price = 0, double weight = 0)
    {
        this->id = ++thing::count;
        this->price = price;
        this->weight = weight;
        strncpy(this->name, name, sizeof(this->name));
    }

private:
    static unsigned long count;
};

unsigned long thing::count = 0;

int main(void)
{
    char in_name[50];
    int price;
    double w;
    std::cin >> in_name >> price >> w;

    thing *ptr_th = new thing(in_name, price, w);

    std::cout << ptr_th->price << std::endl;

    delete ptr_th;
    return 0;
}