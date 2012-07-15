#include "task.h"

#ifndef TASK_LIST
#define TASK_LIST

typedef struct TaskList {

  int today_count;
  Task today[20];
  /*
  int size = 30 * sizeof( *tasks );
  tasks = malloc( size );
  */

} TaskList;

#endif
