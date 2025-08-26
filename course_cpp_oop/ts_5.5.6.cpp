#include <iostream>
#include <string>

using uint8 = unsigned char;

class ClockError : public std::exception
{
protected:
    std::string msg;

public:
    ClockError(const std::string &m) noexcept : msg(m) {}
    virtual ~ClockError() {}
    const char *what() const noexcept override { return msg.c_str(); }
};

class ClockValueError : public ClockError
{
public:
    ClockValueError(const std::string &m) noexcept : ClockError(m) {}
};

class ClockIndexError : public ClockError
{
public:
    ClockIndexError(const std::string &m) noexcept : ClockError(m) {}
};

class Clock
{
    uint8 hours{0};
    uint8 mins{0};
    uint8 secs{0};

    class Item
    {
        Clock *current{nullptr};
        int index{-1};

    public:
        Item(Clock *obj, int indx) : current{obj}, index{indx}
        {
        }

        uint8 operator=(uint8 right)
        {
            switch (index)
            {
            case 0:
                if (right < 0 || right > 11)
                {
                    throw ClockValueError("Clock: out of range");
                }
                current->hours = right;
                break;
            case 1:
                if (right < 0 || right > 59)
                {
                    throw ClockValueError("Clock: out of range");
                }
                current->mins = right;
                break;
            case 2:
                if (right < 0 || right > 59)
                {
                    throw ClockValueError("Clock: out of range");
                }
                current->secs = right;
                break;
            }
            return right;
        }
        operator uint8() const
        {
            switch (index)
            {
            case 0:
                return current->hours;
            case 1:
                return current->mins;
            case 2:
                return current->secs;
            }
            return 0;
        }
    };

public:
    Clock(uint8 hs = 0, uint8 ms = 0, uint8 sc = 0)
    {
        if (!check_values(hs, ms, sc))
        {
            throw ClockValueError("Clock: out of range");
        }
        hours = hs;
        mins = ms;
        secs = sc;
    }
    unsigned get_time() const { return hours * 3600 + mins * 60 + secs; }
    void get_time(uint8 &hours, uint8 &mins, uint8 &secs) const
    {
        hours = this->hours;
        mins = this->mins;
        secs = this->secs;
    }
    void set_time(uint8 hours, uint8 mins, uint8 secs)
    {
        if (!check_values(hours, mins, secs))
        {
            throw ClockValueError("Clock: out of range");
        }
        this->hours = hours;
        this->mins = mins;
        this->secs = secs;
    }
    Item operator[](int indx)
    {
        if (indx < 0 || indx > 2)
        {
            throw ClockIndexError("Clock: index error");
        }

        return Item(this, indx);
    }
    bool check_values(uint8 hs, uint8 ms, uint8 sc)
    {
        if (hs < 0 || hs > 11 || ms < 0 || sc < 0 || ms > 59 || sc > 59)
        {
            return false;
        }
        return true;
    }
};

int main()
{
    try
    {
        Clock cl(10, 19, 24);
        cl[0] = 11;
        cl[-1] == 3;
    }
    catch (const ClockIndexError &e)
    {
        std::cout << e.what() << '\n';
    }
    catch (const ClockValueError &e)
    {
        std::cout << e.what() << '\n';
    }
    catch (const ClockError &e)
    {
        std::cout << e.what() << '\n';
    }

    // __ASSERT_TESTS__

    return 0;
}