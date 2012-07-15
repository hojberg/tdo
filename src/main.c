#include <stdlib.h>
#include <stdio.h>

#include "tasks.h"
#include "task.h"
#include "ui.h"

int main() {
  Task *tasks;

  // allocate 30 tasks initially
  int size = 30 * sizeof( *tasks );
  tasks = malloc( size );

  fetch_incomplete_tasks(tasks);
  render(tasks);

  return 0;
}
