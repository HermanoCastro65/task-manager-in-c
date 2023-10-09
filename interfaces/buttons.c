#include "buttons.h"

#include "../task/task.h"

GtkWidget * descriptionEntry;
GtkWidget * dateEntry;
GtkWidget * addTaskWindow;

void on_add_button_clicked(GtkWidget * widget, gpointer data) {
  addTaskWindow = gtk_window_new(GTK_WINDOW_TOPLEVEL);
  gtk_window_set_title(GTK_WINDOW(addTaskWindow), "Add Task");
  gtk_container_set_border_width(GTK_CONTAINER(addTaskWindow), 10);

  descriptionEntry = gtk_entry_new();
  dateEntry = gtk_entry_new();

  GtkWidget * confirmButton = gtk_button_new_with_label("Confirm");
  g_signal_connect(confirmButton, "clicked", G_CALLBACK(on_confirm_button_clicked), NULL);

  GtkWidget * vbox = gtk_vbox_new(TRUE, 5);
  gtk_box_pack_start(GTK_BOX(vbox), descriptionEntry, TRUE, TRUE, 0);
  gtk_box_pack_start(GTK_BOX(vbox), dateEntry, TRUE, TRUE, 0);
  gtk_box_pack_start(GTK_BOX(vbox), confirmButton, TRUE, TRUE, 0);

  gtk_container_add(GTK_CONTAINER(addTaskWindow), vbox);

  gtk_widget_show_all(addTaskWindow);
}

void on_confirm_button_clicked(GtkWidget * widget, gpointer data) {
  const gchar * description = gtk_entry_get_text(GTK_ENTRY(descriptionEntry));
  const gchar * date = gtk_entry_get_text(GTK_ENTRY(dateEntry));

  strcpy(tasks[taskCount].description, description);
  strcpy(tasks[taskCount].date, date);
  tasks[taskCount].completed = 0;
  taskCount++;

  gtk_widget_destroy(addTaskWindow);
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