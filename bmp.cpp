#include <iostream>
#include "lib/bmp.hpp"

int main ()
{
    Image * img = new BMPImage;
    img->LoadImage("images/flag.bmp");
    //img->Invert();
    //img->SaveImage("images/inverted.bmp");
    img->Split(3, Horizontal);

    return 0;
}
