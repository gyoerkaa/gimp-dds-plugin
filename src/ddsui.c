#include "ddsui.h"
#include "options.h"

#include <gtk/gtk.h>
#include <libgimp/gimp.h>
#include <libgimp/gimpui.h>

static void toggle_clicked(GtkWidget *widget, gpointer data)
{
   int *flag = (int*)data;
   (*flag) = !(*flag);
}

int load_dialog (void)
{
    int run = 0;

    gimp_ui_init("file-dds", FALSE);

    GtkWidget *dialog = gimp_dialog_new("DDS Import Options", "file-dds",
                                        NULL, (GtkDialogFlags)0,
                                        gimp_standard_help_func, "file-dds",
                                        GTK_STOCK_CANCEL, GTK_RESPONSE_CANCEL,
                                        GTK_STOCK_OK, GTK_RESPONSE_OK,
                                        NULL);
    gimp_window_set_transient(GTK_WINDOW(dialog));

    GtkWidget *main_vbox = gtk_vbox_new (FALSE, 6);
    gtk_container_add(GTK_CONTAINER(GTK_DIALOG(dialog)->vbox), main_vbox);
    gtk_widget_show(main_vbox);

    GtkWidget *chboxMipmaps = gtk_check_button_new_with_label("Load mipmaps");
    gtk_toggle_button_set_active(GTK_TOGGLE_BUTTON(chboxMipmaps),
                                 dds_import_options.mipmaps);
    gtk_signal_connect(GTK_OBJECT(chboxMipmaps),
                       "clicked",
                       GTK_SIGNAL_FUNC(toggle_clicked),
                       &dds_import_options.mipmaps);
    gtk_box_pack_start(GTK_BOX(main_vbox), chboxMipmaps, 1, 1, 0);
    gtk_widget_show(chboxMipmaps);

    GtkWidget *chboxDecode = gtk_check_button_new_with_label("Decode YCoCg/AExp images");
    gtk_toggle_button_set_active(GTK_TOGGLE_BUTTON(chboxDecode),
                                 dds_import_options.decode);
    gtk_signal_connect(GTK_OBJECT(chboxDecode),
                       "clicked",
                       GTK_SIGNAL_FUNC(toggle_clicked),
                       &dds_import_options.decode);
    gtk_box_pack_start(GTK_BOX(main_vbox), chboxDecode, 1, 1, 0);
    gtk_widget_show(chboxDecode);

    run = (gimp_dialog_run(GIMP_DIALOG (dialog)) == GTK_RESPONSE_OK);
    gtk_widget_destroy(dialog);

    return run;
}


int save_dialog (void)
{
    int run = 0;

    gimp_ui_init("file-dds", FALSE);

    GtkWidget *dialog = gimp_dialog_new("DDS Export Options", "file-dds",
                                        NULL, (GtkDialogFlags)0,
                                        gimp_standard_help_func, "file-dds",
                                        GTK_STOCK_CANCEL, GTK_RESPONSE_CANCEL,
                                        GTK_STOCK_OK, GTK_RESPONSE_OK,
                                        NULL);
    gimp_window_set_transient(GTK_WINDOW(dialog));

    GtkWidget *main_vbox = gtk_vbox_new (FALSE, 6);
    gtk_container_add(GTK_CONTAINER(GTK_DIALOG(dialog)->vbox), main_vbox);
    gtk_widget_show(main_vbox);

    run = (gimp_dialog_run(GIMP_DIALOG (dialog)) == GTK_RESPONSE_OK);
    gtk_widget_destroy(dialog);

    return run;
}
