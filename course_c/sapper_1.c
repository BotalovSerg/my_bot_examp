#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define SIZE 10
#define MINES 12

int get_number()
{
    return rand() % SIZE;
}

int main(void)
{
    int total = 0;
    char pg[SIZE][SIZE] = {0};
    int row = 0, colm = 0;
    bool flag = true;

    while (total < MINES)
    {
        row = get_number();
        colm = get_number();
        for (int i = -1; i < 2; ++i)
        {
            for (int j = -1; j < 2; ++j)
            {
                if ((row + i >= 0 && row + i < SIZE) && (colm + j >= 0 && colm + j < SIZE))
                {
                    if (pg[row + i][colm + j] == '*')
                    {
                        flag = false;
                    }
                }
            }
            if (!flag)
                break;
        }
        if (flag)
        {
            pg[row][colm] = '*';
            total++;
        }
        flag = true;
    }
    for (size_t i = 0; i < SIZE; i++)
    {
        for (size_t j = 0; j < SIZE; j++)
        {
            pg[i][j] == 0 ? printf("%d ", pg[i][j]) : printf("%c ", pg[i][j]);
        }
        printf("\n");
    }

    return 0;
}