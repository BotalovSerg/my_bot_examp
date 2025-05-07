#include <iostream>

class PointND
{
    short *coords{nullptr}; // координаты точки
    size_t dims{0};         // число координат
    short index_out{0};

public:
    PointND() = default;
    PointND(short *cds, size_t len) : dims(len)
    {
        coords = new short[dims];
        for (size_t i = 0; i < dims; ++i)
            coords[i] = cds[i];
    }
    PointND(const PointND &other) : dims(other.dims)
    {
        coords = new short[dims];
        for (size_t i = 0; i < dims; ++i)
            coords[i] = other.coords[i];
    }
    ~PointND() { delete[] coords; }
    short &operator[](int index)
    {
        if (index < 0 || index >= dims)
        {
            return index_out;
        }
        return coords[index];
    }
    PointND &operator=(const PointND &other)
    {
        if (this == &other)
        {
            return *this;
        }
        delete[] this->coords;
        this->dims = other.dims;
        this->coords = new short[dims];
        for (size_t i = 0; i < dims; i++)
        {
            this->coords[i] = other.coords[i];
        }
        return *this;
    }
};

int main(void)
{
    short coords[] = {1, 2, 3, 4, 5};
    PointND pt1(coords, std::size(coords));

    int val = pt1[4];
    pt1[0] = val;
    PointND pt2;
    pt2 = pt1;

    return 0;
}