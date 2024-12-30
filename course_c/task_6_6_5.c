#include <stdio.h>
#define MAX_SIZE 20

void reverse(short arr[], int cnt)
{
    int start = 0, end = cnt - 1, midl = cnt / 2;
    while (start < midl)
    {
        int tmp = arr[start];
        arr[start] = arr[end];
        arr[end] = tmp;
        start++;
        end--;
    }
}

int main(void)
{
    short digs[MAX_SIZE];
    int count = 0;
    while (count < MAX_SIZE && scanf("%hd", &digs[count]) == 1)
        count++;

    reverse(digs, count);
    for (int i = 0; i < count; ++i)
    {
        printf("%d ", digs[i]);
    }

    return 0;
}