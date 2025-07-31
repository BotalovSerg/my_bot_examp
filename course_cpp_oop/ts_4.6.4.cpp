#include <iostream>
#include <string>

class CommonInterface
{
public:
    virtual long long get_id() const = 0;
    virtual void set_id(long long id) = 0;
    virtual ~CommonInterface() {}
};

class Thing : public CommonInterface
{
    long long id{0};
    std::string name;
    int price{0};

public:
    virtual long long get_id() const override { return id; }
    virtual void set_id(long long id) override { this->id = id; }
    const std::string &get_name() const { return name; }
    int get_price() const { return price; }
    Thing(long long id, std::string name, int price)
        : id(id), name(name), price(price) {}
    virtual ~Thing() {}
};

enum
{
    max_size = 100
};
int main(void)
{
    CommonInterface *lst[max_size]{nullptr};
    lst[0] = new Thing(4, "Book C++", 2500);
    lst[1] = new Thing(1, "Computer HP", 125000);
    lst[2] = new Thing(10, "Mouse Lg", 4300);
    lst[3] = new Thing(19, "Monitor Samsung", 9560);

    for (int i = 0; i < 4; i++)
    {
        std::cout << lst[i]->get_id() << (i < 3 ? " " : "\n");
    }

    for (int i = 0; i < 4; i++)
    {
        delete lst[i];
    }

    return 0;
}