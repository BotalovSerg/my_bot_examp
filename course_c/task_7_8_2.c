#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct tag_obj
{
    char url[1024];
    struct tag_obj *next;

} OBJ;

OBJ *push(OBJ *top, const char *url)
{
    OBJ *p = malloc(sizeof(OBJ));
    p->next = top;
    strcpy(p->url, url);

    return p;
}

OBJ *pop(OBJ *top)
{

    if (top == NULL)
    {
        return top;
    }
    OBJ *p_next = top->next;
    free(top);
    return p_next;
}

int main(void)
{
    OBJ *top = NULL;

    top = push(top, "https://proproprogs.ru/c_base/c_etapy-translyacii-programmy-v-mashinnyy-kod-standarty");
    top = push(top, "https://proproprogs.ru/c_base/c_struktura-i-ponimanie-raboty-programmy-hello-world");
    top = push(top, "https://proproprogs.ru/c_base/c_dvoichnaya-shestnadcaterichnaya-i-vosmerichnaya-sistemy-schisleniya");
    top = push(top, "https://proproprogs.ru/c_base/c_lokalnye-i-globalnye-peremennye");
    top = push(top, "https://proproprogs.ru/c_base/c_perechisleniya-enum-direktiva-typedef");

    while (top)
    {
        top = pop(top);
    }

    return 0;
}