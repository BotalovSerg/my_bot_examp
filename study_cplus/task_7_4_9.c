#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void get_ln(char *buffer, size_t max_len)
{
    fgets(buffer, max_len - 1, stdin);
    char *ptr_n = strrchr(buffer, '\n');
    if (ptr_n != NULL)
        *ptr_n = '\0';
}

char *merge_string(const char *str1, const char *str2)
{
    char *result = malloc(strlen(str1) + strlen(str2));
    strcpy(result, str1);
    strcat(result, str2);
    return result;
}

int main(void)
{
    char str_1[200] = {0};
    char str_2[200] = {0};

    get_ln(str_1, sizeof(str_1));
    get_ln(str_2, sizeof(str_2));
    char *res = malloc(strlen(str_1) + strlen(str_2));

    res = merge_string(str_1, str_2);
    puts(res);
    free(res);

    return 0;
}