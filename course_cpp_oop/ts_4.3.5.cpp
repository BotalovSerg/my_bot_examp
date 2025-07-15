#include <iostream>
#include <string>

class Printer
{
public:
    enum type_printer
    {
        pr_none = 0,
        pr_needle = 1,
        pr_jet = 2,
        pr_laser = 3
    };

protected:
    std::string model;
    type_printer type{pr_none};

public:
    Printer() = delete;
    Printer(std::string m, type_printer tp) : model(m), type(tp) {}
    const std::string &get_model() const { return model; } // возвращает поле model
    type_printer get_type() const { return type; }         // возвращает поле type
};

class PrinterJet : public Printer
{
    bool color{false};
    short speed{0};

public:
    PrinterJet(std::string model, bool color, short speed)
        : Printer(model, pr_jet), color(color), speed(speed) {}
    void get_data(std::string &model, type_printer &type, bool &color, short &speed)
    {
        model = this->model;
        type = this->type;
        color = this->color;
        speed = this->speed;
    }
};

class PrinterLaser : public Printer
{
    bool color{false};
    short speed{0};

public:
    PrinterLaser(std::string model, bool color, short speed)
        : Printer(model, pr_laser), color(color), speed(speed) {}
    void get_data(std::string &model, type_printer &type, bool &color, short &speed)
    {
        model = this->model;
        type = this->type;
        color = this->color;
        speed = this->speed;
    }
};

int main(void)
{

    PrinterJet *pr_j1 = new PrinterJet("Brother Jet 600", true, 5);
    PrinterJet *pr_j2 = new PrinterJet("Samsung Jet 100", true, 7);
    PrinterLaser *pr_l1 = new PrinterLaser("Canon Laser 10", false, 10);
    PrinterLaser *pr_l2 = new PrinterLaser("BaLaser 1 Pro", true, 21);

    Printer *pr_lst[4]{pr_j1, pr_l1, pr_j2, pr_l2};
    // __ASSERT_TESTS__ // макроопределение для тестирования (не убирать и должно идти непосредственно перед return 0 или перед освобождением памяти)

    for (int i = 0; i < 4; i++)
    {
        delete pr_lst[i];
    }

    return 0;
}