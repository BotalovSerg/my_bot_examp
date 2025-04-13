#include <iostream>

class DeskTop
{
    int width{0}, height{0};
    static DeskTop *ptr_instance;
    DeskTop() = default;
    DeskTop(int w, int h) : width(w), height(h) {}

public:
    int get_width();
    int get_height();
    static DeskTop *get_instance(int, int);
    ~DeskTop() { ptr_instance = nullptr; }
};

DeskTop *DeskTop::ptr_instance = nullptr;

int DeskTop::get_width()
{
    return width;
}

int DeskTop::get_height()
{
    return height;
}

DeskTop *DeskTop::get_instance(int w, int h)
{
    if (ptr_instance == nullptr)
    {
        ptr_instance = new DeskTop(w, h);
        return ptr_instance;
    }

    return ptr_instance;
}

int main(void)
{
    DeskTop *ptr_desk{nullptr};
    ptr_desk = DeskTop::get_instance(200, 50);

    // __ASSERT_TESTS__

    delete ptr_desk;

    return 0;
}