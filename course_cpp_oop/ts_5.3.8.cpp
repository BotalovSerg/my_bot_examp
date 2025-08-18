#include <iostream>

class Vector3D
{
    enum
    {
        min_coord = -100,
        max_coord = 100
    };
    int x{0}, y{0}, z{0};
    static bool check_coords(int x, int y, int z)
    {
        if (x < min_coord || x > max_coord)
        {
            return false;
        }
        else if (y < min_coord || y > max_coord)
        {
            return false;
        }
        else if (z < min_coord || z > max_coord)
        {
            return false;
        }
        return true;
    }

public:
    void get_coords(int &x, int &y, int &z) const
    {
        x = this->x;
        y = this->y;
        z = this->z;
    }
    void set_coords(int x, int y, int z)
    {
        if (!check_coords(x, y, z))
        {
            throw -1;
        }
        this->x = x;
        this->y = y;
        this->z = z;
    }
    Vector3D() {}
    Vector3D(int x, int y, int z)
    {
        if (!check_coords(x, y, z))
        {
            throw -2;
        }
        this->x = x;
        this->y = y;
        this->z = z;
    }
    int &operator[](int index)
    {
        if (index < 0 || index > 2)
        {
            throw "Incorrect index.";
        }
        switch (index)
        {
        case 0:
            return x;
        case 1:
            return y;
        case 2:
            return z;
        default:
            throw "Incorrect index.";
        }
    }
};

int main(void)
{
    Vector3D v(10, 20, 30);

    int x = v[0];
    int y = v[1];
    int z = v[2];

    v[0] = 3;

    try
    {
        Vector3D v3(10, 1000, -500);
    }
    catch (const char *e)
    {
        std::cout << e << '\n';
    }
    catch (int code)
    {
        std::cout << code << '\n';
    }

    return 0;
}