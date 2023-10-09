#ifndef TASK
#define TASK

typedef struct {
  char description[100];
  char dateTime[40];
  int completed;
}
Task;

Task tasks[100];
int taskCount = 0;

#endif