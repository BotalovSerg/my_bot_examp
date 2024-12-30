#include <stdio.h>
#include <string.h>

void strip_str(char str[], char dst[])
{

    char *to_str = str;
    int cnt = 0;
    for (int i = 0; i < strlen(to_str); ++i)
    {
        char *p = strchr(dst, to_str[i]);
        if (p)
        {
            continue;
        }
        else
        {
            str[cnt++] = to_str[i];
        }
    }
    str[cnt] = '\0';
}

int main(void)
{
    char str[100] = {0}, str2[20] = ".,-!?";
    fgets(str, sizeof(str) - 1, stdin);
    char *ptr_n = strrchr(str, '\n');
    if (ptr_n != NULL)
        *ptr_n = '\0';

    strip_str(str, str2);
    puts(str);

    return 0;
}