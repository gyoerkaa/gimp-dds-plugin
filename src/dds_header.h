#ifndef DDS_HEADER_H
#define DDS_HEADER_H

typedef struct DDS_PIXELFORMAT {
  DWORD dwSize;
  DWORD dwFlags;
  DWORD dwFourCC;
  DWORD dwRGBBitCount;
  DWORD dwRBitMask;
  DWORD dwGBitMask;
  DWORD dwBBitMask;
  DWORD dwABitMask;
} DDS_PIXELFORMAT;

typedef struct DDS_HEADER {
  DWORD           dwSize;
  DWORD           dwFlags;
  DWORD           dwHeight;
  DWORD           dwWidth;
  DWORD           dwPitchOrLinearSize;
  DWORD           dwDepth;
  DWORD           dwMipMapCount;
  DWORD           dwReserved1[11];
  DDS_PIXELFORMAT ddspf;
  DWORD           dwCaps1;
  DWORD           dwCaps2;
  DWORD           dwCaps3;          // Unused
  DWORD           dwCaps4;          // Unused
  DWORD           dwReserved2;
} DDS_HEADER;

// DDS caps flags 1.
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
