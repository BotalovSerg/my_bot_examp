#include <iostream>
#include <string>

class Thing
{
protected:
    std::string name;
    int price{0};

public:
    Thing(const std::string name = "", int price = 0) : name(name), price(price)
    {
    }

    const std::string &get_name() const { return name; }
    int get_price() const { return price; }
    virtual void print() {}
};

class Cart
{
    enum
    {
        max_total_thing = 100
    };
    Thing *goods[max_total_thing]{nullptr}; // товары в корзине
    int count{0};                           // текущее количество товаров
public:
    void append(Thing *th)
    {
        if (count >= max_total_thing)
            return;
        goods[count++] = th;
    }

    Thing **get_goods() { return goods; }
    int get_count() const { return count; }
    void show()
    {
        for (int i = 0; i < count; i++)
        {
            goods[i]->print();
        }
    }
};

class Table : public Thing
{
    int color{0};
    double weight{0.0};

public:
    Table(std::string name, int price, int color, double weight)
        : Thing(name, price), color(color), weight(weight) {}
    virtual void print()
    {
        printf("Table: %s, %d, %d, %.2f\n", name.data(), price, color, weight);
    }
};

class TV : public Thing
{
    int size{0};

public:
    TV(std::string name, int price, int size)
        : Thing(name, price), size(size) {}
    virtual void print()
    {
        printf("TV: %s, %d, %d\n", name.data(), price, size);
    }
};

int main(void)
{

    Table tb_1{"Стол", 12000, 0, 12.70};
    TV tv_1{"Panasonic", 54000, 43};
    TV tv_2{"Samsung", 83500, 54};
    Table tb_2{"Стол 2", 9500, 432, 10.74};

    Cart cart;
    cart.append(&tb_1);
    cart.append(&tv_1);
    cart.append(&tv_2);
    cart.append(&tb_2);
    cart.show();
    return 0;
}