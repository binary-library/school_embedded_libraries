#include <rgb.hpp>

int RGB::get(color c) {
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

void RGB::set(color c, int i) {
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