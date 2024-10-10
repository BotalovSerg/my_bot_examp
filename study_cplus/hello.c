#include <stdio.h>

void strip_string(char *str, int max_len)
{
    int count = 0;
    while (*str++ != '\0' && count++ < max_len)
        ;

    if (count > 1)
    {
        str -= 2;
        if (*str == '\n')
            *str = '\0';
    }
}

int main(void)
{
    char str[100];
    int indx = 0, count = 0, start = 0, end = 0;
    fgets(str, sizeof(str), stdin);
    strip_string(str, sizeof(str));

    while (str[indx] != '\0')
    {
        if (str[indx] != ' ')
        {
            int i = indx;
            start = indx;
            while (str[i] != ' ' && str[i + 1] != '\0')
            {
                ++i;
            }
            indx = i;
            end = i;
            count += 1;
        }
        ++indx;
        if (count == 2)
        {
            if (end == start)
                printf("%c", start[start]);
            for (; start < end; ++start)
            {
                printf("%c", str[start]);
            }
            return 0;
        }
    }

    puts("no");

    return 0;
}