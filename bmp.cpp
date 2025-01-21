#include <iostream>
#include <map>
#include <stdlib.h>
#include <fcntl.h>
#include <dirent.h>
#include "lib/bmp.hpp"

int main ()
{
    

    DIR *dir;
    struct dirent *ent;
    std::map<std::string, RGBA*> contryFlagColors;
    if ((dir = opendir("images/flags")) != NULL) {
        /* print all the files and directories within directory */
        while ((ent = readdir(dir)) != NULL) {
            //std::cout << ent->d_name << std::endl;
            std::string name(ent->d_name);
            if ( name.ends_with(".bmp") /* && name.starts_with("Colombia")*/ ) {
                name = name.substr(0, name.size() - 8);
                std::cout << "Processing " << name << std::endl;

                Image * img = new BMPImage;
                auto filePath = "images/flags/" + name + ".svg.bmp";
                img->LoadImage(filePath.c_str());
                //img->Invert();
                //img->SaveImage("images/inverted.bmp");
                auto images = img->Split(3, Horizontal);
                RGBA *colors = new RGBA[3];
                for (unsigned int i = 0; i < images.size(); ++i) {
                    auto tmp_img = images[i];
                    auto color = tmp_img->GetAverageColor();
                    colors[i] = color;
                    //std::cout << "Avg color of image " << i << ": (" << color.R << "," << color.G << "," << color.B << ")" << std::endl;
                }
                std::pair<std::string, RGBA*> pair(name, colors);
                contryFlagColors.insert(pair);
            }
        }
        closedir(dir);

        // Load the flag to look up for
        Image * img = new BMPImage;
        
        img->LoadImage("images/flag.bmp");
        //img->Invert();
        //img->SaveImage("images/inverted.bmp");
        auto images = img->Split(3, Horizontal);
        RGBA *colors = new RGBA[3];
        for (unsigned int i = 0; i < images.size(); ++i) {
            auto tmp_img = images[i];
            auto color = tmp_img->GetAverageColor();
            colors[i] = color;
            std::cout << "Avg color of image " << i << ": (" << color.R << "," << color.G << "," << color.B << ")" << std::endl;
        }

        //Find the closest flag
        uint minDist = __INT_MAX__;
        std::string closestCountry = "";
        for (auto i = contryFlagColors.begin(); i != contryFlagColors.end(); ++i) {
            uint distance = colors[0].Distance(i->second[0]) + colors[1].Distance(i->second[1]) + colors[2].Distance(i->second[2]);
            if ( distance < minDist ) {
                minDist = distance;
                closestCountry = i->first;
            }
        }

        std::cout << "Closest coutry: " << closestCountry << std::endl;
    }
    return 0;
}
