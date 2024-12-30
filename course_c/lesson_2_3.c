#include <stdio.h>


int main(void)
{
    int val = getchar();
    int res = putchar(val);
    printf("\n%d\n", res);

    int var_i = 1208;
    printf("var_i_dec = %d\n", var_i);
    printf("var_i_hex = %x\n", var_i);
    printf("var_i_oct = %o\n", var_i);

    char ch = 'u';
    short sh = -55;
    int var_i = 1024;
    double var_d = 3.1415;

    // здесь продолжайте программу
    printf("%c %d %d %f", ch, sh, var_i, var_d);

    return 0;
}