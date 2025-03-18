#include <iostream>
#include <cstdlib>
#include <string.h>

class Vector3D
{
    int x, y, z;

public:
    Vector3D(const char *str_vars)
    {
        // char *y_ptr = strchr(str_vars, ' ');
        // char *z_ptr = strchr(++y_ptr, ' ');

        // x = atoi(str_vars);
        // y = atoi(y_ptr);
        // z = atoi(z_ptr);
        x = atof(str_vars);
        while (*str_vars && *str_vars++ != ' ')
            ;
        y = atof(str_vars);
        while (*str_vars && *str_vars++ != ' ')
            ;
        z = atof(str_vars);
    }
    Vector3D(int arr[]) : x(arr[0]), y(arr[1]), z(arr[2]) {}
    void get_coords(int &a, int &b, int &c)
    {
        a = x;
        b = y;
        c = z;
    }
};

int main(void)
{
    Vector3D v1 = "1 2 -5";            // x=1, y=2, z=-5
    Vector3D v2 = "1.5 2.2 -5.7";      // x=1, y=2, z=-5
    Vector3D v3 = "1.5 2.2 -5.7 data"; // x=1, y=2, z=-5

    int coords_1[] = {2, 4, 7}, coords_2[] = {5, 3, 1, 0, 20};
    Vector3D v4 = coords_1; // x=2, y=4, z=7
    Vector3D v5 = coords_2; // x=5, y=3, z=1

    return 0;
}