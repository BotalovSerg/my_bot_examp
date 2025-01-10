#include <iostream>

using THING = struct
{
    char name[50];
    unsigned int weight;
};

void sort_arr_th(THING arr[], int count)
{
    for (int i = 0; i < count - 1; i++)
    {
        for (int j = i + 1; j < count; ++j)
            if (arr[j].weight > arr[i].weight)
            {
                THING tmp = arr[i];
                arr[i] = arr[j];
                arr[j] = tmp;
            }
    }
}

int main(void)
{
    unsigned int max_weight, current_weight = 0;
    THING things[] = {
        {"карандаш", 20},
        {"зеркальце", 100},
        {"зонт", 500},
        {"рубашка", 300},
        {"брюки", 1000},
        {"бумага", 200},
        {"молоток", 600},
        {"пила", 400},
        {"удочка", 1200},
        {"расческа", 40},
        {"котелок", 820},
        {"палатка", 5240},
        {"брезент", 2130},
        {"спички", 10},
    };
    int len_th = sizeof(things) / sizeof(*things);
    sort_arr_th(things, len_th);
    std::cin >> max_weight;
    max_weight *= 1000;
    for (int i = 0; i < len_th && current_weight < max_weight; ++i)
    {
        if (current_weight + things[i].weight <= max_weight)
        {
            std::cout << things[i].name << ' ';
            current_weight += things[i].weight;
        }
    }
    std::cout << std::endl;
    return 0;
}