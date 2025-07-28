#include <iostream>
#include <string>

class Equipment
{
    unsigned long uid{0};
    static int nextId;

protected:
    bool is_exists{false};

public:
    Equipment() { uid = nextId++; };
    Equipment(bool is_exists) : is_exists(is_exists) { uid = nextId++; }
    virtual ~Equipment() {}
    unsigned long get_uid() const { return uid; }
    virtual void print() const {}
};

int Equipment::nextId = 1;

class PC : public Equipment
{
    std::string model;
    int price{0};

public:
    PC(std::string model, int price, bool is_exists)
        : model(model), price(price), Equipment(is_exists) {}
    virtual ~PC() { std::cout << "~PC\n"; }
    const std::string get_model() const { return model; }
    int get_price() const { return price; }
    virtual void print() const override
    {
        printf("PC: %s, %d, %d\n", model.data(), price, is_exists);
    }
};

int main(void)
{
    PC pc("model", 1, true);
    return 0;
}