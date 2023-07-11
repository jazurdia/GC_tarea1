#include "Color.h"

Color::Color(unsigned char r, unsigned char g, unsigned char b)
        : r(clamp(r)), g(clamp(g)), b(clamp(b)) {}

std::ostream& operator<<(std::ostream& os, const Color& color) {
    os << "Color(" << (int)color.r << "," << (int)color.g << "," << (int)color.b << ")";
    return os;
}

Color operator+(const Color& c1, const Color& c2) {
    return Color(c1.r + c2.r, c1.g + c2.g, c1.b + c2.b);
}

Color Color::operator*(float f) {
    return Color(r * f, g * f, b * f);
}

unsigned char Color::clamp(int val) {
    if (val < 0) return 0;
    if (val > 255) return 255;
    return val;
}
