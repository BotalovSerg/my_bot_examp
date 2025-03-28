#include <iostream>
#include <string>

class Item
{
    std::string name;        // название программы
    unsigned short duration; // длительность в минутах
public:
    Item(std::string name = "", unsigned short duration = 0) : name(name), duration(duration) {}
    std::string &get_name()
    {
        return name;
    }
    unsigned short get_duration()
    {
        return duration;
    }
};

class TVProg
{
    enum
    {
        max_length = 100
    };
    Item items[max_length]; // программы
    int count{0};           // число программ
public:
    void append(const Item &it)
    {
        if (count < max_length)
        {
            items[count] = it;
            count++;
        }
    }
    void append(const Item *lst, int length)
    {
        for (int i = count, j = 0; j < length && i < max_length; i++, j++)
        {
            items[i] = lst[j];
            count++;
        }
    }
    Item *get_list() { return items; }
    int get_count() { return count; }
    TVProg() = default;
    TVProg(const Item *lst, int len)
    {
        append(lst, len);
    }
};

int main(void)
{
    Item lst[6] = {
        {"Новости", 20},
        {"Модный приговор", 50},
        {"Жить здорово!", 60},
        {"Информационный канал", 15},
        {"Новости", 15},
        {"Давай поженимся!", 70}};

    TVProg tv(lst, 6);
    return 0;
}