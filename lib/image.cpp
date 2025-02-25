#include "image.hpp"
#include <iostream>
#include <vector>
#include <map>
#include <stdlib.h>

Image* Image::Invert() {
    for(int h = this->GetHeight() - 1; h >= 0; h--)
    {
        for(int w = 0; w <= this->GetWidth() - 1; w++)
        {
            Pixel& P = GetPixels()[(this->GetWidth() * h + w)];
            std::cout << "(" << P.RGBA.R << ", " << P.RGBA.G << ", " << P.RGBA.B << ", " << P.RGBA.A << ") ";
            P.RGBA.B = 255 - P.RGBA.B;
            P.RGBA.G = 255 - P.RGBA.G;
            P.RGBA.R = 255 - P.RGBA.R;
            std::cout << "(" << P.RGBA.R << ", " << P.RGBA.G << ", " << P.RGBA.B << ", " << P.RGBA.A << ") ";
        }
        std::cout << std::endl;
    }

    return this;
}

std::vector<Image*> Image::Split(uint16_t numParts, SplitType type) {
    std::vector<Image*> images;

    for (int i = 0; i < numParts; ++i) {
        Image* img = Clone();
        img->SetPixels(this->GetPixels() + (img->GetHeight() / numParts * i)*GetWidth());
        img->SetHeight(img->GetHeight() / numParts);
        std::string fileName = "images/tmp/img_";
        fileName += (char)(i+'0');
        fileName += ".bmp"; 
        img->SaveImage(fileName.c_str());
        images.push_back(img);
    }

    return images;
}

RGBA Image::GetAverageColor() {
    std::map<RGBA, unsigned int> colorMap;
    
    RGBA avgColor;
    for (int i = 0; i < height * width; ++i) {
        uint count = colorMap[pixels[i].RGBA];
        //std::pair<RGBA, unsigned int> pair(pixels[i].RGBA, count+1);
        colorMap[pixels[i].RGBA] = count+1;
        // avgColor.R = (avgColor.R + (int)pixels[i].RGBA.R) / 2;
        // avgColor.G = (avgColor.G + (int)pixels[i].RGBA.G) / 2;
        // avgColor.B = (avgColor.B + (int)pixels[i].RGBA.B) / 2;
    }

    unsigned int max = 0;
    for (auto i = colorMap.begin(); i != colorMap.end(); ++i) {
        if (i->second > max) {
            max = i->second;
            avgColor = i->first;
        }
    }

    return avgColor;
}
