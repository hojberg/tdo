#include <stdlib.h>
#include <stdio.h>

#include "tasks.h"
#include "task_list.h"
#include "ui.h"

int main() {
  TaskList task_list;

  fetch_incomplete_tasks(&task_list);
  render(&task_list);

  return 0;
}
