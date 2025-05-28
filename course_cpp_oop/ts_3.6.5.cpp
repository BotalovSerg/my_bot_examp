#include <iostream>

// class PointND {
//     short* coords {nullptr}; // координаты точки
//     size_t dims {0}; // число координат
//     short errval{0};
// public:
//     PointND() = default;
//     PointND(short* cds, size_t len) : dims(len)
//     {
//         coords = new short[dims];
//         for(size_t i = 0;i < dims; ++i)
//             coords[i] = cds[i];
//     }
//     ~PointND() { delete[] coords; }

//     size_t get_dims() const { return dims; }

//     // ====================================

//     short &operator[](int idx)
//     {
//         if (idx < 0 || idx >= (int)dims) { if (errval != 0) errval = 0; return errval; }

//         return this->coords[idx];
//     }

//     void operator++()    { for (size_t i = 0; i < dims; ++i) coords[i]++; }
//     void operator--()    { for (size_t i = 0; i < dims; ++i) coords[i]--; }
//     void operator++(int) { ++(*this); }
//     void operator--(int) { --(*this); }

//     PointND &operator+=(const PointND &other)
//     {
//         if (dims == other.dims)
//         for (size_t i = 0; i < dims; i++) coords[i] += other.coords[i];

//         return *this;
//     }

//     PointND &operator-=(const PointND &other)
//     {
//         if (dims == other.dims)
//         for (size_t i = 0; i < dims; i++) coords[i] -= other.coords[i];

//         return *this;
//     }

//     PointND &operator=(const PointND& other)
//     {
//         if (this == &other) return *this;

//         if (coords) delete [] coords;

//         dims = other.dims;

//         coords = new short[dims];

//         for (size_t i = 0; i < dims; ++i) coords[i] = other.coords[i];

//         return *this;
//     }

// };

class PointND
{
    short *coords{nullptr}; // координаты точки
    size_t dims{0};         // число координат
    int value_error = 0;

public:
    PointND() = default;
    PointND(short *cds, size_t len) : dims(len)
    {
        coords = new short[dims];
        for (size_t i = 0; i < dims; ++i)
            coords[i] = cds[i];
    }
    ~PointND() { delete[] coords; }
    size_t get_dims() const { return dims; }
    class Item
    {
        PointND *current{nullptr};
        int index{-1};

    public:
        Item(PointND *obj, int idx) : current(obj), index(idx) {}

        short operator=(short right)
        {
            if (index >= 0 && index < current->dims)
                current->coords[index] = right;

            return right;
        }

        operator short() const
        {
            if (index >= 0 && index < current->dims)
                return current->coords[index];

            return 0;
        }
    };
    Item operator[](int index)
    {
        return Item(this, index);
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
    const PointND &operator++()
    {
        for (size_t i = 0; i < dims; i++)
        {
            coords[i]++;
        }
        return *this;
    }
    PointND operator++(int)
    {
        PointND tmp = *this;
        for (size_t i = 0; i < dims; i++)
        {
            coords[i]++;
        }
        return tmp;
    }
    const PointND &operator--()
    {
        for (size_t i = 0; i < dims; i++)
        {
            coords[i]--;
        }
        return *this;
    }
    PointND operator--(int)
    {
        PointND tmp = *this;
        for (size_t i = 0; i < dims; i++)
        {
            coords[i]--;
        }
        return tmp;
    }
    const PointND &operator+=(const PointND &other)
    {
        if (dims == other.dims)
        {
            for (size_t i = 0; i < dims; i++)
            {
                coords[i] += other.coords[i];
            }
        }

        return *this;
    }
    const PointND &operator-=(const PointND &other)
    {
        if (dims == other.dims)
        {
            for (size_t i = 0; i < dims; i++)
            {
                coords[i] -= other.coords[i];
            }
        }

        return *this;
    }
};

int main(void)
{
    short coords[] = {1, 2, 3, 4, 5};
    PointND pt(coords, std::size(coords));
    int val = pt[2]; // получение значения координаты по индексу (от 0 до dims-1); если указывается не верный индекс, то возвращается 0
    pt[2] = val;     // присвоение координате с индексом indx значения val; если указывается не верный индекс, то ничего не присваивается
    PointND pt2;
    pt2 = pt;  // в объекте pt2 создается свой массив coords с поэлементным копированием данных из объекта pt1 (поле dims также копируется)
    pt2++;     // увеличение каждой координаты на 1
    ++pt2;     // увеличение каждой координаты на 1
    pt--;      // уменьшение каждой координаты на 1
    --pt;      // уменьшение каждой координаты на 1
    pt += pt2; // к координатам coords объекта pt прибавляются соответствующие координаты объекта pt2
    pt -= pt2; // из координат coords объекта pt вычитаются соответствующие координаты объекта pt2

    return 0;
}