#include <stdio.h>

#define SIZE 4

void transpose(short (*arr)[SIZE])
{
    for (int i = 0; i < SIZE; ++i)
    {
        for (int j = i; j < SIZE; ++j)
        {
            short t = arr[i][j];
            arr[i][j] = arr[j][i];
            arr[j][i] = t;
        }
    }
}

int main(void)
{
    short matrix[SIZE][SIZE] = {0};
    short *ptr = &matrix[0][0];
    int count = 0;
    while (count < SIZE * SIZE && scanf("%hd", ptr) == 1)
    {
        ptr++;
        count++;
    }

    transpose(matrix);
    for (int i = 0; i < SIZE; ++i)
    {
        for (int j = 0; j < SIZE; ++j)
        {
            printf((j == SIZE - 1) ? "%hd" : "%hd ", matrix[i][j]);
        }
        putchar('\n');
    }

    return 0;
}