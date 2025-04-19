#include <iostream>

class BottleWater
{
    enum
    {
        max_volume = 320
    };
    unsigned volume{0};

public:
    BottleWater(unsigned volume = 0)
    {

        if (volume > max_volume)
        {
            this->volume = max_volume;
        }
        else
        {
            this->volume = volume;
        }
    }
    BottleWater operator+(const BottleWater &right)
    {
        return BottleWater(this->volume + right.volume);
    }

    unsigned get_volume() const { return volume; }
};

int main(void)
{
    BottleWater bw1(40), bw2(200);
    BottleWater res = bw1 + bw2;

    return 0;
}