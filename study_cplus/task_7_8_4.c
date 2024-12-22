#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdarg.h>

enum
{
    name_length = 50,
    total_links = 50,
    max_path_station = 100
};

typedef struct tag_station
{
    char name[name_length];                 // название станции метро
    struct tag_station *links[total_links]; // связи станции метро с другими соседними станциями
    short count_links;                      // общее количество связей
    char fl_reserved;                       // зарезервированная переменная (полезна при реализации алгоритма поиска маршрута)
} STATION;

void set_station_links(STATION *st, int count_links, ...)
{
    va_list arg;
    va_start(arg, count_links);

    for (int i = 0; i < count_links; ++i)
    {
        STATION *res = va_arg(arg, STATION *);
        st->links[i] = res;
    }
    st->count_links = count_links;

    va_end(arg);
}

void find_path(STATION *from, STATION *to, STATION *path[], int *count_st);

int main(void)
{
    STATION st[10] = {
        {"St #1", .count_links = 0, .fl_reserved = 0},
        {"St #2", .count_links = 0, .fl_reserved = 0},
        {"St #3", .count_links = 0, .fl_reserved = 0},
        {"St #4", .count_links = 0, .fl_reserved = 0},
        {"St #5", .count_links = 0, .fl_reserved = 0},
        {"St #6", .count_links = 0, .fl_reserved = 0},
        {"St #7", .count_links = 0, .fl_reserved = 0},
        {"St #8", .count_links = 0, .fl_reserved = 0},
        {"St #9", .count_links = 0, .fl_reserved = 0},
        {"St #10", .count_links = 0, .fl_reserved = 0},
    };

    set_station_links(&st[0], 2, &st[1], &st[2]);
    set_station_links(&st[1], 3, &st[0], &st[3], &st[4]);
    set_station_links(&st[2], 2, &st[0], &st[5]);
    set_station_links(&st[3], 2, &st[1], &st[5]);
    set_station_links(&st[4], 2, &st[1], &st[7]);
    set_station_links(&st[5], 4, &st[2], &st[3], &st[6], &st[8]);
    set_station_links(&st[6], 2, &st[5], &st[8]);
    set_station_links(&st[7], 2, &st[4], &st[8]);
    set_station_links(&st[8], 4, &st[5], &st[6], &st[7], &st[9]);
    set_station_links(&st[9], 1, &st[8]);

    /*STATION* path[max_path_station];

    int count_st = 0;
    find_path(&st[0], &st[9], path, &count_st);
    for(int i = 0;i < count_st;++i)
        printf("[%s] ", path[i]->name);*/
    // __ASSERT_TESTS__ // макроопределение для тестирования (не убирать и должно идти непосредственно перед return 0)
    return 0;
}

void make_path(STATION *from, STATION *to, int cnt)
{
    from->fl_reserved = cnt;
    for (int i = 0; i < from->count_links; ++i)
    {
        if (from->links[i]->fl_reserved == 0)
            make_path(from->links[i], to, cnt + 1);
        if (from->links[i]->fl_reserved > cnt + 1)
            make_path(from->links[i], to, cnt + 1);
    }
}

void find_path(STATION *from, STATION *to, STATION *path[], int *count_st)
{
    make_path(from, to, 1);
    STATION *next = to;
    size_t indx_end = to->fl_reserved - 1;
    path[indx_end--] = next;

    *count_st = to->fl_reserved;

    while (next != from)
    {
        for (int i = 0; i < next->count_links; ++i)
        {
            if (next->links[i]->fl_reserved == next->fl_reserved - 1)
            {
                next = next->links[i];
                path[indx_end--] = next;
                break;
            }
        }
    }
}