#include <iostream>

#define IN_RANGE(A) (-100 <= (A) && (A) <= 100)


class Vector3D
{
private:
    int x, y, z;

public:
    Vector3D(int x = 0, int y = 0, int z = 0) : x(x), y(y), z(z) {}
    Vector3D(const Vector3D &other) : Vector3D(other.x, other.y, other.z)
    {
    }

    void set_coords(int a, int b, int c)
    {
        if (a >= -100 && a <= 100 && b >= -100 && b <= 100 && c >= -100 && c <= 100)
        {
            x = a;
            y = b;
            z = c;
        }
    }
    void get_coords(int &x, int &y, int &z)
    {
        x = this->x;
        y = this->y;
        z = this->z;
    }
};

int main(void)
{
    Vector3D *ptr_v1 = new Vector3D(100, -5, 7);
    Vector3D *ptr_v2 = new Vector3D(0, 12, -56);

    // __ASSERT_TESTS__ // макроопределение для тестирования (не убирать и должно идти непосредственно перед return 0 или перед освобождением памяти)

    delete ptr_v1;
    delete ptr_v2;

    return 0;
}