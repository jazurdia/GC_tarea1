#ifndef COLOR_H
#define COLOR_H

class Color {
public:
    unsigned char r, g, b;

    Color(unsigned char red = 0, unsigned char green = 0, unsigned char blue = 0)
            : r(red), g(green), b(blue) { }

    void set(unsigned char red, unsigned char green, unsigned char blue) {
        r = red;
        g = green;
        b = blue;
    }
};

#endif // COLOR_H
