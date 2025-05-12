#include <iostream>

class TicTacToe
{
    enum
    {
        size_pole = 3
    };
    char pole[size_pole * size_pole]{0};
    class Row
    {
        short index_row{0};
        TicTacToe *obj{nullptr};

    public:
        Row(TicTacToe *obj, short indx) : obj(obj), index_row(indx) {}
        char &operator[](short index_col)
        {
            return obj->pole[index_row * size_pole + index_col];
        }
    };

public:
    const char *get_pole() const { return pole; }
    int get_size() { return size_pole; }
    Row operator[](short index_row)
    {
        return Row(this, index_row);
    }
};

int main(void)
{
    TicTacToe *ptr_game = new TicTacToe;
    ptr_game->operator[](0)[0] = 'x';
    ptr_game->operator[](1)[1] = 'x';
    ptr_game->operator[](2)[2] = 'x';

    (*ptr_game)[0][1] = 'x';

    delete ptr_game;
    return 0;
}