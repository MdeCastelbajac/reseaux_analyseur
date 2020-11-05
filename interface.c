#include "interface.h"

void print_hello (GtkWidget *widget, gpointer   data)
{
	g_print ("Hello World\n");
}

void activate (GtkApplication *app,gpointer        user_data)
{
	GtkWidget *window;
	GtkWidget *button;
	GtkWidget *button_box;
	
	//creation de la nouvelle fenetre et de ses boutons
	window = gtk_application_window_new (app);
	//titre de la fenetre
	gtk_window_set_title (GTK_WINDOW (window), "Analyseur de Trames");
	//taille de la fenetre
	gtk_window_set_default_size (GTK_WINDOW (window), 600, 400);
	
	
	button_box = gtk_button_box_new (GTK_ORIENTATION_HORIZONTAL);
	gtk_container_add (GTK_CONTAINER (window), button_box);

	button = gtk_button_new_with_label ("Hello World");
	g_signal_connect (button, "clicked", G_CALLBACK (print_hello), NULL);
	g_signal_connect_swapped (button, "clicked", G_CALLBACK (gtk_window_close), window);
	gtk_container_add (GTK_CONTAINER (button_box), button);

	gtk_widget_show_all (window);
}