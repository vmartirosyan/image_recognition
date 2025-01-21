#include <stdint.h>
#include <math.h>
#include <vector>

struct __attribute__((__packed__)) RGBA
{
    unsigned int B: 8;
    unsigned int G: 8;
    unsigned int R: 8;
    unsigned int A: 8;
    uint Distance(const RGBA & c) { return fabs(R-c.R) + fabs(G-c.G) + fabs(B-c.B); }
    bool operator <  (const RGBA c) const { return (R<c.R)  || (G<c.G)  || (B<c.B); }
    bool operator == (const RGBA c) const { return (R==c.R) && (G==c.G) && (B==c.B);}
};

union Pixel
{
    uint32_t Value;
    struct RGBA RGBA;
};

enum SplitType {
    None,
    Horizontal,
    Vertical
};


class Image {
protected:
    uint16_t height;
    uint16_t width;
    uint16_t bpp; // Bits per pixel
    Pixel *pixels;
public:
   
    virtual Image* LoadImage(const char * fileName) = 0;
    virtual bool SaveImage(const char * fileName) = 0;
    virtual Image* Invert();
    virtual Image* Clone(bool clonePixels = false) = 0;

    // Splits the image into cmaller parts of given number. Can split either horizontally, or vertically.
    virtual std::vector<Image*> Split(uint16_t numParts, SplitType type);
    virtual RGBA GetAverageColor();

    virtual uint16_t    GetHeight()                 { return height;}
    virtual void        SetHeight(uint16_t value)   { height = value;}
    virtual uint16_t    GetWidth()                  { return width;}
    virtual void        SetWidth(uint16_t value)    { width = value;}
    virtual uint16_t    GetBPP()                    { return bpp;}
    virtual void        SetBPP(uint16_t value)      { bpp = value;}
    virtual Pixel*      GetPixels()                 { return pixels;}
    virtual void        SetPixels(Pixel* value)     { pixels = value;}

};
