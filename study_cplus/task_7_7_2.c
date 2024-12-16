#include <stdio.h>

struct tag_geom
{
    char type;
    int x0, y0;
    int x1, y1;
};

int main(void)
{
    struct tag_geom geom = {
        geom.type = 1,
        geom.x0 = 10,
        geom.y0 = 20,
        geom.x1 = 50,
        geom.y1 = 30,
    };
    struct tag_geom *ptr_geom = &geom;

    printf("%d %d %d %d %d", ptr_geom->type, ptr_geom->x0, ptr_geom->y0, ptr_geom->x1, ptr_geom->y1);

    return 0;
}