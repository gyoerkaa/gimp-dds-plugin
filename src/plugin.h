#ifndef DDSPLUGIN_H
#define DDSPLUGIN_H

#define LOAD_PROCEDURE "file-dds-load"
#define SAVE_PROCEDURE "file-dds-save"

typedef struct DDSImportOptions
{
    gint mipmaps;
} DDSImportOptions;

static DDSImportOptions import_options = {0};

static void query (void);

static void run (const gchar      *name,
                 gint              nparams,
                 const GimpParam  *param,
                 gint             *nreturn_vals,
                 GimpParam       **return_vals);

#endif
