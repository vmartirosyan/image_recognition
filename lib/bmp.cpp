#include <fstream>
#include <iostream>
#include <string.h>
#include "bmp.hpp"

Image * BMPImage::LoadImage(const char * fileName) {

    
    std::ifstream MyFile(fileName);  
    MyFile.read((char*)&Header, sizeof(Header));

    std::cout << "ID address: " << &Header.ID << std::endl;
    std::cout << "File Size address: " << &Header.FileSize << std::endl;

    std::cout << "Id: " << Header.ID << std::endl;
    std::cout << "File Size: " << Header.FileSize << std::endl;
    std::cout << "Pixel offset: " << Header.PixelOffset << std::endl;

    MyFile.read((char*)&ImageDetails, sizeof(ImageDetails));

    std::cout << "DIB Header Size: " << ImageDetails.HeaderSize << std::endl;
    std::cout << "Width: " << ImageDetails.Width << std::endl;
    std::cout << "Height: " << ImageDetails.Height << std::endl;

    Tail = new char[ImageDetails.HeaderSize - sizeof(ImageDetails)];
    MyFile.read((Tail), ImageDetails.HeaderSize - sizeof(ImageDetails));
    std::cout << "Tail loaded. Size: " << ImageDetails.HeaderSize - sizeof(ImageDetails) << std::endl;
    
    
    this->height = ImageDetails.Height;
    this->width = ImageDetails.Width;
    this->bpp = 32; // ToDo: Implement support for multiple BPPs

    this->pixels = new Pixel[this->height * this->width];
    MyFile.read((char*)this->pixels, sizeof(Pixel) * ImageDetails.Width * ImageDetails.Height);
    std::cout << "Pixels loaded. Size: " << this->height * this->width << std::endl;

    return this;
}

bool BMPImage::SaveImage(const char * fileName) {
    std::ofstream Output (fileName);
    Output.write((char*)&Header, sizeof(Header));
    Output.write((char*)&ImageDetails, sizeof(ImageDetails));
    Output.write((char*)Tail, ImageDetails.HeaderSize - sizeof(ImageDetails));
    Output.write((char*)pixels, sizeof(Pixel) * ImageDetails.Width * ImageDetails.Height);
    Output.close();
    return true;
}

Image* BMPImage::Clone(bool clonePixels) {
    Image  * newImage = new BMPImage(*this);
     if (clonePixels) {
        newImage->SetPixels(new Pixel[height*width]);
        memcpy(newImage->GetPixels(), this->pixels, height*width*sizeof(Pixel));
     }

     return newImage;
}



