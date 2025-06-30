#include <istream>
#include <string>

class Thing
{
private:
    unsigned id{0};
protected:
    std::string name;
    int price{0};

public:
    void set_data(const std::string &name, int price) // заносит в поля name и price переданные значения
    {
        this->name = name;
        this->price = price;
    }
    unsigned get_id() const { return id; }        // возвращает значение поля id
    std::string get_name() const { return name; } // возвращает значение поля name
    int get_price() const { return price; }       // возвращает значение поля price
    Thing() {}
    Thing(std::string name, int price) : name(name), price(price) {}
};

class ThingPhisical : public Thing
{
private:
    unsigned width{0}, height{0}, depth{0}; // габариты товара
    double weight{0.0};                     // вес товара
public:
    void set_dims(unsigned width, unsigned height, unsigned depth) // заносит в поля width, height, depth переданные значения
    {
        this->width = width;
        this->height = height;
        this->depth = depth;
    }
    void set_weight(double weight) // заносит в поле weight переданное значение
    {
        this->weight = weight;
    }

    void get_dims(unsigned &width, unsigned &height, unsigned &depth) const // возвращает габариты товара
    {
        width = this->width;
        height = this->height;
        depth = this->depth;
    }
    double get_weight() const { return weight; } // возвращает вес товара
    ThingPhisical() {}
    ThingPhisical(std::string name, int price)
    {
        this->name = name;
        this->price = price;
    }
    // ThingPhisical(const std::string& name, int price)
    //     : Thing(name, price) { }
    ThingPhisical(std::string name, int price, unsigned w, unsigned h, unsigned d, double weight)
    {
        this->name = name;
        this->price = price;
        width = w;
        height = h;
        depth = d;
        this->weight = weight;
    }
};

class ThingElectro : public Thing
{
    unsigned volume{0};

public:
    void set_volume(unsigned volume) { this->volume = volume; } // заносит в поле volume переданное значение
    unsigned get_volume() const { return volume; }              // возвращает значение поля volume
    ThingElectro() {}
    ThingElectro(std::string name, int price, unsigned volume = 0)
    {
        this->name = name;
        this->price = price;
        this->volume = volume;
    }

    // ThingElectro(const std::string& name, int price, unsigned volume = 0)
    //     : Thing(name, price), volume(volume) { }
};