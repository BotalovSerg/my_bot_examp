#include <iostream>
#include <cstring>

class GamePole
{
    int rows{0}, cols{0};
    char *pole{nullptr};
    static GamePole *ptr_instance;
    GamePole(int r, int c) : rows(r), cols(c)
    {
        pole = new char[rows * cols]{0};
    }

public:
    GamePole(const GamePole &other) = delete;
    void set_item(int row, int col, char value)
    {
        pole[row * cols + col] = value;
    }
    char get_item(int row, int col) const
    {
        return pole[row * cols + col];
    }
    const char *get_pole() const
    {
        return pole;
    }
    void get_size(int &rows, int &cols) const
    {
        rows = this->rows;
        cols = this->cols;
    }
    static GamePole *init(int r, int w)
    {
        if (ptr_instance == nullptr)
        {
            ptr_instance = new GamePole(r, w);
            return ptr_instance;
        }
        return ptr_instance;
    }

    // GamePole(const GamePole &other) : rows(other.rows), cols(other.cols)
    // {
    //     pole = new char[rows * cols];
    //     std::memcpy(pole, other.pole, rows * cols);
    // }
    // GamePole operator=(const GamePole &other)
    // {
    //     if (this == &other)
    //     {
    //         return *this;
    //     }
    //     delete[] pole;

    //     rows = other.rows;
    //     cols = other.cols;
    //     pole = new char[rows * cols];
    //     for (int i = 0; i < rows * cols; i++)
    //     {
    //         pole[i] = other.pole[i];
    //     }

    //     return *this;
    // }
    ~GamePole()
    {
        delete[] pole;
    }
};

GamePole *GamePole::ptr_instance = nullptr;

int main(void)
{
    GamePole *ptr_pl = GamePole::init(5, 10);
    ptr_pl->set_item(1, 1, '@');
    ptr_pl->set_item(4, 9, '#');
    ptr_pl->set_item(3, 2, '*');

    // gp.set_item(3, 5, '#');
    // gp.set_item(4, 2, '*');
    // gp.set_item(4, 4, '*');

    delete ptr_pl;

    return 0;
}