#include <iostream>

// class BottleWater
// {
//     enum type_assign {add_op, mun_op, mul_op, ddiv_op};
//     enum {max_volume = 640}; // максимальный объем воды
//     short volume {0}; // объем воды в бутылке
//     short _assign_op(short right, type_assign t){
//         switch(t){
//             case add_op:
//                 volume+=right; break;
//             case mun_op:
//                 volume-=right; break;
//             case mul_op:
//                 volume*=right; break;
//             case ddiv_op:
//                 volume/=right; break;
//         }
//         volume=(volume<0)?0:volume;
//         volume=(volume>max_volume)?max_volume:volume;
//         return volume;
//     }
// public:
//     BottleWater(short volume = 0) : volume(volume){}
//     short get_volume() const { return volume; }
//     operator short()const{return volume;}
//     short operator +(const BottleWater other){ return volume+other.volume;}
//     short operator +=(const BottleWater other){ return _assign_op(other.volume, add_op);}
//     short operator -=(const BottleWater other){ return _assign_op(other.volume, mun_op);}
//     short operator *=(const BottleWater other){ return _assign_op(other.volume, mul_op);}
//     short operator /=(const BottleWater other){ return _assign_op(other.volume, ddiv_op);}
// };

class BottleWater
{
    enum
    {
        max_volume = 640
    }; // максимальный объем воды
    short volume{0}; // объем воды в бутылке
public:
    BottleWater(short volume = 0) : volume(volume) {}

    BottleWater(const BottleWater &other) : volume(other.volume) {}

    short get_volume() const { return volume; }
    BottleWater operator+(const BottleWater &other)
    {
        if (volume + other.volume > max_volume)
        {
            BottleWater obj(max_volume);
            return obj;
        }
        else
        {
            BottleWater obj(volume + other.volume);
            return obj;
        }
    }
    BottleWater &operator+=(short v)
    {
        if (volume + v > max_volume)
        {
            this->volume = max_volume;
            return *this;
        }
        else
        {
            this->volume += v;
            return *this;
        }
    }
    BottleWater &operator-=(short v)
    {
        if (volume - v < 0)
        {
            this->volume = 0;
            return *this;
        }
        else
        {
            this->volume -= v;
            return *this;
        }
    }
    BottleWater &operator*=(short v)
    {
        if (volume * v > max_volume)
        {
            this->volume = max_volume;
            return *this;
        }
        else
        {
            this->volume *= v;
            return *this;
        }
    }
    BottleWater &operator/=(short v)
    {
        if (volume / v < 0)
        {
            this->volume = 0;
            return *this;
        }
        else
        {
            this->volume /= v;
            return *this;
        }
    }
    BottleWater &operator+=(const BottleWater &other)
    {
        if (volume + other.volume > max_volume)
        {
            this->volume = max_volume;
            return *this;
        }
        else
        {
            this->volume += other.volume;
            return *this;
        }
    }
    BottleWater &operator-=(const BottleWater &other)
    {
        if (volume - other.volume < 0)
        {
            this->volume = 0;
            return *this;
        }
        else
        {
            this->volume -= other.volume;
            return *this;
        }
    }
    BottleWater &operator*=(const BottleWater &other)
    {
        if (volume * other.volume > max_volume)
        {
            this->volume = max_volume;
            return *this;
        }
        else
        {
            this->volume *= other.volume;
            return *this;
        }
    }
    BottleWater &operator/=(const BottleWater &other)
    {
        if (volume / other.volume < 0)
        {
            this->volume = 0;
            return *this;
        }
        else
        {
            this->volume /= other.volume;
            return *this;
        }
    }
};

int main(void)
{

    BottleWater b1(10), b2(100);
    BottleWater res_1 = b1 + b2; // res_1: volume = 110

    b1 += 100; // volume += 100
    b1 -= 20;  // volume -= 20
    b1 *= 2;   // volume *= 2
    b1 /= 4;   // volume /= 4
    b1 += b2;  // b1.volume += b2.volume
    b1 -= b2;  // b1.volume -= b2.volume
    b1 *= b2;  // b1.volume *= b2.volume
    b1 /= b2;  // b1.volume /= b2.volume

    BottleWater bw1{40};
    BottleWater bw2{200};
    BottleWater res = bw1 + bw2;
    return 0;
}
