#include <stdlib.h>
#include <gtk/gtk.h>
#include <libintl.h>
#include <fstream>
#include <boost/lexical_cast.hpp>
//#include <boost/random.hpp>
//#include "generators.h"
using namespace std;
using namespace boost;
//using namespace boost::random;
#define _(x) gettext(x)

///Global variables
GtkWidget *win;
GtkWidget *rootHbox; //"More root" than rootVbox
 GtkWidget *labelVbox;
 GtkWidget *rootVbox;
GtkWidget *hbox;
GtkWidget *label;
GtkWidget *algorithmComboBox;
GtkWidget *distributionComboBox;
GtkWidget *seedEntry;
unsigned long seed;
#ifdef __linux__
  GtkWidget *hqSeedCheckButton; //High quality seed, uses /dev/random instead of /dev/urandom
#endif
GtkWidget *generateSeedButton;
GtkWidget *lowerLimitEntry;
GtkWidget *upperLimitEntry;
GtkWidget *amountSpinner;
GtkWidget *fileEntry;

static void generateSeed(GtkWidget *wid, gpointer data)
{

    ///Read from /dev/(u)random if we are using linux or use time(0) on windows
    #ifdef __linux__
        ifstream f;
        ///Dependent on the state of highEntropyCheckbox open either /dev/random or /dev/urandom for read
        if(gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(hqSeedCheckButton)))
            {f.open("/dev/random", ifstream::in);}
        else {f.open("/dev/urandom", ifstream::in);}
        f.read(reinterpret_cast<char*>(&seed), sizeof(seed));
        f.close();
    #else ///Seed from time(0)
        mt19937 mersenne(static_cast<unsigned long>(time(0)));
        uniform_int<unsigned int> dist(0, ULONG_MAX);
        variate_generator<mt19937&, uniform_int<unsigned int>> dist(mersenne, evenDist);
        seed = mersenne();
    #endif
        gtk_entry_set_text(GTK_ENTRY(seedEntry), lexical_cast<string>(seed).c_str());
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

  /// Create the main horizontal/vertical boxes and fill it.
  rootHbox = gtk_hbox_new(false,5);
   labelVbox = gtk_vbox_new(false,5);
   rootVbox = gtk_vbox_new (false, 5);
  //Create new hbox
  label = gtk_label_new(_("Library"));
   gtk_box_pack_start_defaults(GTK_BOX(labelVbox), label);
  ///Init algorithm widgets
  hbox = gtk_hbox_new(false, 5);
  label = gtk_label_new(_("Algorithms:"));
    gtk_box_pack_start_defaults(GTK_BOX(labelVbox), label);
  algorithmComboBox = gtk_combo_box_new_text();
    gtk_combo_box_append_text(GTK_COMBO_BOX(algorithmComboBox), _("MT 19937"));
    gtk_combo_box_append_text(GTK_COMBO_BOX(algorithmComboBox), _("Mersenne Twister 191937"));  ///1
    gtk_combo_box_append_text(GTK_COMBO_BOX(algorithmComboBox), _("MInstdRand (LC Variant)"));  ///2
    gtk_combo_box_append_text(GTK_COMBO_BOX(algorithmComboBox), _("Ecuyer 1988"));              ///3
    gtk_combo_box_append_text(GTK_COMBO_BOX(algorithmComboBox), _("Kreutzer 1986"));            ///4
    gtk_combo_box_append_text(GTK_COMBO_BOX(algorithmComboBox), _("Hellekalek 1995"));          ///5
    gtk_combo_box_append_text(GTK_COMBO_BOX(algorithmComboBox), _("Mersenne Twister 11213b"));  ///6
    gtk_combo_box_append_text(GTK_COMBO_BOX(algorithmComboBox), _("Lagged Fibonacci 607"));     ///7
    gtk_combo_box_append_text(GTK_COMBO_BOX(algorithmComboBox), _("Lagged Fibonacci 1279"));    ///8
    gtk_combo_box_append_text(GTK_COMBO_BOX(algorithmComboBox), _("Lagged Fibonacci 2281"));    ///9
    gtk_combo_box_append_text(GTK_COMBO_BOX(algorithmComboBox), _("Lagged Fibonacci 3217"));    ///10
    gtk_combo_box_append_text(GTK_COMBO_BOX(algorithmComboBox), _("Lagged Fibonacci 4423"));    ///11
    gtk_combo_box_append_text(GTK_COMBO_BOX(algorithmComboBox), _("Lagged Fibonacci 9689"));    ///12
    gtk_combo_box_append_text(GTK_COMBO_BOX(algorithmComboBox), _("Lagged Fibonacci 19937"));   ///13
    gtk_combo_box_append_text(GTK_COMBO_BOX(algorithmComboBox), _("Lagged Fibonacci 23209"));   ///14
    gtk_combo_box_append_text(GTK_COMBO_BOX(algorithmComboBox), _("Lagged Fibonacci 44497"));   ///15
    gtk_combo_box_set_active(GTK_COMBO_BOX(algorithmComboBox), 0);
    gtk_box_pack_start_defaults(GTK_BOX(hbox),algorithmComboBox);
   gtk_box_pack_start_defaults(GTK_BOX(rootVbox), hbox);
  ///Init distribution widgets
  hbox = gtk_hbox_new(false, 5);
  label = gtk_label_new(_("Distributions:"));
    gtk_box_pack_start_defaults(GTK_BOX(labelVbox), label);
  distributionComboBox = gtk_combo_box_new_text();
    gtk_combo_box_append_text(GTK_COMBO_BOX(distributionComboBox), _("Uniform Integer"));
    gtk_combo_box_append_text(GTK_COMBO_BOX(distributionComboBox), _("Uniform Real"));
    gtk_combo_box_append_text(GTK_COMBO_BOX(distributionComboBox), _("Triangle"));
    gtk_combo_box_append_text(GTK_COMBO_BOX(distributionComboBox), _("Bernoulli"));
    gtk_combo_box_append_text(GTK_COMBO_BOX(distributionComboBox), _("Cauchy"));
    gtk_combo_box_append_text(GTK_COMBO_BOX(distributionComboBox), _("Exponential"));
    gtk_combo_box_append_text(GTK_COMBO_BOX(distributionComboBox), _("Geometric"));
    gtk_combo_box_append_text(GTK_COMBO_BOX(distributionComboBox), _("Normal"));
    gtk_combo_box_append_text(GTK_COMBO_BOX(distributionComboBox), _("Lognormal"));
    gtk_combo_box_append_text(GTK_COMBO_BOX(distributionComboBox), _("Uniform on Sphere"));
    gtk_combo_box_set_active(GTK_COMBO_BOX(algorithmComboBox), 0);
    gtk_box_pack_start_defaults(GTK_BOX(hbox),distributionComboBox);
   gtk_box_pack_start_defaults(GTK_BOX(rootVbox), hbox);
  ///Init file widgets
  hbox = gtk_hbox_new(false, 5);
  label = gtk_label_new(_("File:"));
    gtk_box_pack_start_defaults(GTK_BOX(labelVbox), label);
  fileEntry = gtk_entry_new();
    gtk_entry_set_text(GTK_ENTRY(fileEntry), "random.txt");
    gtk_box_pack_start_defaults(GTK_BOX(hbox), fileEntry);
   gtk_box_pack_start_defaults(GTK_BOX(rootVbox), hbox);
  ///Init Seed widgets
  hbox = gtk_hbox_new(false, 5);
  label = gtk_label_new(_("Seed:"));
    gtk_box_pack_start_defaults(GTK_BOX(labelVbox), label);
  seedEntry = gtk_entry_new();
    gtk_entry_set_text(GTK_ENTRY(seedEntry), "1234567890");
    gtk_box_pack_start_defaults(GTK_BOX(hbox), seedEntry);
  #ifdef __linux__
    hqSeedCheckButton = gtk_check_button_new_with_label(_("HQ Entropy"));
     gtk_box_pack_start_defaults(GTK_BOX(hbox), hqSeedCheckButton);
  #endif
  generateSeedButton = gtk_button_new_with_label(_("Generate"));
   g_signal_connect (generateSeedButton, "clicked", G_CALLBACK(generateSeed), NULL);
   gtk_box_pack_start_defaults(GTK_BOX(rootVbox), hbox);
  ///Init limit widgets
  hbox = gtk_hbox_new(false, 5);
  label = gtk_label_new(_("Lower limit:"));
    gtk_box_pack_start_defaults(GTK_BOX(labelVbox), label);
  lowerLimitEntry = gtk_entry_new();
    gtk_entry_set_text(GTK_ENTRY(lowerLimitEntry), "0");
    gtk_box_pack_start_defaults(GTK_BOX(hbox), lowerLimitEntry);
  label = gtk_label_new(_("Upper limit:"));
    gtk_box_pack_start_defaults(GTK_BOX(labelVbox), label);
  upperLimitEntry = gtk_entry_new();
    gtk_entry_set_text(GTK_ENTRY(lowerLimitEntry), "1000");
    gtk_box_pack_start_defaults(GTK_BOX(hbox), upperLimitEntry);
   gtk_box_pack_start_defaults(GTK_BOX(rootVbox), hbox);

   ///Add subordinary boxes to rootBox
   gtk_box_pack_start_defaults(GTK_BOX(rootHbox), labelVbox);
   gtk_box_pack_start_defaults(GTK_BOX(rootHbox), rootVbox);

  gtk_container_add (GTK_CONTAINER (win), rootHbox);

  /* Enter the main loop */
  gtk_widget_show_all(win);
  gtk_main ();
  return 0;
}
