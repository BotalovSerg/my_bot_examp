#include <iostream>

class IndexError
{
};

class PointND
{
    double *coords{nullptr}; // координаты точки
    size_t dims{0};          // число координат
public:
    PointND() = default;
    PointND(double *cds, size_t len) : dims(len)
    {
        coords = new double[dims];
        for (size_t i = 0; i < dims; ++i)
            coords[i] = cds[i];
    }
    PointND(const PointND &other) : dims{other.dims}
    {
        coords = new double[dims];
        for (size_t i = 0; i < dims; ++i)
            coords[i] = other.coords[i];
    }
    ~PointND() { delete[] coords; }

    size_t get_dims() const { return dims; }
    double &operator[](int index)
    {
        if (index < 0 || static_cast<size_t>(index) >= dims)
        {
            throw IndexError();
        }

        return coords[index];
    }
    PointND &operator=(const PointND &other)
    {
        if (this != &other)
        {
            delete[] coords;
            dims = other.dims;
            coords = new double[dims];
            for (size_t i = 0; i < dims; ++i)
                coords[i] = other.coords[i];
        }
        return *this;
    }
};

int main(void)
{
    double coords[] = {0.1, 0.2, 0.5, -1.4};
    PointND pt(coords, std::size(coords));

    double val = pt[1];
    pt[2] = val;

    PointND pt2;
    pt2 = pt;

    return 0;
}