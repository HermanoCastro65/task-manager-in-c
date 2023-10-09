#ifndef TASK
#define TASK

typedef struct {
  char description[100];
  char date[20];
  int completed;
}
Task;

Task tasks[100];
int taskCount = 0;

#endif