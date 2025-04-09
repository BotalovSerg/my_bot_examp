#include <iostream>

class Window
{
    static unsigned long total;
    int width, height, color;

public:
    static unsigned long get_total() { return total; }
    void set_size(int w, int h);
    void get_size(int &w, int &h);
    int get_color();
    Window(int w, int h, int c) : width(w), height(h), color(c) { total++; }
};

unsigned long Window::total = 0;

void Window::set_size(int w, int h)
{
    width = w;
    height = h;
}

void Window::get_size(int &w, int &h)
{
    w = width;
    h = height;
}

int Window::get_color()
{
    return color;
}

int main(void)
{
    Window *ptr_wnd = new Window(200, 100, 255);

    // __ASSERT_TESTS__

    delete ptr_wnd;

    return 0;
}
