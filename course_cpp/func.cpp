#include <iostream>
#include <string>

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::to_string;

enum
{
    max_cities = 10
};

int main()
{
    string cities[max_cities];
    string res;
    size_t count = 0;
    while (count < max_cities && cin >> cities[count])
    {
        count++;
    }
    for (string &item : cities)
    {
        if (item.size() > 5)
        {
            res += item + " ";
        }
        }
    cout << res << endl;

    // __ASSERT_TESTS__ // макроопределение для тестирования (не убирать и должно идти непосредственно перед return 0)
    return 0;
}