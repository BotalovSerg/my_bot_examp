#include <iostream>
#include <string>

class Airplane
{
    Airplane() = delete;

protected:
    std::string model;
    unsigned max_speed{0};
    int length{0};

public:
    Airplane(std::string model, unsigned max_speed, int length)
        : model(model), max_speed(max_speed), length(length) {}
    const std::string &get_model() const { return model; } // возвращает поле model
    unsigned get_max_speed() const { return max_speed; }   // возвращает поле max_speed
    int get_length() const { return length; }              // возвращает поле length
};

class MS21 : public Airplane
{

    std::string drive_model; // модель двигателя
    double weight{0.0};      // вес
public:
    MS21(std::string model, unsigned max_speed, int length, std::string drive_model, double weight)
        : Airplane(model, max_speed, length), drive_model(drive_model), weight(weight) {}
    void get_info(std::string &drive, double &weight)
    {
        drive = drive_model;
        weight = this->weight;
    }
};

int main(void)
{
    MS21 ms21{"MS 21", 1000, 212, "PD-14", 11.3};

    // __ASSERT_TESTS__ // макроопределение для тестирования (не убирать и должно идти непосредственно перед return 0 или перед освобождением памяти)

    return 0;
}