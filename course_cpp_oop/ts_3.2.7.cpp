#include <iostream>

enum type_memory
{
    mem_none = -1,
    mem_corsair = 1,
    mem_adata = 2,
    mem_kingston = 3
};

class Memory
{
    type_memory type{mem_none}; // тип (производитель) ОЗУ
    unsigned volume;            // объем ОЗУ в Мб
public:
    Memory() {}
    Memory(unsigned v) : volume(v), type(mem_none) {}
    Memory(unsigned v, type_memory t) : volume(v), type(t) {}
    friend void set_memory_data(Memory &mem, unsigned vol, type_memory tp);
    friend void get_memory_data(const Memory &mem, unsigned &vol, type_memory &tp);
    friend Memory operator+(const Memory &l, const Memory &r);
};

int main(void)
{
    Memory mem_1{8000, mem_adata}, mem_2{4000, mem_adata};
    Memory res = mem_1 + mem_2;

    // __ASSERT_TESTS__

    return 0;
}

void set_memory_data(Memory &mem, unsigned vol, type_memory tp)
{
    mem.volume = vol;
    mem.type = tp;
}

void get_memory_data(const Memory &mem, unsigned &vol, type_memory &tp)
{
    vol = mem.volume;
    tp = mem.type;
}

Memory operator+(const Memory &l, const Memory &r)
{
    if (l.type == r.type)
    {
        return Memory(l.volume + r.volume, l.type);
    }

    return l;
}

class Vector {
    int x{0}, y{0};
public:
    int get_x();
    int get_y();
};
