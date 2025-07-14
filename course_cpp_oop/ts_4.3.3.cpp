#include <iostream>
#include <string>

class SmartPhone
{
    SmartPhone() = delete;

protected:
    std::string model;
    double weight{0.0};

public:
    SmartPhone(std::string m, double w) : model(m), weight(w) {}
    const std::string &get_model() const { return model; }
    double get_weight() const { return weight; }
};

class IPhone : public SmartPhone
{
    int memory_volume{0};
    int display_size{0};

public:
    IPhone(std::string model, double weight, int memory, int display_size)
        : SmartPhone(model, weight), memory_volume(memory), display_size(display_size) {}
    void get_info(int &memory, int &size)
    {
        memory = memory_volume;
        size = display_size;
    }
};

int main(void)
{
    IPhone iPhone12{"iPhone12", 0.17, 64000, 11};
    return 0;
}