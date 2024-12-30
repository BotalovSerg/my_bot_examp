#include <stdio.h>
#include <string.h>


int match_ab(const char a, const char b)
{
       
    if ((a >= '0' && a <= '9') && (b >= '0' && b <= '9'))
    {
        return a < b;
    }
    if ((a >= '0' && a <= '9'))
    {
        return 1;
    }
    if ((b >= '0' && b <= '9'))
    {
        return 0;
    }
    return a < b;
}

void sort_string(char *str, size_t max_len, int (*filter)(char, char))
{
    for (int i = 0; i < max_len - 1; ++i)
    {
        for (int j = i + 1; j < max_len; ++j)
        {
            if (filter(str[j], str[i]))
            {
                char tmp = str[i];
                str[i] = str[j];
                str[j] = tmp;
            }
        }
    }
}

int main(void)
{
    char str[100] = {0};
    fgets(str, sizeof(str) - 1, stdin);
    char *ptr_n = strrchr(str, '\n');
    if (ptr_n != NULL)
        *ptr_n = '\0';

    sort_string(str, strlen(str), match_ab);
    puts(str);

    return 0;
}