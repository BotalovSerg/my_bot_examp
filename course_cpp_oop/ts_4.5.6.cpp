#include <iostream>

enum type_life
{
    lf_protists = 1,
    lf_plants = 2,
    lf_animals = 3,
    lf_mosses = 4,
    lf_flowering = 5,
    lf_worms = 6,
    lf_mammals = 7,
    lf_human = 8,
    lf_monkeys = 9
};

class Protists
{
    const type_life type{lf_protists}; // вид живого организма
public:
    virtual const type_life get_type() const { return type; }
    virtual ~Protists() {}
};

class Plants : public Protists
{
public:
    virtual const type_life get_type() const override { return lf_plants; }
    virtual ~Plants() {}
};
class Mosses : public Plants
{
public:
    virtual const type_life get_type() const override { return lf_mosses; }
    virtual ~Mosses() {}
};
class Flowering : public Plants
{
public:
    virtual const type_life get_type() const override { return lf_flowering; }
    virtual ~Flowering() {}
};

class Animals : public Protists
{
public:
    virtual const type_life get_type() const override { return lf_animals; }
    virtual ~Animals() {}
};

class Worms : public Animals
{
public:
    virtual const type_life get_type() const override { return lf_worms; }
    virtual ~Worms() {}
};
class Mammals : public Animals
{
public:
    virtual const type_life get_type() const override { return lf_mammals; }
    virtual ~Mammals() {}
};

class Human : public Mammals
{
public:
    virtual const type_life get_type() const override { return lf_human; }
    virtual ~Human() {}
};
class Monkeys : public Mammals
{
public:
    virtual const type_life get_type() const override { return lf_monkeys; }
    virtual ~Monkeys() {}
};

int main(void)
{
    Protists *life[]{
        new Plants(),
        new Flowering(),
        new Flowering(),
        new Monkeys(),
        new Animals(),
        new Worms(),
        new Worms(),
        new Human(),
        new Monkeys(),
        new Mammals(),
        new Animals(),
        new Animals(),
    };
    size_t sz_an{0}, sz_mn{0};
    for (size_t i = 0; i < std::size(life); ++i)
    {
        if (life[i]->get_type() == lf_animals)
            sz_an++;
        if (life[i]->get_type() == lf_monkeys)
            sz_mn++;
    }

    Animals **lf_lst1 = new Animals *[sz_an];
    Monkeys **lf_lst2 = new Monkeys *[sz_mn];

    int count1{0}, count2{0};
    for (size_t i = 0; i < std::size(life); ++i)
    {
        if (life[i]->get_type() == lf_animals)
            lf_lst1[count1++] = (Animals *)life[i];
        if (life[i]->get_type() == lf_monkeys)
            lf_lst2[count2++] = (Monkeys *)life[i];
    }

    // __ASSERT_TESTS__ // макроопределение для тестирования (не убирать и должно идти непосредственно перед return 0 или перед освобождением памяти)

    delete[] lf_lst1;
    delete[] lf_lst2;

    return 0;
}