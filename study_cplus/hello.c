#include <stdio.h>
#include <string.h>

int main(void)
{
    char str[100] = {0};
    fgets(str, sizeof(str) - 1, stdin);
    char *ptr_n = strrchr(str, '\n');
    if (ptr_n != NULL)
        *ptr_n = '\0';

    char temp[100] = {0};
    char *ptr = strstr(str, "--");

    while (ptr)
    {
        strcpy(temp, ptr + 1);
        *ptr = '\0';
        strcat(str, temp);
        ptr = strstr(str, "--");
    }

    printf("%s\n", str);

    return 0;
}