#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TOTAL 10

void *expand_array(short *ptr, size_t *len, short fill)
{
    short *ar = realloc(ptr, *len * 2 * sizeof(short));
    if (ar == NULL)
        return ptr;

    for (int i = *len; i < *len * 2; ++i)
        ar[i] = fill;

    (*len) *= 2;
    ptr = ar;
    return ptr;
}

int main(void)
{
    short *ptr_d = calloc(TOTAL, sizeof(short));
    size_t len = TOTAL;
    if (ptr_d == NULL)
        return 0;

    int count = 0;
    while (count < TOTAL && scanf("%hd", &ptr_d[count]) == 1)
        count++;

    ptr_d = expand_array(ptr_d, &len, -1);
    for (int i = 0; i < len; ++i)
    {
        printf("%d ", ptr_d[i]);
    }

    free(ptr_d);
    return 0;
}