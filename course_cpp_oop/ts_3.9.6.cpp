#include <iostream>

class CoordsND
{
    enum
    {
        max_coords = 10
    };
    int *coords{nullptr}; // массив значений координат
    int size{0};          // количество координат (не более max_coords)
public:
    CoordsND(int *lst, int sz)
    {
        size = (sz > max_coords) ? max_coords : sz;

        coords = new int[size];
        for (int i = 0; i < size; ++i)
            coords[i] = lst[i];
    }
    ~CoordsND() { delete[] coords; }

    int *get_coords() { return coords; }
    int get_size() const { return size; }

    CoordsND(const CoordsND &other)
    {
        delete[] coords;
        this->size = other.size;
        this->coords = new int(size);
        for (int i = 0; i < size; i++)
        {
            coords[i] = other.coords[i];
        }
    }
    CoordsND(CoordsND &&move) noexcept : size(move.size)
    {
        this->coords = move.coords;
        move.coords = nullptr;
    }
    CoordsND &operator=(CoordsND &right)
    {
        if (this == &right)
        {
            return *this;
        }
        delete[] coords;
        size = right.size;
        this->coords = new int(size);
        for (int i = 0; i < size; i++)
        {
            coords[i] = right.coords[i];
        }
        return *this;
    }
};