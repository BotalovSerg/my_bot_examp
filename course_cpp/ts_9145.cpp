#include <iostream>
#include <string>
#include <cstring> // Для работы с Си-строками

void set_tag(char *str, size_t max_len, const char *tag = "h1")
{

    std::string open_tag = "<" + std::string(tag) + ">";
    std::string close_tag = "</" + std::string(tag) + ">";

    if (open_tag.length() + strlen(str) + close_tag.length() >= max_len)
    {
        std::cerr << "Error: String is too long to fit within the maximum length.\n";
        return;
    }

    char temp[max_len];
    snprintf(temp, max_len, "%s%s%s", open_tag.c_str(), str, close_tag.c_str());

    strncpy(str, temp, max_len - 1);
    str[max_len - 1] = '\0';
}

int main()
{
    std::string title, tag;

    std::getline(std::cin, title);
    std::getline(std::cin, tag);

    size_t max_len = title.length() + 20;

    char *p_str = new char[max_len];
    strcpy(p_str, title.c_str());
    char *p_tag = new char[tag.length() + 1];
    strcpy(p_tag, tag.c_str());

    set_tag(p_str, max_len);
    std::cout << p_str << std::endl;

    strcpy(p_str, title.c_str());

    set_tag(p_str, max_len, p_tag);
    std::cout << p_str << std::endl;

    delete[] p_str;
    delete[] p_tag;

    return 0;
}