#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define TOTAL 10

int main(void)
{
    char str[TOTAL][50], *p_sort[TOTAL] = {0};
    int count = 0, id = 0, price = 0;
    double w = 0;
    char name[20];
    while (count < TOTAL && fgets(str[count], sizeof(str) - 1, stdin))
    {
        char *ptr_n = strrchr(str[count], '\n');
        if (ptr_n != NULL)
            *ptr_n = '\0';
        p_sort[count] = str[count];
        count++;
    }

    for (int i = 0; i < count - 1; ++i)
    {
        sscanf(p_sort[i], "%s %d; %d; %lf", name, &id, &price, &w);
        for (int j = i + 1; j < count; ++j)
        {
            int j_id = 0, j_price = 0;
            double j_w = 0;
            char j_name[20];
            sscanf(p_sort[j], "%s %d; %d; %lf", j_name, &j_id, &j_price, &j_w);
            if (j_w > w)
            {
                char *tmp;
                tmp = p_sort[i];
                p_sort[i] = p_sort[j];
                p_sort[j] = tmp;
                sscanf(p_sort[i], "%s %d; %d; %lf", name, &id, &price, &w);
            }
        }
    }

    for(int i = 0; i < count; ++i) {
        sscanf(p_sort[i], "%s %d; %d; %lf", name, &id, &price, &w);
        printf("%s ", name);
    }

    return 0;
}