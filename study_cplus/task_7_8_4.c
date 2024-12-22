#include <stdio.h>
#include <stdarg.h>
#include <string.h>

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
    char fl_reserved = 0;                   // зарезервированная переменная (полезна при реализации алгоритма поиска маршрута)
} STATION;

void show(STATION *st);
void find_path(STATION *from, STATION *to, STATION *path[], int *count_st);
int vertex_in_path(STATION *v, STATION *links[], short *len_path);

void set_station_links(STATION *st, short count_links, ...)
{
    va_list arg;
    va_start(arg, count_links);

    for (int i = 0; i < count_links; ++i)
    {
        st->links[i] = va_arg(arg, STATION *);
    }
    va_end(arg);
}

int main(void)
{
    STATION st[10] = {
        {"St #1", .count_links = 2, .fl_reserved = 0},
        {"St #2", .count_links = 3, .fl_reserved = 0},
        {"St #3", .count_links = 2, .fl_reserved = 0},
        {"St #4", .count_links = 2, .fl_reserved = 0},
        {"St #5", .count_links = 2, .fl_reserved = 0},
        {"St #6", .count_links = 4, .fl_reserved = 0},
        {"St #7", .count_links = 2, .fl_reserved = 0},
        {"St #8", .count_links = 2, .fl_reserved = 0},
        {"St #9", .count_links = 4, .fl_reserved = 0},
        {"St #10", .count_links = 1, .fl_reserved = 0},
    };

    set_station_links(&st[0], st[0].count_links, &st[1], &st[2]);
    set_station_links(&st[1], st[1].count_links, &st[0], &st[3], &st[4]);
    set_station_links(&st[2], st[2].count_links, &st[0], &st[5]);
    set_station_links(&st[3], st[3].count_links, &st[1], &st[5]);
    set_station_links(&st[4], st[4].count_links, &st[1], &st[7]);
    set_station_links(&st[5], st[5].count_links, &st[2], &st[3], &st[6], &st[8]);
    set_station_links(&st[6], st[6].count_links, &st[5], &st[8]);
    set_station_links(&st[7], st[7].count_links, &st[4], &st[8]);
    set_station_links(&st[8], st[8].count_links, &st[5], &st[6], &st[7], &st[9]);
    set_station_links(&st[9], st[9].count_links, &st[8]);

    // show(st);

    STATION *path[max_path_station];
    int count_st = 0;

    find_path(&st[0], &st[9], path, &count_st);

    for (int i = 0; i < count_st; ++i)
        printf("[%s] ", path[i]->name);

    return 0;
}

void show(STATION *st)
{
    printf("   Станция  ||  Соединена с\n");
    printf("====================================\n");
    for (int i = 0; i < 10; ++i)
    {
        printf("%10s", st[i].name);
        if (st[i].count_links != 0)
        {
            printf("   || ");
            for (int j = 0; j < st[i].count_links; ++j)
                printf("%s ", st[i].links[j]->name);
        }
        putchar('\n');
    }
}

void find_path(STATION *from, STATION *to, STATION *path[], int *count_st)
{
    if (from->fl_reserved == 0)
    {
        from->fl_reserved = 1;
        path[*count_st] = from;
    }
    
    if (vertex_in_path(to, from->links, &from->count_links))
    {
        *count_st = *count_st + 1;
        path[*count_st] = to;
    }
    else if (from->links)
    {
        path[*count_st] = from;
        *count_st = *count_st + 1;
        find_path(++from, to, path, count_st);
    }
}

int vertex_in_path(STATION *v, STATION *links[], short *len_path)
{
    for (short i = 0; i < *len_path; i++)
    {
        if (strcmp(v->name, links[i]->name) == 0)
        {
            return 1;
        }
    }
    return 0;
}