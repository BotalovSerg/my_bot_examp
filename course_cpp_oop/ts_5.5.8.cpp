#include <iostream>

class ColorRGBError : public std::exception
{
protected:
    std::string msg;

public:
    ColorRGBError(const std::string &m) noexcept : msg(m) {}
    virtual ~ColorRGBError() {}
    const char *what() const noexcept override { return msg.c_str(); }
};

class ColorRGBValueError : public ColorRGBError
{
public:
    ColorRGBValueError(const std::string &m) noexcept : ColorRGBError(m) {}
};

class ColorRGBIndexError : public ColorRGBError
{
public:
    ColorRGBIndexError(const std::string &m) noexcept : ColorRGBError(m) {}
};

class ColorRGB
{
    short r{0}, g{0}, b{0};
    class Item
    {
        ColorRGB *current{nullptr};
        int index{-1};

    public:
        Item(ColorRGB *obj, int indx) : current{obj}, index{indx} {}
        short operator=(short v)
        {
            if (!current->check_value(v))
            {
                throw ColorRGBValueError("Valid values must be in the range [0; 255]");
            }
            switch (index)
            {
            case 0:
                current->r = v;
                break;
            case 1:
                current->g = v;
                break;
            case 2:
                current->b = v;
                break;
            }
            return v;
        }
        operator int()
        {
            switch (index)
            {
            case 0:
                return current->r;
            case 1:
                return current->g;
            case 2:
                return current->b;
            default:
                throw ColorRGBIndexError("Index must be in range [0; 2]");
            }
        }
    };

public:
    ColorRGB(short r = 0, short g = 0, short b = 0)
    {
        set_rgb(r, g, b);
    }
    bool check_value(short v)
    {
        if (v < 0 || v > 255)
        {
            return false;
        }
        return true;
    }
    void set_rgb(short r, short g, short b)
    {
        if (!check_value(r) || !check_value(g) || !check_value(b))
        {
            throw ColorRGBValueError("Valid values must be in the range [0; 255]");
        }

        this->r = r;
        this->g = g;
        this->b = b;
    }
    Item operator[](int index)
    {
        if (index < 0 || index > 2)
        {
            throw ColorRGBIndexError("Index must be in range [0; 2]");
        }
        return Item(this, index);
    }
};

class Root {
public:
    int id {0};
    int get_id() const { return id; }
};

class Flower_1 : virtual public Root { };
class Flower_2 : virtual public Root { };

class Rose : public Flower_1, public Flower_2 { };

int main()
{
    Rose rose;
    int res_1 = rose.get_id();
    int res_2 = rose.id;
    
    try
    {
        ColorRGB yellow{255, 201, -14};
    }
    catch (const ColorRGBIndexError &e)
    {
        std::cout << e.what() << '\n';
    }
    catch (const ColorRGBValueError &e)
    {
        std::cout << e.what() << '\n';
    }
    catch (const ColorRGBError &e)
    {
        std::cout << e.what() << '\n';
    }

    // __ASSERT_TESTS__ // макроопределение для тестирования (не убирать и должно идти непосредственно перед return 0)

    return 0;
}