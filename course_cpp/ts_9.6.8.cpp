#include <iostream>

enum
{
    matrix_size = 4
};

int main()

{
    const char symbol_f = 'f';
    const short *ptr_sh;
    int count = 0;
    const int &lnk = count;

    decltype(symbol_f) var_1 = 'd';
    decltype(&symbol_f) var_2;
    decltype(ptr_sh) var_3;
    decltype(&count) var_4 = &count;
    decltype(lnk) var_5 = count;

    short matrix[matrix_size][matrix_size] = {0};

    for (int i = 0; i < matrix_size; ++i)
    {
        for (int j = 0; j < matrix_size; ++j)
        {
            std::cin >> matrix[i][j];
            std::cout << matrix[i][j] << (j < matrix_size - 1 ? ' ' : '\n');
        }
    }

    return 0;
}