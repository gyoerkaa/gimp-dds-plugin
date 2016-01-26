#include <libgimp/gimp.h>

#include "ddsplugin.h"


GimpPlugInInfo PLUG_IN_INFO =
{
  NULL,
  NULL,
  query,
  run
};


MAIN()


static void query (void)
{
    // Load arguments
    static const GimpParamDef load_args[] =
    {
        {GIMP_PDB_INT32,  "run-mode",     "Interactive, non-interactive"},
        {GIMP_PDB_STRING, "filename",     "The name of the file to load"},
        {GIMP_PDB_STRING, "raw-filename", "The name entered"},
        {GIMP_PDB_INT32,  "load-mipmaps", "Load mipmaps if present"}
    };

    // Load return values
    static const GimpParamDef load_return_values[] =
    {
        {GIMP_PDB_IMAGE, "image", "Output image"}
    };

    // Save arguments
    static const GimpParamDef save_args[] =
    {
        {GIMP_PDB_INT32,    "run-mode",     "Interactive, non-interactive" },
        {GIMP_PDB_IMAGE,    "image",        "Input image" },
        {GIMP_PDB_DRAWABLE, "drawable",     "Drawable to save" },
        {GIMP_PDB_STRING,   "filename",     "The name of the file to save the image in" },
        {GIMP_PDB_STRING,   "raw-filename", "The name entered" }
    };

    // Install load procedure
    gimp_install_procedure(LOAD_PROCEDURE,
                           "Loads files in Direct Draw Surface (DDS) format",
                           "Loads files in Direct Draw Surface (DDS) format",
                           "Attila Györkös",
                           "GPL v3",
                           "2016",
                           "Direct Draw Surface",
                           NULL,
                           GIMP_PLUGIN,
                           G_N_ELEMENTS(load_args),
                           G_N_ELEMENTS(load_return_values),
                           load_args,
                           load_return_values);
    // Register load handlers
    gimp_register_file_handler_mime(LOAD_PROCEDURE, "image/dds");
    gimp_register_load_handler(LOAD_PROCEDURE, "dds", "");

    // Install save procedure
    gimp_install_procedure(SAVE_PROCEDURE,
                           "Saves files in Direct Draw Surface (DDS) format",
                           "Saves files in Direct Draw Surface (DDS) format",
                           "Attila Györkös",
                           "GPL v3",
                           "2016",
                           "Direct Draw Surface",
                           "RGB*",
                           GIMP_PLUGIN,
                           G_N_ELEMENTS(save_args),
                           0,
                           save_args,
                           NULL);
    // Register save handlers
    gimp_register_file_handler_mime(SAVE_PROCEDURE, "image/dds");
    gimp_register_save_handler(SAVE_PROCEDURE, "dds", "");
}


static void run(const gchar      *name,
                gint              nparams,
                const GimpParam  *param,
                gint             *nreturn_vals,
                GimpParam       **return_vals)
{
    static GimpParam return_values[2];
    GimpPDBStatusType status = GIMP_PDB_SUCCESS;
    GimpRunMode run_mode;

    /* Mandatory output values */
    *nreturn_vals = 1;
    *return_vals  = return_values;

    /* Default return value = success*/
    return_values[0].type = GIMP_PDB_STATUS;
    return_values[0].data.d_status = status;

    /* Get run_mode - don't display a dialog if in NONINTERACTIVE mode */
    run_mode = param[0].data.d_int32;
    if(!strcmp(name, LOAD_PROCEDURE))
    {
        if (run_mode == GIMP_RUN_INTERACTIVE)
            g_message("load dds\n");
    }
    else if(!strcmp(name, SAVE_PROCEDURE))
    {
        if (run_mode == GIMP_RUN_INTERACTIVE)
            g_message("save dds\n");
    }
    else
    {
        return_values[0].data.d_status = GIMP_PDB_CALLING_ERROR;
    }
}
