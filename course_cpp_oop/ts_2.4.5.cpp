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
    Memory(std::string name = "", unsigned long long volume = 0) : name(name), volume(volume) {}
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

    CPU cpu("CORE i5", 1.7);
    Memory mems[2]{{"Samsung", 4000000000}, {"Kingston", 8000000000}};

    MotherBoard *ptr_mb = new MotherBoard(cpu, mems[0], mems[1]);

    // __ASSERT_TESTS__ // макроопределение для тестирования (не убирать и должно идти непосредственно перед return 0 или перед освобождением памяти)

    delete ptr_mb;

    return 0;
}