#include <stdio.h>

int main(void)
{
    int var, size, hex, oct;
    int total = 1024;
    var = size = 100;
    hex = 0x1FA;
    oct = 0123;

    char ch;

    ch = 's';
    printf("char = %c, code = %d\n", ch, ch);

    double d1, d2, d3, d4, d5;
    d1 = 10.0;
    d2 = -8.;
    d3 = -1e2;
    d4 = 5e-3;
    d5 = 123;

    float var_float;
    var_float = 10.3f;

    int size_float = sizeof(float);
    int size_char = sizeof(ch);
    int size_d1 = sizeof d1;

    printf("size_d1: %d\n", size_d1);

    return 0;
}