#include <iostream>
#include <string>

class Student
{
    std::string fio;
    short old;
    Student operator=(Student &other) = delete;
    Student(Student &other) = delete;

public:
    void set_data(const std::string &fio, short old);
    std::string &get_fio() { return fio; }
    short get_old() { return old; }
    Student(const char *fio, short old)
    {
        this->fio = fio;
        this->old = old;
    }
};

void Student::set_data(const std::string &fio, short old)
{
    this->fio = fio;
    this->old = old;
}

int main(void)
{
    Student *ptr_st = new Student("Pushkin", 21);

    // __ASSERT_TESTS__

    delete ptr_st;

    return 0;
}