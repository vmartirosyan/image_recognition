#include "image.hpp"
#include <iostream>

Image* Image::Invert() {
    for(int h = this->Height - 1; h >= 0; h--)
    {
        for(int w = 0; w <= this->Width - 1; w++)
        {
            Pixel& P = Pixels[(this->Width * h + w)];
            std::cout << "(" << P.R << ", " << P.G << ", " << P.B << ", " << P.A << ") ";
            P.B = 255 - P.B;
            P.G = 255 - P.G;
            P.R = 255 - P.R;
            std::cout << "(" << P.R << ", " << P.G << ", " << P.B << ", " << P.A << ") ";
        }
        std::cout << std::endl;
    }

    return this;
}
