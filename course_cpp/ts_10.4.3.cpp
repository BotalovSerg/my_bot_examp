#include <iostream>

struct rectangle
{
    rectangle(int x0 = 0, int y0 = 0, int x1 = 0, int y1 = 0)
    {
        this->x0 = x0;
        this->y0 = y0;
        this->x1 = x1;
        this->y1 = y1;
    }
    bool is_in_rect(int x, int y)
    {
        return (this->x0 <= x && x <= this->x1 && this->y0 <= y && y <= this->y1) ? true : false;
    }
    void set_coords(int x0, int y0, int x1, int y1)
    {
        this->x0 = x0;
        this->y0 = y0;
        this->x1 = x1;
        this->y1 = y1;
    }
    void get_coords(int &x0, int &y0, int &x1, int &y1)
    {
        x0 = this->x0;
        y0 = this->y0;
        x1 = this->x1;
        y1 = this->y1;
    }

private:
    int x0, y0, x1, y1;
};

int main(void)
{
    int x, y;
    std::cin >> x >> y;
    rectangle *ptr_r = new rectangle(-5, 4, 8, 32);

    std::cout << (ptr_r->is_in_rect(x, y) ? "yes" : "no") << std::endl;

    delete ptr_r;
    return 0;
}