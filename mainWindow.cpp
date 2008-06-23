#include <stdlib.h>
#include <gtk/gtk.h>
#include <libintl.h>
using namespace std;

#define _(x) gettext(x)

///Global variables, mainly widgets
GtkWidget *win;
GtkWidget *rootVbox;
GtkWidget *hbox;
GtkWidget *label;
GtkWidget *libComboBox;
GtkWidget *algorithmComboBox;
GtkWidget *amountSpinner;
GtkWidget *fileField;

static void processLibraryChange(GtkWidget *wid, gpointer data)
{
    switch(gtk_combo_box_get_active(GTK_COMBO_BOX(libComboBox)))
        {
            case 0: ///MersenneTwister.h
                {
                    gtk_combo_box_
                }
        }
}

int main (int argc, char *argv[])
{

  /* Initialize GTK+ */
  g_log_set_handler ("Gtk", G_LOG_LEVEL_WARNING, (GLogFunc) gtk_false, NULL);
  gtk_init (&argc, &argv);
  g_log_set_handler ("Gtk", G_LOG_LEVEL_WARNING, g_log_default_handler, NULL);

  /* Create the main window */
  win = gtk_window_new (GTK_WINDOW_TOPLEVEL);
  gtk_container_set_border_width (GTK_CONTAINER (win), 8);
  gtk_window_set_title (GTK_WINDOW (win), _("MultiRNG"));
  gtk_window_set_position (GTK_WINDOW (win), GTK_WIN_POS_CENTER);
  gtk_widget_realize (win);
  g_signal_connect (win, "destroy", gtk_main_quit, NULL);

  /// Create the main vertical box and fill it.
  vbox = gtk_vbox_new (false, 0);
  gtk_container_add (GTK_CONTAINER (win), vbox);
  //Create new hbox
  hbox = gtk_hbox_new(false, 0);
  label = gtk_label_new(_("Library"));
   gtk_box_pack_start_defaults(GTK_BOX(hbox), label);
  libComboBox = gtk_combo_box_new_text();
    gtk_combo_box_append_text(GTK_COMBO_BOX(libComboBox), _("MersenneTwister.h"));
    gtk_combo_box_append_text(GTK_COMBO_BOX(libComboBox), _("GMP"));
    gtk_combo_box_append_text(GTK_COMBO_BOX(libComboBox), _("Boost::random"));
    gtk_combo_box_append_text(GTK_COMBO_BOX(libComboBox), _("C Stdlib"));
    gtk_box_pack_start_defaults(GTK_BOX(hbox), libComboBox);
    g_signal_connect (libComboBox, "changed", G_CALLBACK(processLibraryChange), NULL);
  label = gtk_label_new(_("Algorithms:"));
    gtk_box_pack_start_defaults(GTK_BOX(hbox), label);

  /* Enter the main loop */
  gtk_widget_show_all (win);
  gtk_main ();
  return 0;
}
