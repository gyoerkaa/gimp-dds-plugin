#ifndef DDSIMPORT_H
#define DDSIMPORT_H

#include <string>
#include "ddsheader.h"
#include "options.h"

#define MAKE4CC(v1, v2, v3, v4) (v1 | v2 << 8 | v3 << 16 | v4 << 24)
#define FOURCC_DXT1     MAKE4CC('D', 'X', 'T', '1')
#define FOURCC_DXT2     MAKE4CC('D', 'X', 'T', '2')
#define FOURCC_DXT3     MAKE4CC('D', 'X', 'T', '3')
#define FOURCC_DXT4     MAKE4CC('D', 'X', 'T', '4')
#define FOURCC_DXT5     MAKE4CC('D', 'X', 'T', '5')
#define FOURCC_DX10     MAKE4CC('D', 'X', '1', '0')
#define FOURCC_DWMAGIC  MAKE4CC('D', 'D', 'S', ' ')

class DDSImport {
public:
    DDSImport();
    bool read(const std::string filename);

private:
    std::string m_filename;
    FILE *m_file;
    uint32_t         m_dwMagic;
    DDS_HEADER       m_header;
    DDS_HEADER_DXT10 m_headerDxt10;

    void init();
    bool readHeader();
};

#endif

