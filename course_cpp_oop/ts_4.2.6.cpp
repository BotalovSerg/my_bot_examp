#include <iostream>

enum type_filter_water
{
    flt_none = 0,
    flt_mechanical = 1,
    flt_aragon = 2,
    flt_calcium = 3
};

class FilterWater
{
protected:
    unsigned date{0};
    type_filter_water type{flt_none};

public:
    FilterWater(unsigned date, type_filter_water type) : date(date), type(type) {}
    unsigned get_date() const { return date; }
    type_filter_water get_type() const { return type; }
};

class Mechanical : public FilterWater
{
public:
    Mechanical(unsigned date) : FilterWater(date, flt_mechanical) {}
};

class Aragon : public FilterWater
{
public:
    Aragon(unsigned date) : FilterWater(date, flt_aragon) {}
};

class Calcium : public FilterWater
{
public:
    Calcium(unsigned date) : FilterWater(date, flt_calcium) {}
};

class GeyserClassic
{

public:
    enum
    {
        total_slots = 3
    };
    const FilterWater *operator[](int index) const
    {
        if (index < 0 || index >= total_slots || slots[index] == nullptr)
        {
            return nullptr;
        }

        return slots[index];
    }
    void add_filter(int slot_num, FilterWater *filter)
    {
        if (slot_num < 1 || slot_num > total_slots)
            return;
        int index = slot_num - 1;
        if (slots[index] == nullptr && filter != nullptr && filter->get_type() == slot_num)
        {
            slots[index] = filter;
        }
    }
    GeyserClassic(
        FilterWater *filter_1 = nullptr,
        FilterWater *filter_2 = nullptr,
        FilterWater *filter_3 = nullptr)
    {
        add_filter(1, filter_1);
        add_filter(2, filter_2);
        add_filter(3, filter_3);
    }

private:
    FilterWater *slots[total_slots]{nullptr};
};

int main(void)
{
    Mechanical filter_1(100);
    Aragon filter_2(100);
    Calcium filter_3(100);

    GeyserClassic gc_1;
    GeyserClassic gc_2(&filter_1);                       // filter_1 для 1-го слота (два остальных nullptr)
    GeyserClassic gc_3(&filter_1, &filter_2);            // filter_1 для 1-го слота; filter_2 для 2-го слота
    GeyserClassic gc_4(&filter_1, &filter_2, &filter_3); // каждый фильтр в свой слот (по порядку)

    return 0;
}