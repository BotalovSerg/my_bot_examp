#include <iostream>

class PhysicInterface
{
public:
    virtual void forward(int speed) = 0;  // движение вперед
    virtual void stop() = 0;              // останов
    virtual void left(double angle) = 0;  // поворот влево
    virtual void right(double angle) = 0; // поворот вправо

    virtual ~PhysicInterface() {}
};

class Car
{
protected:
    int speed{0};      // скорость
    int x{0}, y{0};    // координаты автомобиля (на карте)
    int weight{0};     // вес
    double angle{0.0}; // угол поворота
public:
    void get_coords(int &x, int &y) const
    {
        x = this->x;
        y = this->y;
    };
    int get_speed() const { return speed; }    // возвращает значение поля speed
    int get_weight() const { return weight; }  // возвращает значение поля weight
    double get_angle() const { return angle; } // возвращает значение поля angle
    Car(int x, int y, int w) : x(x), y(y), weight(w) {}
    virtual ~Car() {}
};

class Train
{
protected:
    int speed{0};      // скорость
    int x{0}, y{0};    // координаты поезда (на карте)
    int weight{0};     // вес
    double power{0.0}; // мощность
public:
    void get_coords(int &x, int &y) const
    {
        x = this->x;
        y = this->y;
    };
    int get_speed() const { return speed; }    // возвращает значение поля speed
    int get_weight() const { return weight; }  // возвращает значение поля weight
    double get_power() const { return power; } // возвращает значение поля power
    Train(int x, int y, int w, double p)
        : x(x), y(y), weight(w), power(p) {}
    virtual ~Train() {}
};

class ModelCar : public Car, public PhysicInterface
{
public:
    ModelCar(int x, int y, int w) : Car(x, y, w) {}
    virtual ~ModelCar() {}
    virtual void forward(int speed) override { this->speed = speed; }
    virtual void stop() override { this->speed = 0; }
    virtual void left(double angle) { this->angle = angle; }
    virtual void right(double angle) { this->angle = -angle; }
};

class ModelTrain : public Train, public PhysicInterface
{
public:
    ModelTrain(int x, int y, int w, double p) : Train(x, y, w, p) {}
    virtual ~ModelTrain() {}
    virtual void forward(int speed) override { this->speed = speed; }
    virtual void stop() override { this->speed = 0; }
    virtual void left(double angle) {}
    virtual void right(double angle) {}
};

int main(void)
{
    PhysicInterface *obj_lst[] = {
        new ModelCar{0, 0, 1200},
        new ModelTrain{-5, 7, 534200, 574.33},
        new ModelCar{11, 24, 1920},
        new ModelCar{-1, 12, 945},
    };

    for (int i = 0; i < 4; i++)
    {
        obj_lst[i]->forward(7);
    }

    // __ASSERT_TESTS__ // макроопределение для тестирования (не убирать и должно идти непосредственно перед return 0 или перед освобождением памяти)

    for (int i = 0; i < 4; i++)
    {
        delete obj_lst[i];
    }

    return 0;
}