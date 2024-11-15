#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define LEN 20

int get_data_csv(double arr[], int len, char *str)
{
    int count = 0;
    char *ptr = strchr(str, ' ');
    int indx = 0;
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
    double array[LEN] = {0};
    fgets(str, sizeof(str) - 1, stdin);
    char *ptr_n = strrchr(str, '\n');
    if (ptr_n != NULL)
        *ptr_n = '\0';

    int res = get_data_csv(array, LEN, str);
    for (int i = 0; i < res; ++i)
    {
        printf("%.2f ", array[i]);
    }

    return 0;
}