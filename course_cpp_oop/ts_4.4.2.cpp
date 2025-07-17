#include <iostream>
#include <iomanip>

class FunctionInterface
{
public:
    virtual double func(double arg) { return 0; }
    virtual double operator()(double arg) { return 0; }
};

class LinearFunction : public FunctionInterface
{
    double k{0.0}; // угловой коэффициент
    double b{0.0}; // смещение
public:
    virtual double func(double arg) { return k * arg + b; }
    virtual double operator()(double arg) { return k * arg + b; }
    LinearFunction(double k, double b) : k(k), b(b) {}
};

class ReluFunction : public FunctionInterface
{
public:
    ReluFunction() {}
    virtual double func(double arg) { return (arg > 0) ? arg : 0; }
    virtual double operator()(double arg) { return (arg > 0) ? arg : 0; }
};

int main(void)
{
    FunctionInterface *funcs[3]{nullptr};
    LinearFunction *ptr_lf_1 = new LinearFunction{0.5, 0};
    LinearFunction *ptr_lf_2 = new LinearFunction{1.2, -5.4};
    ReluFunction *ptr_rf = new ReluFunction;
    funcs[0] = ptr_lf_1;
    funcs[1] = ptr_lf_2;
    funcs[2] = ptr_rf;
    double arg;
    std::cin >> arg;

    std::cout << std::fixed << std::setprecision(2)
              << funcs[0]->func(arg) << " "
              //   << (*funcs[0])(arg) << " "
              << funcs[1]->func(arg) << " "
              << funcs[2]->func(arg) << std::endl;

    delete funcs[0];
    delete funcs[1];
    delete funcs[2];

    return 0;
}