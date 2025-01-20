#include "image.hpp"

struct __attribute__((__packed__)) BMPHeader
{
    char ID[2];
    uint32_t FileSize;
    char Unused[4];
    uint32_t PixelOffset;
};

struct __attribute__((__packed__)) DIBHeader
{
    uint32_t HeaderSize;
    uint32_t Width;
    uint32_t Height;
};

struct __attribute__((__packed__)) DIBHeaderTail
{
};

class BMPImage : public Image {
private:
    struct BMPHeader Header;
    struct DIBHeader ImageDetails;
    char *Tail;
    
public:
    virtual Image * LoadImage(const char * fileName);
    virtual bool SaveImage(const char * fileName);
    virtual Image* Clone(bool clonePixels = false);

    void SetHeight(uint16_t height) { Image::SetHeight(height); ImageDetails.Height = height; }
    void SetWidth(uint16_t width)   { Image::SetWidth(width); ImageDetails.Width = width; }
};
