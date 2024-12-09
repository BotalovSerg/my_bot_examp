#include <stdio.h>
#include <string.h>

typedef int (*FUNC_CORRECT)(const char *);

int is_correct(const char *str)
{
    if (strstr(str, "ra") || strstr(str, "Ra") || strstr(str, "RA"))
    {
        return 1;
    }
    return 0;
}

int get_correct_words(const char (*words)[50], int count_words, FUNC_CORRECT filter)
{
    int cnt = 0;
    for (int i = 0; i < count_words; ++i)
    {
        if (filter(words[i]))
        {
            ++cnt;
        }
    }
    return cnt;
}

int main(void)
{
    char arr[20][50] = {0};
    int c_w = 0;
    FUNC_CORRECT p_f = is_correct;
    double* p1 = (void *)128000, *p2 = (void *)128064;  // тип double 64 бит
    int count = p2 - p1;
    while (scanf("%49s", arr[c_w]) && c_w < 20)
    {
        ++c_w;
    }
    printf("%d", get_correct_words(arr, c_w, p_f));

    return 0;
}