#include <iostream>
#include <memory>

struct object
{
private:
    short data;
    object *next;

public:
    object(short d)
    {
        this->data = d;
        this->next = nullptr;
    }
    object *get_next()
    {
        return next;
    }
    short get_data()
    {
        return data;
    }
    void set_next(object *ptr)
    {
        this->next = ptr;
    }
    void set_data(short d)
    {
        this->data = d;
    }
};

using st_unique_ptr = std::unique_ptr<object>;

void push(st_unique_ptr &top, short data)
{
    auto new_obj = std::make_unique<object>(data);
    if (top)
    {
        new_obj->set_next(top.release());
    }

    top = std::move(new_obj);
}

int main(void)
{
    st_unique_ptr top;

    for (int i = 1; i <= 7; ++i)
        push(top, i);

    for (object *current = top.get(); current != nullptr; current = current->get_next())
    {
        std::cout << current->get_data() << " ";
    }

    // std::unique_ptr<object> top, ptr;
    // ptr = std::make_unique<object>(1);
    // top = std::make_unique<object>(2);

    // top->set_next(ptr.get());

    return 0;
}