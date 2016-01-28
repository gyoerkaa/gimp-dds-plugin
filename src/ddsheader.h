#ifndef DDS_HEADER_H
#define DDS_HEADER_H

//#include <stdint.h> // no C++11
#include <cstdint>

typedef struct DDS_PIXELFORMAT {
  uint32_t dwSize;
  uint32_t dwFlags;
  uint32_t dwFourCC;
  uint32_t dwRGBBitCount;
  uint32_t dwRBitMask;
  uint32_t dwGBitMask;
  uint32_t dwBBitMask;
  uint32_t dwABitMask;
} DDS_PIXELFORMAT;

typedef struct DDS_HEADER {
  uint32_t        dwSize;
  uint32_t        dwFlags;
  uint32_t        dwHeight;
  uint32_t        dwWidth;
  uint32_t        dwPitch; // dwPitchOrLinearSize
  uint32_t        dwDepth;
  uint32_t        dwMipMapCount;
  uint32_t        dwReserved1[11];
  DDS_PIXELFORMAT ddspf;
  uint32_t        dwCaps1;
  uint32_t        dwCaps2;
  uint32_t        dwCaps3;          // Unused
  uint32_t        dwCaps4;          // Unused
  uint32_t        dwReserved2;
} DDS_HEADER;

// DDS caps flags 1
enum {
    DDSCAPS1_COMPLEX = 0x00000008,  // 2D image or cube map
    DDSCAPS1_TEXTURE = 0x00001000,  // Should always be set
    DDSCAPS1_MIPMAP  = 0x00400000   // Image contains mimaps
};

// DDS caps flags 2
enum {
    DDSCAPS2_CUBEMAP           = 0x00000200,
    DDSCAPS2_CUBEMAP_POSITIVEX = 0x00000400,
    DDSCAPS2_CUBEMAP_NEGATIVEX = 0x00000800,
    DDSCAPS2_CUBEMAP_POSITIVEY = 0x00001000,
    DDSCAPS2_CUBEMAP_NEGATIVEY = 0x00002000,
    DDSCAPS2_CUBEMAP_POSITIVEZ = 0x00004000,
    DDSCAPS2_CUBEMAP_NEGATIVEZ = 0x00008000,
    DDSCAPS2_VOLUME            = 0x00200000   // 3D/volume texture
};

#endif
