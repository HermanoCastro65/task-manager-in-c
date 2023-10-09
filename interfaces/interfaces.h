#ifndef INTERFACES
#define INTERFACES

#include <gtk/gtk.h>

void on_add_button_clicked(GtkWidget *widget, gpointer data);
void on_list_todo_button_clicked(GtkWidget *widget, gpointer data);
void on_list_completed_button_clicked(GtkWidget *widget, gpointer data);
void on_remove_button_clicked(GtkWidget *widget, gpointer data);

#endif

