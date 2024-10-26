#include <stdio.h>
#include <string.h>

#define TOTAL 100

int main(void)
{
    char str[TOTAL];
    char name[TOTAL] = {0};
    fgets(str, sizeof(str) - 1, stdin);
    char *ptr_n = strrchr(str, '\n');
    if (ptr_n != NULL)
    {
        *ptr_n = '\0';
    }
    char *ptr = strchr(str, ' ');
    strncpy(name, str, strlen(str) - strlen(ptr));
    strcat(name, ": ");
    for (; ptr != NULL;)
    {
        char *p = strchr(++ptr, ' ');
        int max_len_copy = strlen(ptr) - ((p) ? strlen(p) : 0);
        char tmp[2] = {0};
        strncpy(tmp, ptr, max_len_copy);
        strcat(name, tmp);
        if (p != NULL)
        {
            strcat(name, ", ");
        }
        ptr = p;
    }
    puts(name);

    return 0;
}