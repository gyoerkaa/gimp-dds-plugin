#ifndef DDSOPTIONS_H
#define DDSOPTIONS_H

#include <libgimp/gimp.h>

typedef struct DDSImportOptions
{
    gint mipmaps;
} DDSImportOptions;

typedef struct DDSExportOptions
{
    gint mipmaps;
} DDSExportOptions;

extern DDSImportOptions dds_import_options;
extern DDSExportOptions dds_export_options;

#endif
