#include <time.h>

#ifndef TASK
#define TASK

typedef struct Task {
  int     id;
  char    description[256];
  int     estimate;
  int     position;
  time_t  due_on;
} Task;

#endif
