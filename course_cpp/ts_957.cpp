#include <iostream>

enum
{
    max_things = 20
};

using THING = struct
{
    char name[50];
    double weight;
};

void sort_arr_th(THING arr[], int count)
{
    for (int i = 0; i < count - 1; i++)
    {
        for (int j = i + 1; j < count; ++j)
            if (arr[j].weight < arr[i].weight)
            {
                THING tmp = arr[i];
                arr[i] = arr[j];
                arr[j] = tmp;
            }
    }
}

int main(void)
{
    THING th[max_things];
    int count = 0;
    while (std::cin >> th[count].name >> th[count].weight && count < max_things)
    {
        count++;
    }
    sort_arr_th(th, count);
    for (int i = 0; i < count; i++)
    {
        std::cout << th[i].name << ' ';
    }
    std::cout << std::endl;

    return 0;
}