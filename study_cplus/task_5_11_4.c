#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(void)
{
    char str[200] = {0};
    double csv[50] = {0};
    fgets(str, sizeof(str) - 1, stdin);
    char *ptr_n = strrchr(str, '\n');
    if (ptr_n != NULL)
        *ptr_n = '\0';
    char *ptr = strchr(str, ' ');
    int indx = 0;
    for (; ptr != NULL; ++ptr)
    {
        char *p = strchr(ptr, ';');
        int max_len_copy = strlen(ptr) - ((p) ? strlen(p) : 0);
        char tmp[10] = {0};
        strncpy(tmp, ptr, max_len_copy);
        csv[indx++] = atof(tmp);
        if (p == NULL)
            break;
        ptr = p;
    }

    for (int i; csv[i] != 0; ++i)
    {
        printf("%.2f", csv[i]);
    }

    return 0;
}