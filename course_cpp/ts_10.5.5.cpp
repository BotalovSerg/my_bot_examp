#include <iostream>

struct box
{
    int a, b, c;
    box()
    {
        std::cout << "Empty box" << std::endl;
    }
    box(int a, int b, int c)
    {
        this->a = a;
        this->b = b;
        this->c = c;
        printf("Box: %d, %d, %d\n", a, b, c);
    }
};

struct vector
{
    int x, y, z;
    ~vector()
    {
        printf("Deleted vector: %d, %d, %d\n", x, y, z);
    }
};

int main(void)
{
    int x, y, z;
    std::cin >> x >> y >> z;

    vector *p_v = new vector{x, y, z};
    box *ar_box = new box[5]{{1, 2, 3}, {6, 2, 1}, {0, 0, 0}, {11, 13, 19}, {23, 5, 7}};
    //__ASSERT_TESTS__ // макроопределение для тестирования (не убирать и должно идти непосредственно перед return 0)

    delete[] ar_box;
    delete p_v;
    return 0;
}