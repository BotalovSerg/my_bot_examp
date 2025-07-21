#include <iostream>
#include <string>

class Dish
{
protected:
    std::string name; // наименование
    int price{0};     // цена
public:
    Dish(std::string name, int price) : name(name), price(price) {}
    virtual void print_dish()
    {
        printf("Dish: %s; %d\n", name.data(), price);
    }
};

class FishDish : public Dish
{
    int weight{0};

public:
    virtual void print_dish()
    {
        printf("FishDish: %s; %d; %d\n", name.data(), price, weight);
    }
    FishDish(std::string name, int price, int weight)
        : Dish(name, price), weight(weight) {}
};

class MeatDish : public Dish
{
    short fry_type{1};
    int weight{0};

public:
    virtual void print_dish()
    {
        printf("MeatDish: %s; %d; %hd; %d\n", name.data(), price, fry_type, weight);
    }
    MeatDish(std::string name, int price, short ft, int w)
        : Dish(name, price), fry_type(ft), weight(w) {}
};

int main(void)
{
    FishDish *ptr_fd_1 = new FishDish("Устрицы", 900, 300);
    MeatDish *ptr_md_1 = new MeatDish("Бекон", 800, 2, 420);
    FishDish *ptr_fd_2 = new FishDish("Форель", 400, 210);

    Dish *dishes[3] = {ptr_fd_1, ptr_md_1, ptr_fd_2};

    for (int i = 0; i < 3; i++)
    {
        dishes[i]->print_dish();
    }

    for (int i = 0; i < 3; i++)
    {
        delete dishes[i];
    }

    return 0;
}