#include <stdio.h>

enum window_styles
{
    border = 2,
    caption = 4,
    sizeable = 8
};

int main(void)
{
    enum window_styles style = 0;
    style = border | caption;
    printf("%d\n", style);

    return 0;
}
