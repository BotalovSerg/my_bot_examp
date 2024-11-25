#include <stdio.h>
#include <string.h>

char *to_morse(char c)
{
    char symbols[] = "AJS2BKT3CLU4DMV5ENW6FOX7GPY8HQZ9IR10 ";
    char *morse[] = {".-", ".---", "...", "..---", "-...", "-.-", "-",
                     "...--", "-.-.", ".-..", "..-", "....-", "-..", "--",
                     "...-", ".....", ".", "-.", ".--", "-....", "..-.",
                     "---", "-..-", "--...", "--.", ".--.", "-.--",
                     "---..", "....", "--.-", "--..", "----.", "..", ".-.",
                     ".----", "-----", "-...-"};
    if (c >= 'a' && c <= 'z')
    {
        c = c - 32;
    }

    for (int i = 0; i < strlen(symbols); ++i)
        if (c == symbols[i])
        {
            return morse[i];
        }
}

int main(void)
{
    char str[100] = {0};
    fgets(str, sizeof(str) - 1, stdin);
    char *ptr_n = strrchr(str, '\n');
    if (ptr_n != NULL)
        *ptr_n = '\0';

    for (int i = 0; i < strlen(str); ++i)
    {
        printf((i == strlen(str) - 1) ? "%s" : "%s ", to_morse(str[i]));
    }

    return 0;
}