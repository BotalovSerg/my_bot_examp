#include <iostream>
#include <string>

class Art
{
protected:
    short stars{0}; // количество звезд (оценка)
public:
    Art(short st = 0) : stars(st) {}
    virtual ~Art() {}
    virtual void set_stars(short vol) { stars = vol; }
    short get_stars() const { return stars; }
};

class Painting : public Art
{
    std::string title, author;

public:
    const std::string &get_title() const { return title; }
    const std::string &get_author() const { return author; }
    Painting(std::string title, std::string author)
        : title(title), author(author) {}
    virtual ~Painting() { std::cout << "~Painting\n"; }
};

class Music : public Art
{
    std::string title, composer;
    int max_stars{5};

public:
    Music(std::string title, std::string composer)
        : title(title), composer(composer) {}
    virtual ~Music() { std::cout << "~Music\n"; }
    const std::string &get_title() const { return title; }
    const std::string &get_composer() const { return composer; }
    virtual void set_stars(short vol) override
    {
        if (vol > max_stars)
        {
            stars = max_stars;
        }
        else
        {
            stars = vol;
        }
    }
};