#include <iostream>

class Distance
{
    int dist{0};

public:
    Distance(int d = 0) : dist(d) {}
    int operator()()
    {
        return dist;
    }
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
};

int main(void)
{
    Distance d1 = 100;
    d1 += 50;                 // dist = 150
    Distance d2 = d1 += 10;   // dist в d1 и d2 равны 150+10 = 160
    Distance res = d2 -= 100; // dist = 60
    Distance sp = d1 *= 5;
    Distance ep = d1 /= 7;
    int res1 = d1(); // возвращает значение поля dist

    Distance dObj{547};
    Distance &lnk_d = dObj;
    Distance &&lnk_r_d = std::move(dObj);
    lnk_r_d += 100;
    
    return 0;
}