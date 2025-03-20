#include <iostream>

class VectorN
{
    int dims{0};
    short *coords{nullptr};

public:
    VectorN(int dims) : dims(dims), coords(new short[dims]{}) {}
    VectorN(short a, short b) : dims(2), coords(new short[dims]{a, b}) {}
    VectorN(short ar[], int dims)
    {
        this->coords = new short[dims]{};
        for (int i = 0; i < dims; i++)
        {
            coords[i] = ar[i];
        }
        this->dims = dims;
    }
    ~VectorN()
    {
        if (coords)
        {
            std::cout << "delete coords: ";
            for (int i = 0; i < dims; i++)
            {
                std::cout << coords[i] << (i != dims - 1 ? ' ' : '\n');
            }
            delete[] this->coords;
        }
    }
    const short *get_coords()
    {
        return coords;
    }
    int get_dims()
    {
        return dims;
    }
};

int main(void)
{
    short data[] = {4, 2, 10, 0, -5};
    VectorN v1 = 5;
    VectorN v2(1, 2);
    VectorN v3(data, std::size(data));

    return 0;
}