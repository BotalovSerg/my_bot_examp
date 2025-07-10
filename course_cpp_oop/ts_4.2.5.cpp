#include <iostream>
#include <string>

class Thing
{
protected:
    std::string name;
    int price{0};

public:
    void set_base_info(const std::string &name, int &price)
    {
        this->name = name;
        this->price = price;
    }
    void get_base_info(std::string &name, int &price)
    {
        name = this->name;
        price = this->price;
    }
};

class TV : public Thing
{
    int size{0};
    double weight{0.0};

public:
    TV(std::string name, int price, int size, double weight) : size(size), weight(weight)
    {
        this->name = name;
        this->price = price;
    }
    void get_data(std::string &name, int &price, int &size, double &weight)
    {
        name = this->name;
        price = this->price;
        size = this->size;
        weight = this->weight;
    }
};

class Book : public Thing
{
    std::string author;
    int pages{0};

public:
    Book(std::string name, int price, std::string author, int pages) : author(author), pages(pages)
    {
        this->name = name;
        this->price = price;
    }
    void get_data(std::string &name, int &price, std::string &author, int &pages)
    {
        name = this->name;
        price = this->price;
        author = this->author;
        pages = this->pages;
    }
};

class Store
{
    enum
    {
        max_total = 100
    };
    Thing *things[max_total]{nullptr};
    int total{0};

public:
    ~Store()
    {
        for (int i = 0; i < total; i++)
        {
            things[i] = nullptr;
        }
        total = 0;
    }
    void append(Thing *th)
    {
        things[total++] = th;
    }
    Thing *operator[](int index)
    {
        if (index < 0 || index > total)
        {
            return nullptr;
        }
        return things[index];
    }
    int get_total() const { return total; }
};

int main(void)
{
    Store st;
    TV tv{"Samsung", 54300, 43, 5.4};
    Book bk{"C++", 2000, "Balakirev", 543};
    TV tv1{"Sony", 97000, 80, 7.5};
    st.append(&tv);
    st.append(&bk);
    st.append(&tv1);

    return 0;
}