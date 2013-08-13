#include <gnome.h>

void hellomessage( GtkWidget *widget, gpointer data )
{
	g_print ("Hello World\n");
}

gint closeprog ( GtkWidget *widget, GdkEvent *event, gpointer data )
{
	g_print ("Bye\n");
	gtk_main_quit();
}

int main( int argc, char *argv[] )
{
	GtkWidget *app;
	GtkWidget *mybutton;

	gnome_init ("", "0.1", argc, argv);

	mybutton = gtk_button_new_with_label ("Click Me");

	app = gnome_app_new ("Hello-World", "Hello App");

	gnome_app_set_contents (GNOME_APP (app), mybutton);

	gtk_signal_connect (GTK_OBJECT (app), "delete_event", GTK_SIGNAL_FUNC(closeprog),NULL);

	gtk_signal_connect (GTK_OBJECT (mybutton), "clicked", GTK_SIGNAL_FUNC(hellomessage), NULL);

	gtk_widget_show_all(app);
	gtk_main();
	return(0);
}
