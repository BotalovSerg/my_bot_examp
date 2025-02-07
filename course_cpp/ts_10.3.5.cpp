#include <iostream>
#include <cmath>

struct point3D
{
private:
    int x, y, z;

public:
    point3D()
    {
        x = 0;
        y = 0;
        z = 0;
    }
    point3D(int x, int y, int z)
    {
        this->x = x;
        this->y = y;
        this->z = z;
    }
    void get_coords(int &x, int &y, int &z)
    {
        x = this->x;
        y = this->y;
        z = this->z;
    }
};

struct line3D
{
private:
    point3D start_pt, end_pt;

public:
    line3D(point3D start_pt, point3D end_pt)
    {
        this->start_pt = start_pt;
        this->end_pt = end_pt;
    }
    ~line3D()
    {
        int x, y, z, x1, y1, z1;
        start_pt.get_coords(x, y, z);
        end_pt.get_coords(x1, y1, z1);
        printf("Deleted line: (%d, %d, %d) (%d, %d, %d)\n", x, y, z, x1, y1, z1);
    }
    double length()
    {
        int x, y, z, x1, y1, z1;
        start_pt.get_coords(x, y, z);
        end_pt.get_coords(x1, y1, z1);
        return sqrt(pow((x - x1), 2) + pow((y - y1), 2) + pow((z - z1), 2));
    }
    const point3D &get_coords_start()
    {
        return this->start_pt;
    }
    const point3D &get_coords_end()
    {
        return this->end_pt;
    }
};

int main(void)
{
    line3D line(point3D(-5, 100, 45), point3D(0, 32, -45));
    return 0;
}