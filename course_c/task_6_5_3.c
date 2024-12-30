#include <stdio.h>
#include <string.h>

int is_char(const char c)
{
    if (c >= 'a' && c <= 'z')
    {
        return 0;
    }
    if (c >= 'A' && c <= 'Z')
    {
        return 0;
    }
    return 1;
}

void copy_string(char *dst, size_t max_len_dst, const char *src, int (*copy_permision)(char))
{
    size_t src_len = strlen(src);
    int i = 0, j = 0;
    for (; i < src_len && j < max_len_dst - 1; ++i)
        if (copy_permision(src[i]))
            dst[j++] = src[i];

    dst[j] = '\0';
}

int main(void)
{
    char str[100] = {0}, str2[20] = {0};
    fgets(str, sizeof(str) - 1, stdin);
    char *ptr_n = strrchr(str, '\n');
    if (ptr_n != NULL)
        *ptr_n = '\0';

    copy_string(str2, 20, str, is_char);
    puts(str2);

    return 0;
}