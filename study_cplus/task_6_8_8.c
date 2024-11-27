#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define SIZE 20

int get_data_csv(double arr[], size_t len, char *str)
{
    char *ptr = strchr(str, ' ');
    size_t indx = 0;
    for (; ptr != NULL && indx < len; ++ptr)
    {
        char *p = strchr(ptr, ';');
        int max_len_copy = strlen(ptr) - ((p) ? strlen(p) : 0);
        char tmp[10] = {0};
        strncpy(tmp, ptr, max_len_copy);
        arr[indx++] = atof(tmp);
        if (p == NULL)
            break;
        ptr = p;
    }
    return indx;
}

int main(void)
{
    char str[100] = {0};
    double arr[SIZE] = {0};
    fgets(str, sizeof(str) - 1, stdin);
    char *ptr_n = strrchr(str, '\n');
    if (ptr_n != NULL)
        *ptr_n = '\0';

    get_data_csv(arr, SIZE, str);

    return 0;
}