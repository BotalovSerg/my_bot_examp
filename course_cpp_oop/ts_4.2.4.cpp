#include <iostream>
#include <string>

class Animal
{
protected:
    std::string name;
    short old{0};
};

class Cat : public Animal
{
    int color{0};
    double weight{0.0};

public:
    Cat(std::string name, short old, int color, double weight)
        : color(color), weight(weight)
    {
        this->name = name;
        this->old = old;
    }
    void get_data(std::string &name, short &old, int &color, double &weight)
    {
        name = this->name;
        old = this->old;
        color = this->color;
        weight = this->weight;
    }
};

class Dog : public Animal
{
    int height{0};
    int speed{0};

public:
    Dog(std::string name, short old, int height, int speed)
        : height(height), speed(speed)
    {
        this->name = name;
        this->old = old;
    }
    void get_data(std::string &name, short &old, int &height, int &speed)
    {
        name = this->name;
        old = this->old;
        height = this->height;
        speed = this->speed;
    }
};

int main(void)
{
    Cat cat_1{"Zeus", 5, 0, 1.2};
    Cat cat_2{"Poseidon", 7, 122, 0.9};
    Dog dog_1{"Rex", 10, 50, 32};

    return 0;
}