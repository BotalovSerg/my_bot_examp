#include <iostream>
#include <cstdlib>

class Point {
    int x, y;
public:
    int get_x() { return x; }
    int get_y() { return y; }

    Point(char* str) {
        char* ptr=str;
        while (*ptr != ' ') {
            ptr++;
        }
        x = atoi(str);
        y = atoi(ptr);
    }
};