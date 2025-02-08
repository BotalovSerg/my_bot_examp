#include <iostream>
#include <string>

// здесь объявляйте структуру
struct dtime
{
private:
    unsigned char hs, ms, sc;

public:
    dtime(unsigned char h = 0, unsigned char m = 0, unsigned char s = 0)
    {
        hs = h;
        ms = m;
        sc = s;
    }

    std::string get_time()
    {
        std::string res;
        char str[9];

        sprintf(str, "%02d:%02d:%02d", hs, ms, sc);
        res += str;

        return res;
    }

    void set_time(unsigned char hours, unsigned char minutes, unsigned char seconds)
    {
        hs = hours;
        ms = minutes;
        sc = seconds;
    }

    static dtime sum_time(const dtime &t1, const dtime &t2)
    {
        dtime res = t1;

        res.hs = t1.hs + t2.hs;
        res.ms = t1.ms + t2.ms;
        res.sc = t1.sc + t2.sc;

        if (res.sc > 59)
        {
            res.sc %= 60;
            res.ms++;
        }
        if (res.ms > 59)
        {
            res.ms %= 60;
            res.hs++;
        }

        return res;
    }
};

int main(void)
{
    // здесь продолжайте программу
    dtime tm1, tm2, time_res;
    int a, b, c;

    std::cin >> a >> b >> c;
    tm1.set_time(a, b, c);

    std::cin >> a >> b >> c;
    tm2.set_time(a, b, c);

    time_res = tm1.sum_time(tm1, tm2);

    std::cout << time_res.get_time() << std::endl;

    //__ASSERT_TESTS__ // макроопределение для тестирования (не убирать и должно идти непосредственно перед return 0)
    return 0;
}