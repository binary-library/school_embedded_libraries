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

    int get(color c) {
        switch (c) {
            case red:
                return r;
                break;
            case green:
                return g;
                break;
            case blue:
                return b;
                break;
            default:
                return 0; 
        } 
    }

    void set(color c, int i) {
        if (i < 1) i = 0;
            else i %= 255;            
        switch (c) {
            case red:
                r = i;
                break;
            case green:
                g = i;
                break;
            case blue:
                b = i;
                break; 
            }
    }

};

#endif RGB_HPP
