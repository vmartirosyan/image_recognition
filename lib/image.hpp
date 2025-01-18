#include <stdint.h>

union Pixel
{
    uint32_t Value;
    struct __attribute__((__packed__)) 
    {
        unsigned int B: 8;
        unsigned int G: 8;
        unsigned int R: 8;
        unsigned int A: 8;
    };
};


class Image {
public:
    uint16_t Height;
    uint16_t Width;
    uint16_t BPP; // Bits per pixel
    Pixel *Pixels;

    virtual Image* LoadImage(const char * fileName) = 0;
    virtual bool SaveImage(const char * fileName) = 0;
    virtual Image* Invert();
};
