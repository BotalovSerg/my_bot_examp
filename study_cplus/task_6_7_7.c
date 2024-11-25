#include <stdio.h>
#include <string.h>

void to_world(char str[])
{
    char symbols[] = "AJS2BKT3CLU4DMV5ENW6FOX7GPY8HQZ9IR10 ";
    char *morse[] = {".-", ".---", "...", "..---", "-...", "-.-", "-",
                     "...--", "-.-.", ".-..", "..-", "....-", "-..", "--",
                     "...-", ".....", ".", "-.", ".--", "-....", "..-.",
                     "---", "-..-", "--...", "--.", ".--.", "-.--",
                     "---..", "....", "--.-", "--..", "----.", "..", ".-.",
                     ".----", "-----", "-...-"};
    char *ptr = str;
    while (ptr != NULL)
    {
        char *p = strchr(ptr, ' ');
        int len_copy = strlen(ptr) - ((p) ? strlen(p) : 0);
        char tmp[10] = {0};
        strncpy(tmp, ptr, len_copy);
        for (int i = 0; i < 37; i++)
        {
            if (strcmp(tmp, morse[i]) == 0)
            {
                printf("%c", symbols[i]);
                break;
            }
        }
        ptr = p;
        if (ptr)
        {
            ++ptr;
        }
        else
        {
            break;
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

    to_world(str);

    return 0;
}