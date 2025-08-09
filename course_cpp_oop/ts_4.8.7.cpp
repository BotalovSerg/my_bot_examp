#include <iostream>

class Object
{
protected:
    ~Object() {}

public:
    static void remove_object(Object *obj) { delete obj; }
};

class Human
{
public:
    virtual void set_data(int old, double weight) {}
    virtual ~Human() { puts("~Human"); }
};

class Woman : public Human
{
public:
    virtual void set_data(int old, double weight) {}
    virtual ~Woman() { puts("~Woman"); }
};

int main(void)
{
    Object *ptr_obj = new Object;
    Woman *ptr_w = new Woman();
    Human *ptr_h = ptr_w;

    // __ASSERT_TESTS__ // макроопределение для тестирования (не убирать и должно идти непосредственно перед return 0 или перед освобождением памяти)

    delete ptr_h;
    return 0;
}