#include <stdio.h>

int main(void)
{
    char str[50] = "Best   language  \"C\"";
    for (int i = 0; str[i] != '\0'; ++i)
    {
        if (str[i] == ' ')
        {
            if (str[i - 1] != '\n')
            {
                str[i] = '\n';
            }
            else
            {
                int tmp = i;
                while (str[tmp] == ' ')
                {
                    for (int j = tmp; str[j] != '\0'; ++j)
                    {
                        str[j] = str[j + 1];
                    }
                }
            }
        }
    }
    return 0;
}