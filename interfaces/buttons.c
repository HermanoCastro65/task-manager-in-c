#include "interfaces.h"

void on_add_button_clicked(GtkWidget * widget, gpointer data) {
  g_print("Add Task\n");
}

void on_list_todo_button_clicked(GtkWidget * widget, gpointer data) {
  g_print("List To-do Tasks\n");
}

void on_list_completed_button_clicked(GtkWidget * widget, gpointer data) {
  g_print("List Completes Tasks\n");
}

void on_remove_button_clicked(GtkWidget * widget, gpointer data) {
  g_print("Remove Task\n");
}