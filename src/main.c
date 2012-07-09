#include <stdlib.h>
#include <stdio.h>

#include "tasks.h"
#include "task.h"
#include "ui.h"

int main() {
  Task tasks[20];

  fetch_incomplete_tasks(tasks);
  render(tasks);

  return 0;
}
