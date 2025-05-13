#include <iostream>

class Distance
{
    int dist{0};

public:
    Distance(int d) : dist(d) {}
    Distance &operator+=(int v)
    {
        this->dist += v;
        return *this;
    }
    Distance &operator-=(int v)
    {
        this->dist -= v;
        return *this;
    }
    Distance &operator*=(int v)
    {
        this->dist *= v;
        return *this;
    }
    Distance &operator/=(int v)
    {
        this->dist /= v;
        return *this;
    }
    operator int()
    {
        return dist;
    }
};

int main(void)
{
    Distance d1 = 100;
    d1 += 50;                 // dist = 150
    Distance d2 = d1 += 10;   // dist в d1 и d2 равны 150+10 = 160

    Distance sp = d1 *= 5;
    Distance ep = d1 /= 7;
    int res = sp; // возвращает значение поля dist
    return 0;
}