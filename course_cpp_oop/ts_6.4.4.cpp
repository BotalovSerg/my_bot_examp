#include <iostream>

template <typename T>
class Validator
{
protected:
    std::string msg_ex;

public:
    virtual bool is_valid(T x, bool exception = true) const = 0;
    virtual ~Validator() {};
};

template <typename T>
class ValidatorRange : public Validator<T>
{
    T min_value{0}, max_value{0}; // диапазон [min_value; max_value]
public:
    ValidatorRange(std::string msg, T min_value, T max_value) : min_value(min_value), max_value(max_value)
    {
        this->msg_ex = msg;
    }
    virtual bool is_valid(T x, bool exception = true) const
    {
        if (x < min_value || x > max_value)
        {
            if (exception)
            {
                throw this->msg_ex;
            }
            return false;
        }
        return true;
    }
    virtual ~ValidatorRange() {}
};

//
class Person
{
protected:
    std::string fio;
    short old{0};

public:
    Person(const std::string &fio, short old) : fio(fio), old(old)
    {
    }
    virtual ~Person() {}
    const std::string &get_fio() const { return fio; }
    short get_old() const { return old; }
};

template <typename T>
class Array
{
public:
    enum
    {
        max_array_size = 100
    };

protected:
    T data_array[max_array_size]{0};
    int length_array{0};

public:
    Array() = default;
    Array(T *d, int size)
    {
        length_array = (size > max_array_size) ? max_array_size : size;
        for (int i = 0; i < length_array; ++i)
            data_array[i] = d[i];
    }
    virtual ~Array() {}

    T *get_data() { return data_array; }
    int get_length() { return length_array; }
};

template <typename T>
class Student : public Array<T>, public Person
{
    std::string group;

public:
    void set_group(const std::string &group) { this->group = group; }
    const std::string &get_group() const { return group; }
    Student(const std::string &fio, short old) : Person(fio, old) {}
    Student(const std::string &fio, short old, T *d, int size) : Person(fio, old), Array<T>(d, size) {}
};

int main()
{
    ValidatorRange<int> range("сообщение исключения", -10, 10);
    ValidatorRange<double> vr{"Value is outside the range [-4.5; 2.5]", -4.5, 2.5};

    try
    {
        double x;
        std::cin >> x;
        vr.is_valid(x);
    }
    catch (const std::string &e)
    {
        std::cout << e << '\n';
    }

    int marks[] = {2, 2, 5, 3, 2, 4, 3};
    char m2[] = {3, 2, 5, 5};
    Student<int> st_1("Balakirev S.M.", 78); // fio = "Balakirev S.M.", old = 78
    Student<char> st_2("Emelianov S.V.", 19, m2, std::size(m2));

    short m1[] = {3, 3, 4, 2};

    Student<short> *ptr_st = new Student<short>{"Bechterev S. A.", 52, m1, std::size(m1)};

    // __ASSERT_TESTS__ // макроопределение для тестирования (не убирать и должно идти непосредственно перед return 0)

    delete ptr_st;

    return 0;
}