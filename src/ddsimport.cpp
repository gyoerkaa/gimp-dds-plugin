#include "ddsimport.hpp"

#include <cstdio>
#include <cstdint>
#include <libgimp/gimp.h>

DDSImport::DDSImport ()
{
    init();
}

void DDSImport::init ()
{

}

bool DDSImport::read (const std::string filename)
{
    m_filename = filename;

    m_file = std::fopen(m_filename.c_str(), "rb");

    if (!m_file)
    {
        g_message("Error opening file.\n");
        return false;
    }

    if (!readHeader())
    {
        g_message("Invalid dds file.\n");
        return false;
    }
    /*
    std::ifstream file(m_filename.c_str(), std::ifstream::binary | std::ifstream::in);
    if (!file.good())
    {
        g_message("Error opening file.\n");
        return(GIMP_PDB_EXECUTION_ERROR);
    }
    uint32_t dwmagic;

    file.read(&dwmagic, sizeof(dwmagic));
    file.close();
    */
}

bool DDSImport::readHeader ()
{
    uint32_t dwmagic;
    std::fread(&dwmagic, sizeof(dwmagic), 1, m_file);
    if (dwmagic != FOURCC_DWMAGIC)
    {
        g_message("Invalid DDS file.\n");
        return false;
    }
    // DDS_HEADER struct
    // TODO: Sanity checks where possible
    // TODO: Clean this up
    std::fread(&m_header.dwSize, sizeof(m_header.dwSize), 1, m_file);
    std::fread(&m_header.dwFlags, sizeof(m_header.dwFlags), 1, m_file);
    std::fread(&m_header.dwHeight, sizeof(m_header.dwHeight), 1, m_file);
    std::fread(&m_header.dwWidth, sizeof(m_header.dwWidth), 1, m_file);
    std::fread(&m_header.dwPitch, sizeof(m_header.dwPitch), 1, m_file);
    std::fread(&m_header.dwDepth, sizeof(m_header.dwDepth), 1, m_file);
    std::fread(&m_header.dwMipMapCount, sizeof(m_header.dwMipMapCount), 1, m_file);
    std::fseek(m_file, 44, SEEK_CUR); // Unused, 11 DWORDS = 44 bytes
    // DDS_PIXELFORMAT (sub)struct
    std::fread(&m_header.ddspf.dwSize, sizeof(&m_header.ddspf.dwSize), 1, m_file);
    std::fread(&m_header.ddspf.dwFlags, sizeof(&m_header.ddspf.dwFlags), 1, m_file);
    std::fread(&m_header.ddspf.dwFourCC, sizeof(&m_header.ddspf.dwFourCC), 1, m_file);
    std::fread(&m_header.ddspf.dwRGBBitCount, sizeof(&m_header.ddspf.dwRGBBitCount), 1, m_file);
    std::fread(&m_header.ddspf.dwRBitMask, sizeof(&m_header.ddspf.dwRBitMask), 1, m_file);
    std::fread(&m_header.ddspf.dwGBitMask, sizeof(&m_header.ddspf.dwGBitMask), 1, m_file);
    std::fread(&m_header.ddspf.dwBBitMask, sizeof(&m_header.ddspf.dwBBitMask), 1, m_file);
    std::fread(&m_header.ddspf.dwABitMask, sizeof(&m_header.ddspf.dwABitMask), 1, m_file);
    // DDS_HEADER struct
    std::fread(&m_header.dwCaps1, sizeof(m_header.dwCaps1), 1, m_file);
    std::fread(&m_header.dwCaps2, sizeof(m_header.dwCaps2), 1, m_file);
    std::fread(&m_header.dwCaps3, sizeof(m_header.dwCaps3), 1, m_file);
    std::fread(&m_header.dwCaps4, sizeof(m_header.dwCaps4), 1, m_file);
    std::fread(&m_header.dwReserved2, sizeof(m_header.dwReserved2), 1, m_file);
    // Check for DXT10 header
    if ((m_header.ddspf.dwFourCC == FOURCC_DX10) and
        (m_header.ddspf.dwFlags & DDPF_FOURCC))
    {

    }
}

