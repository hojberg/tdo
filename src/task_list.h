#include "task.h"

#ifndef TASK_LIST
#define TASK_LIST

typedef struct TaskList {

  int today_count;
  Task today[20];

  int next_count;
  Task next[100];

  int complete_count;
  Task complete[10];

} TaskList;

#endif
