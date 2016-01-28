#ifndef OPTIONS_H
#define OPTIONS_H

#include <libgimp/gimp.h>

typedef struct DDSImportOptions
{
    gint mipmaps;
} DDSImportOptions;

typedef struct DDSExportOptions
{
    gint mipmaps;
} DDSExportOptions;

#endif
