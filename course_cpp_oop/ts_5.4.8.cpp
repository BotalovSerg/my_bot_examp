#include <iostream>

class ExceptionIndexError
{
    int row{0}, col{0};

public:
    ExceptionIndexError(int r, int c) : row(r), col(c) {}
    int get_row() const { return row; }
    int get_col() const { return col; }
};

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
            if (index_col < 0 || index_row < 0 || index_col >= size_pole || index_row >= size_pole)
            {
                throw ExceptionIndexError(index_row, index_col);
            }

            return obj->pole[index_row * size_pole + index_col];
        }
    };

public:
    const char *get_pole() const { return pole; }
    int get_size() const { return size_pole; }
    Row operator[](short index_row)
    {
        return Row(this, index_row);
    }
    void print()
    {
        for (int i = 0; i < size_pole; ++i)
        {
            for (int j = 0; j < size_pole; ++j)
                std::cout << pole[i * size_pole + j] << (j == size_pole - 1 ? "\n" : "");
        }
    }
};

int main()
{
    TicTacToe game;

    try
    {
        game[0][1] = 'o';
        game[1][1] = 'x';
        game[4][2] = 'x';
    }
    catch (const ExceptionIndexError &exc)
    {
        printf("Incorrect index: %d, %d\n", exc.get_row(), exc.get_col());
    }
    game[1][2] = 'x';
    char val = game[0][1];
    // __ASSERT_TESTS__

    return 0;
}