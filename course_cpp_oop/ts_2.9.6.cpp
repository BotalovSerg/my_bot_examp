#include <iostream>


class BoxDims
{
    unsigned short dimension{0};
    unsigned *dims{nullptr};

public:
    BoxDims(unsigned size_1, unsigned size_2 = 0, unsigned size_3 = 0) : dimension{1}
    {
        dimension += (size_2 > 0);
        dimension += (size_3 > 0);

        dims = new unsigned[dimension];

        dims[0] = size_1;
        if (size_2)
            dims[1] = size_2;
        if (size_3)
            dims[2] = size_3;
    }

    // dimension = size_ds, dims = ds
    BoxDims(unsigned *ds, unsigned short size_ds) : dimension{size_ds}
    {
        dims = new unsigned[size_ds];
        set_dims(ds);
    }

    ~BoxDims()
    {
        if (dims)
            delete[] dims;
    }

    void set_dims(unsigned *ds)
    {
        for (unsigned i = 0; i < dimension; ++i)
            dims[i] = ds[i];
    }

    // возвращает значение поля dimension
    unsigned short get_dimension() const { return dimension; }

    // возвращает массив габаритов (поле dims)
    const unsigned *get_dims() const { return dims; }

    // возвращает объем предмета
    unsigned get_volume() const
    {
        unsigned vol = 1;

        for (unsigned i = 0; i < dimension; ++i)
            vol *= dims[i];

        return vol;
    }
};

int main(void)
{

    BoxDims box(3, 10, 5);

    // __ASSERT_TESTS__ // макроопределение для тестирования (не убирать и должно идти непосредственно перед return 0 или перед освобождением памяти)

    return 0;
}