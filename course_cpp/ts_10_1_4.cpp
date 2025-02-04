#include <iostream>
#include <iomanip>

struct book
{
    char title[200];
    char author[100];
    int price, npages;

    double price_per_page() const { return static_cast<double>(price) / npages; }
};

int main(void)
{
    const int MAX_BOOKS = 10;
    book lib[MAX_BOOKS];
    int count = 0;

    for (int i = 0; i < MAX_BOOKS; ++i)
    {
        if (std::cin.eof())
        {
            break;
        }
        std::cin.getline(lib[i].title, 200);
        std::cin.getline(lib[i].author, 100);
        std::cin >> lib[i].price >> lib[i].npages;
        std::cin.ignore();
        count++;
    }

    for (int i = 0; i < count; ++i)
    {
        std::cout << std::fixed << std::setprecision(2) << lib[i].price_per_page() << " ";
    }

    std::cout << std::endl;

    return 0;
}