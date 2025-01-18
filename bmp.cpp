#include <iostream>
#include "lib/bmp.hpp"

int main ()
{
    Image * img = new BMPImage;
    img->LoadImage("images/pixels.bmp");
    img->Invert();
    img->SaveImage("images/inverted.bmp");
    /*struct BMPHeader  Header;
    std::ifstream MyFile("images/flag.bmp");  
    MyFile.read((char*)&Header, sizeof(Header));

    std::cout << "ID address: " << &Header.ID << std::endl;
    std::cout << "File Size address: " << &Header.FileSize << std::endl;

    std::cout << "Id: " << Header.ID << std::endl;
    std::cout << "File Size: " << Header.FileSize << std::endl;
    std::cout << "Pixel offset: " << Header.PixelOffset << std::endl;

    struct DIBHeader ImageDetails;
    MyFile.read((char*)&ImageDetails, sizeof(ImageDetails));

    std::cout << "DIB Header Size: " << ImageDetails.HeaderSize << std::endl;
    std::cout << "Width: " << ImageDetails.Width << std::endl;
    std::cout << "Height: " << ImageDetails.Height << std::endl;

    char Tail[ImageDetails.HeaderSize - sizeof(ImageDetails)];
    MyFile.read((Tail), ImageDetails.HeaderSize - sizeof(ImageDetails));

    Pixel Pixels[ImageDetails.Width * ImageDetails.Height];
    MyFile.read((char*)Pixels, sizeof(Pixel) * ImageDetails.Width * ImageDetails.Height);

    for(int h = ImageDetails.Height - 1; h >= 0; h--)
    {
        for(int w = 0; w <= ImageDetails.Width - 1; w++)
        {
            Pixel& P = Pixels[(ImageDetails.Width * h + w)];
            std::cout << "(" << P.R << ", " << P.G << ", " << P.B << ", " << P.A << ") ";
            P.B = 255 - P.B;
            P.G = 255 - P.G;
            P.R = 255 - P.R;
            std::cout << "(" << P.R << ", " << P.G << ", " << P.B << ", " << P.A << ") ";
        }
        std::cout << std::endl;
    }

    std::ofstream Output ("images/inverted.bmp");
    Output.write((char*)&Header, sizeof(Header));
    Output.write((char*)&ImageDetails, sizeof(ImageDetails));
    Output.write((char*)&Tail, ImageDetails.HeaderSize - sizeof(ImageDetails));
    Output.write((char*)Pixels, sizeof(Pixel) * ImageDetails.Width * ImageDetails.Height);
    Output.close();*/

    return 0;
}
