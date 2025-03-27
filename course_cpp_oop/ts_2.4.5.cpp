#include <iostream>
#include <string>

struct CPU
{
    std::string model; // модель CPU
    double fr;         // тактовая частота (в ГГц)
    CPU(std::string name_model = "", double fr = 0) : model(name_model), fr(fr) {}
};

struct Memory
{
    std::string name;          // наименование
    unsigned long long volume; // размер памяти (в байтах)
};

class MotherBoard
{
    CPU cpu;
    Memory mems[2];

public:
    MotherBoard(const CPU &cpu, const Memory &mem_1, const Memory &mem_2)
        : cpu(cpu), mems{mem_1, mem_2}
    {
    }
    CPU &get_cpu() { return cpu; }
    Memory *get_mems() { return mems; }
};

int main(void)
{
    CPU cp;
    CPU intell("Core i7", 2.7);

    // __ASSERT_TESTS__ // макроопределение для тестирования (не убирать и должно идти непосредственно перед return 0 или перед освобождением памяти)

    // здесь освобождайте память

    return 0;
}