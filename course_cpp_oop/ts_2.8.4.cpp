#include <iostream>

enum
{
    max_size = 5
};

class DataThree
{
    static DataThree *instance_ptr;
    static int counter;
    DataThree(const DataThree &) = delete;
    DataThree() = default;

public:
    static DataThree *get_new_data()
    {
        if (instance_ptr == nullptr)
        {
            instance_ptr = new DataThree();
            ++counter;
            return instance_ptr;
        }
        else if (instance_ptr && counter < 3)
        {
            instance_ptr = new DataThree();
            ++counter;
            return instance_ptr;
        }

        return instance_ptr;
    }
    ~DataThree() { instance_ptr = nullptr; }
};

DataThree *DataThree::instance_ptr = nullptr;
int DataThree::counter = 0;

int main(void)
{
    DataThree *ptr_dates[max_size];

    for (size_t i = 0; i < max_size; i++)
    {
        ptr_dates[i] = DataThree::get_new_data();
    }

    for (size_t i = 0; i < 3; i++)
    {
        delete ptr_dates[i];
    }

    return 0;
}