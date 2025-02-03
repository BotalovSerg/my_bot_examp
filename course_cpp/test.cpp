#include <iostream>

struct volume
{
    int width, height, depth;
    int get_volume() { return width * height * depth; }
};

int main(void)
{
    volume data{};
    std::cin >> data.width >> data.height >> data.depth;
    std::cout << data.get_volume() << std::endl;
}
