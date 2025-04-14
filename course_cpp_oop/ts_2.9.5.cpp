#include <iostream>

class CellItem
{
    int row{0}, col{0};
    double data{0.0};

public:
    double get_data() const { return data; }
    int get_row() const { return row; }
    int get_col() const { return col; }
    void set_data(double d)
    {
        data = d;
    }
    CellItem(int n_row, int n_col, double d = 0.0) : row(n_row), col(n_col), data(d) {}
};

int main(void)
{
    CellItem cell{5, 7, 0.79};

    return 0;
}