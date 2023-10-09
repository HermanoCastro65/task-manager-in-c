#include "buttons.h"

#include "../task/task.h"

GtkWidget * descriptionEntry;
GtkWidget * dateTimeEntry;
GtkWidget * addTaskWindow;

void on_add_button_clicked(GtkWidget * widget, gpointer data) {
  addTaskWindow = gtk_window_new(GTK_WINDOW_TOPLEVEL);
  gtk_window_set_title(GTK_WINDOW(addTaskWindow), "Add Task");
  gtk_container_set_border_width(GTK_CONTAINER(addTaskWindow), 10);

  descriptionEntry = gtk_entry_new();
  dateTimeEntry = gtk_entry_new();

  time_t current_time;
  struct tm * time_info;
  char date_time_buffer[40];

  time( & current_time);
  time_info = localtime( & current_time);

  strftime(date_time_buffer, sizeof(date_time_buffer), "%Y-%m-%d %H:%M:%S", time_info);

  gtk_entry_set_text(GTK_ENTRY(dateTimeEntry), date_time_buffer);
  gtk_widget_set_can_focus(dateTimeEntry, FALSE);

  GtkWidget * confirmButton = gtk_button_new_with_label("Confirm");
  g_signal_connect(confirmButton, "clicked", G_CALLBACK(on_confirm_button_clicked), NULL);

  GtkWidget * vbox = gtk_vbox_new(TRUE, 5);
  gtk_box_pack_start(GTK_BOX(vbox), descriptionEntry, TRUE, TRUE, 0);
  gtk_box_pack_start(GTK_BOX(vbox), dateTimeEntry, TRUE, TRUE, 0);
  gtk_box_pack_start(GTK_BOX(vbox), confirmButton, TRUE, TRUE, 0);

  gtk_container_add(GTK_CONTAINER(addTaskWindow), vbox);

  gtk_widget_show_all(addTaskWindow);
}

void on_confirm_button_clicked(GtkWidget * widget, gpointer data) {
  const gchar * description = gtk_entry_get_text(GTK_ENTRY(descriptionEntry));
  const gchar * dateTime = gtk_entry_get_text(GTK_ENTRY(dateTimeEntry));

  strcpy(tasks[taskCount].description, description);
  strcpy(tasks[taskCount].dateTime, dateTime);
  tasks[taskCount].completed = 0;
  taskCount++;

  g_print("%s %s \n", description, dateTime);
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