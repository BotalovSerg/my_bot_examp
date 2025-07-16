#include <iostream>
#include <string>

class Furniture
{
public:
    enum type_furniture
    {
        fr_none = 0,
        fr_table = 1,
        fr_chair = 2,
        fr_closet = 3
    };

protected:
    short width{0}, height{0}, depth{0};
    type_furniture type{fr_none};

public:
    void get_dims(short &width, short &height, short &depth) const
    {
        width = this->width;
        height = this->height;
        depth = this->depth;
    }
    type_furniture get_type() const { return type; }
    Furniture(short width, short height, short depth, type_furniture type)
        : width(width), height(height), depth(depth), type(type) {}
};

class Table : public Furniture
{
    std::string model;

public:
    Table(std::string model, short width, short height, short depth)
        : model(model), Furniture(width, height, depth, fr_table) {}

    const std::string &get_model() { return model; }
};

class Chair : public Furniture
{
    int color{0};
    int weight{0};

public:
    Chair(short width, short height, short depth, int color, int weight)
        : Furniture(width, height, depth, fr_chair), color(color), weight(weight) {}
    void get_data(int &color, int &weight)
    {
        color = this->color;
        weight = this->weight;
    }
};

int main(void)
{
    Table *tb1 = new Table{"Черноземья стол 10", 10, 20, 30};
    Table *tb2 = new Table{"Белоземья стол 21", 6, 5, 22};
    Chair *cr1 = new Chair{3, 5, 7, 132, 1650};
    Chair *cr2 = new Chair{3, 6, 5, 200, 1750};
    Table *tb3 = new Table{"Бурый стол", 11, 6, 8};
    Furniture *fr_lst[] = {tb1, tb2, cr1, cr2, tb3};

    for (int i = 0; i < 5; i++)
    {
        delete fr_lst[i];
    }

    return 0;
}