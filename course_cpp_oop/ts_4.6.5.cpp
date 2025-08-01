#include <iostream>
#include <string>

class Employee
{
public:
    virtual const std::string &get_fname() const = 0; // для получения имени сотрудника
    virtual const std::string &get_lname() const = 0; // для получения фамилии сотрудника
    virtual short get_old() const = 0;                // для получения возраста сотрудника
};

class Lector : public Employee
{
    std::string first_name, last_name;
    short old{0};
    int salary{0};

public:
    virtual const std::string &get_fname() const override { return first_name; }
    virtual const std::string &get_lname() const override { return last_name; }
    virtual short get_old() const override { return old; }
    void set_salary(int salary)
    {
        if (salary > 0)
        {
            this->salary = salary;
        }
    }
    int get_salary() const { return salary; }
    Lector(std::string fname, std::string lname, short old, int salary = 0)
        : first_name(fname), last_name(lname), old(old), salary(salary) {}
};

class Laborant : public Employee
{
    std::string first_name, last_name;
    short old{0};
    std::string job_title;

public:
    virtual const std::string &get_fname() const override { return first_name; }
    virtual const std::string &get_lname() const override { return last_name; }
    virtual short get_old() const override { return old; }
    void set_job_title(const std::string &job_title) { this->job_title = job_title; }
    const std::string &get_job_title() const { return job_title; }
    Laborant(std::string fname, std::string lname, short old, std::string j_title)
        : first_name(fname), last_name(lname), old(old), job_title(j_title) {}
    Laborant(std::string fname, std::string lname, short old)
        : first_name(fname), last_name(lname), old(old) {}
};

enum
{
    max_persons = 255
};

int main(void)
{
    Employee *staff[max_persons]{nullptr};
    staff[0] = new Lector("Sergey", "Balakirev", 33, 85000);
    staff[1] = new Laborant("Elena", "Pozdnjakova", 27, "Programmer");
    staff[2] = new Lector("Olga", "Levkina", 38, 120000);

    for (int i = 0; i < 3; i++)
    {
        std::cout << staff[i]->get_fname() << (i < 2 ? " " : "\n");
    }

    // __ASSERT_TESTS__ // макроопределение для тестирования (не убирать и должно идти непосредственно перед return 0 или перед освобождением памяти)
    for (int i = 0; i < 3; i++)
    {
        delete staff[i];
    }

    return 0;
}