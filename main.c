#include "interfaces/interfaces.h"

GtkWidget * window;
GtkWidget * addButton;
GtkWidget * listToDoButton;
GtkWidget * listCompletedButton;
GtkWidget * removeButton;

int main(int argc, char * argv[]) {
  gtk_init( & argc, & argv);

  window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
  gtk_window_set_title(GTK_WINDOW(window), "Task Manager");
  gtk_container_set_border_width(GTK_CONTAINER(window), 10);
  gtk_widget_set_size_request(window, 300, 200);
  g_signal_connect(window, "destroy", G_CALLBACK(gtk_main_quit), NULL);

  addButton = gtk_button_new_with_label("Add Task");
  listToDoButton = gtk_button_new_with_label("List To Do Tasks");
  listCompletedButton = gtk_button_new_with_label("List Completed Tasks");
  removeButton = gtk_button_new_with_label("Remove Task");

  g_signal_connect(addButton, "clicked", G_CALLBACK(on_add_button_clicked), NULL);
  g_signal_connect(listToDoButton, "clicked", G_CALLBACK(on_list_todo_button_clicked), NULL);
  g_signal_connect(listCompletedButton, "clicked", G_CALLBACK(on_list_completed_button_clicked), NULL);
  g_signal_connect(removeButton, "clicked", G_CALLBACK(on_remove_button_clicked), NULL);

  GtkWidget * vbox = gtk_vbox_new(TRUE, 5);
  gtk_box_pack_start(GTK_BOX(vbox), addButton, TRUE, TRUE, 0);
  gtk_box_pack_start(GTK_BOX(vbox), listToDoButton, TRUE, TRUE, 0);
  gtk_box_pack_start(GTK_BOX(vbox), listCompletedButton, TRUE, TRUE, 0);
  gtk_box_pack_start(GTK_BOX(vbox), removeButton, TRUE, TRUE, 0);

  gtk_container_add(GTK_CONTAINER(window), vbox);

  gtk_widget_show_all(window);

  gtk_main();

  return 0;
}