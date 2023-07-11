#ifndef COLOR_H
#define COLOR_H

#include <iostream>

class Color {
private:
    unsigned char r, g, b;

public:
    Color(unsigned char r = 0, unsigned char g = 0, unsigned char b = 0);

    friend std::ostream& operator<<(std::ostream& os, const Color& color);
    friend Color operator+(const Color& c1, const Color& c2);
    Color operator*(float f);

private:
    unsigned char clamp(int val);
};

#endif // COLOR_H
