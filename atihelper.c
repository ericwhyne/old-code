// Eric Whyne 2004
// To compile:
// gcc -Wall -g atihelper.c -o Atihelper `pkg-config --cflags gtk+-2.0` `pkg-config --libs gtk+-2.0`
// What: This is a program shell for system control using a remote control such as the ATI all in wonder.
// This duplicates the work of some other projects out there, however it provides a chunk of gtk code to play with
// when learning how to make graphical applications.  It also provides the framework to create a highly customized application for similar devices.
//
// For ati all in wonder you need any of the kernel modules installed that treats it as a keyboard.
// There is much room for improvement in this code, that is why it is just a shell.
#include <gtk/gtk.h>
#include <stdlib.h>
#include <errno.h>

/* Required for mute() */
int MUTE = 0;
char UNMUTECOMMAND[] = "amixer set Master,0 100%,100% unmute";
char MUTECOMMAND[] = "amixer set Master,0 0%,0% mute";

/* This function controls the muting/unmuting of the sound card */
int mute()
{
	if (MUTE == 0){ g_print("Muting Master Soundcard\n"); system(MUTECOMMAND); MUTE = 1;}
	else { g_print("Unmuting Master Soundcard\n"); system(UNMUTECOMMAND); MUTE = 0;}
	return MUTE;
}

/* This is a callback function. The data arguments are ignored
 * in this example. More on callbacks below. */
static void byemessage( GtkWidget *widget, gpointer   data )
{
    g_print ("Goodbye.\n");
}

static gboolean delete_event( GtkWidget *widget,
                              GdkEvent  *event,
                              gpointer   data )
{
    g_print ("Use the quit button.\n");

    /* Change TRUE to FALSE and the main window will be destroyed with
     * a "delete_event". */
    return TRUE;
}

/* Another callback */
static void destroy( GtkWidget *widget,
                     gpointer   data )
{
    gtk_main_quit ();
}


/* /////////////////////////////////////////////b////////////////////////////////////// */

int keyevent(GtkWidget *widget, GdkEventKey *event)
{
    int mykey = event->keyval;
    if (mykey == 'a'){ g_print("Turning on light\n"); system("/usr/bin/br -n 1"); }
    else if (mykey == 'b'){ g_print("Turning off light\n"); system("/usr/bin/br -f 1"); }
    else if (mykey == 'c'){ g_print("Muting Master Soundcard\n"); system("amixer set Master,0 0%,0% mute");}
    else if (mykey == 65479){ mute();}
    else if (mykey == 81){ g_print("Quitting\n");}
    else if (mykey == 176){ g_print("Eureka\n");}
    else { g_print("%d\n", mykey); }

    return TRUE;
}


int main( int   argc, char *argv[] )
{
	
    g_print("Unmuting Master Soundcard\n"); 
   	system(UNMUTECOMMAND);
	
    /* GtkWidget is the storage type for widgets */
    GtkWidget *window;
    GtkWidget *button;
    
    
    /* This is called in all GTK applications. Arguments are parsed
     * from the command line and are returned to the application. */
    gtk_init (&argc, &argv);
    
    /* create a new window */
    window = gtk_window_new (GTK_WINDOW_TOPLEVEL);
  
    /* urk - Make sure the window is centered when opened */
    gtk_window_set_position (GTK_WINDOW (window), GTK_WIN_POS_CENTER_ALWAYS);

    gtk_window_set_title (GTK_WINDOW (window), "Remote Helper");
        
    g_signal_connect (G_OBJECT (window), "delete_event", G_CALLBACK (delete_event), NULL);

/* The "destroy" event occurs when we call gtk_widget_destroy() 
    	on the window, or if we return FALSE in the "delete_event" callback. */
    g_signal_connect (G_OBJECT (window), "destroy", G_CALLBACK (destroy), NULL);
    
    /* Sets the border width of the window. */
    gtk_container_set_border_width (GTK_CONTAINER (window), 3);
    
    /* Creates a new button with the label "Hello World". */
    button = gtk_button_new_with_label ("     Quit     ");
   g_print("Debug1\n");
   
    /* When the button receives the "clicked" signal, it will call the
     * function hello() passing it NULL as its argument.  The hello()
     * function is defined above. */
    g_signal_connect (G_OBJECT (button), "clicked",
      G_CALLBACK (byemessage), NULL);

    /* This will cause the window to be destroyed by calling
     * gtk_widget_destroy(window) when "clicked".  Again, the destroy
     * signal could come from here, or the window manager. */
    g_signal_connect_swapped (G_OBJECT (button), "clicked",
      			      G_CALLBACK (gtk_widget_destroy),
                              G_OBJECT (window));

  g_print("Debug2\n");

    gtk_signal_connect (GTK_OBJECT (window), "key_press_event",
                        GTK_SIGNAL_FUNC(keyevent), NULL);
    
  g_print("Debug3\n");

/* ///////////////////////////////////////////////////////////////// */
  GtkWidget *frame;
  GtkWidget *image;
  GtkWidget *label;
  GtkWidget *align;
  GdkPixbuf *pixbuf;
  GError *error = NULL;
  char *filename;

   filename = "foo.xpm";
    /* Need to create a vbox to hold multiple things? from gtk-demo */
      GtkWidget *vbox;

      vbox = gtk_vbox_new (FALSE, 8);
      gtk_container_set_border_width (GTK_CONTAINER (vbox), 8);
      gtk_container_add (GTK_CONTAINER (window), vbox);


      label = gtk_label_new (NULL);
      gtk_label_set_markup (GTK_LABEL (label),
			    "<b>ati Remote Control Tool</b>");
      gtk_box_pack_start (GTK_BOX (vbox), label, FALSE, FALSE, 0);
      
      frame = gtk_frame_new (NULL);
      gtk_frame_set_shadow_type (GTK_FRAME (frame), GTK_SHADOW_IN);
      /* The alignment keeps the frame from growing when users resize
       * the window
       */
      align = gtk_alignment_new (0.5, 0.5, 0, 0);
      gtk_container_add (GTK_CONTAINER (align), frame);
      gtk_box_pack_start (GTK_BOX (vbox), align, FALSE, FALSE, 0);

      /* demo_find_file() looks in the the current directory first,
       * so you can run gtk-demo without installing GTK, then looks
       * in the location where the file is installed.
       */
      pixbuf = NULL;
      
      if (filename)
	{
	  pixbuf = gdk_pixbuf_new_from_file (filename, &error);
	  g_free (filename);
	}

      if (error)
	{
	  /* This code shows off error handling. You can just use
	   * gtk_image_new_from_file() instead if you don't want to report
	   * errors to the user. If the file doesn't load when using
	   * gtk_image_new_from_file(), a "missing image" icon will
	   * be displayed instead.
	   */
	  GtkWidget *dialog;
	  
	  dialog = gtk_message_dialog_new (GTK_WINDOW (window),
					   GTK_DIALOG_DESTROY_WITH_PARENT,
					   GTK_MESSAGE_ERROR,
					   GTK_BUTTONS_CLOSE,
					   "Unable to open image file 'gtk-logo-rgb.gif': %s",
					   error->message);
	  g_error_free (error);
	  
	  g_signal_connect (dialog, "response",
			    G_CALLBACK (gtk_widget_destroy), NULL);
	  
	  gtk_widget_show (dialog);
	}
	  
      image = gtk_image_new_from_pixbuf (pixbuf);

      gtk_container_add (GTK_CONTAINER (frame), image);


    /* ///////////////////////////////////////////////////////////////// */

    
    /* This packs the button into the window (a gtk container). */
    gtk_container_add (GTK_CONTAINER (vbox), button);
    
    /* The final step is to display this newly created widget. */
  //  gtk_widget_show (button);
    
    /* and the window */
   // gtk_widget_show (window);
    
    if (!GTK_WIDGET_VISIBLE (window))
    {
      gtk_widget_show_all (window);
    }
  else
    {
      gtk_widget_destroy (window);
      window = NULL;
    }
    /* All GTK applications must have a gtk_main(). Control ends here
     * and waits for an event to occur (like a key press or
     * mouse event). */
    gtk_main ();
    
    return 0;
}
