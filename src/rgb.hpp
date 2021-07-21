#ifndef RGB_HPP
#define RGB_HPP

enum color {red, green, blue};

class RGB {
public:
    int r, b, g;
    RGB(int r = 255, int g = 255, int b = 255):
        r(r),
        g(g),
        b(b)
{}
    int get(color c);
    void set(color c, int i);
};

#endif RGB_HPP
