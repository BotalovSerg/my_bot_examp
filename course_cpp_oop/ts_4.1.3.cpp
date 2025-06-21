#include <iostream>
#include <string>

class Animal
{
protected:
    std::string name;
    short old{0};

public:
    Animal() {}
    Animal(std::string n, short o) : name(n), old(o) {}
    const std::string &get_name() const { return name; }
    short get_old() const { return old; }
};

class Cat : public Animal
{
    int color{0};
    double weight{0.0};

public:
    Cat(std::string n, short o, int c, double w)
    {
        set_info(n, o, c, w);
    }
    int get_color() const { return color; }
    double get_weight() const { return weight; }
    void set_info(const std::string &name, short old, int color, double weight)
    {
        this->name = name;
        this->old = old;
        this->color = color;
        this->weight = weight;
    }
};

class Dog : public Animal
{
    std::string breed; // порода собаки
    short length{0};   // длина собаки
public:
    Dog(std::string n, short o, std::string b, short l)
    {
        set_info(n, o, b, l);
    }
    const std::string &get_breed() const { return breed; }
    short get_length() const { return length; }
    void set_info(const std::string &name, short old, const std::string &breed, short length)
    {
        this->name = name;
        this->old = old;
        this->breed = breed;
        this->length = length;
    }
};