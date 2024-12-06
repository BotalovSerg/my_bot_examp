#include <stdio.h>

enum menu_item
{
    item_exit = 1,
    item_c = 2,
    item_python = 3,
    item_java = 4
};

int main(void)
{
    int n;
    scanf("%d", &n);
    switch (n)
    {
    case item_exit:
        puts("Выход");
        break;
    case item_c:
        puts("Язык Си");
        break;
    case item_python:
        puts("Язык Python");
        break;
    case item_java:
        puts("Язык Java");
        break;
    default:
        puts("Не верный пункт меню");
        break;
    }
    return 0;
}