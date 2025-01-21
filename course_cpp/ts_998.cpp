#include <iostream>
#include <string>

using std::cin;
using std::cout;
using std::endl;
using std::string;

int main(void)
{
    string in_str;
    string result;
    getline(cin, in_str);
    for (int i = 0; i < in_str.size(); ++i)
    {
        if (in_str[i] == '-')
        {
            result += in_str[i];
            while (in_str[++i] == '-')
            {
                /* code */
            }
            result += in_str[i];
        }
        else
        {
            result += in_str[i];
        }
    }
    cout << result << endl;
    return 0;
}
