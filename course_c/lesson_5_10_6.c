#include <stdio.h>
#include <string.h>

int main(void)
{
    char buff[50] = {0};
    char str[510] = {0};
    int i = 0;
    while (scanf("%49s", buff) && i != 10)
    {
        i++;
        if (!strstr(buff, "на"))
        {
            strcat(str, buff);            
            strcat(str, " ");
        }
    }
    str[strlen(str) - 1] = '\0';
    puts(str);

    return 0;
}