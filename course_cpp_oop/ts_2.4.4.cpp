#include <iostream>

class Graph
{
    double *data{nullptr};
    int length{0};

public:
    void set_data(const double *ar, int size)
    {
        if (data)
        {
            delete[] data;
        }
        double *data = new double[size];
        for (int i = 0; i < size; i++)
        {
            data[i] = ar[i];
        }
        this->data = data;
        length = size;
    }
    double *get_data() { return data; }
    int get_length() { return length; }
    Graph() : data{nullptr}, length(0) {}
    Graph(double *ar, int size)
    {
        set_data(ar, size);
    }

    ~Graph()
    {
        if (data)
        {
            delete[] data;
        }
    }
};

int main(void)
{
    Graph *ptr_gr = new Graph;
    double coords[] = {5, 0.4, 2.7, -3.2};
    Graph gr;
    gr.set_data(coords, sizeof(coords) / sizeof(*coords));
    return 0;
}