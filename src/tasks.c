#include <stdio.h>
#include <time.h>
#include <string.h>
#include <sqlite3.h>
#include "task.h"
#include "task_list.h"

void fetch_incomplete_tasks(TaskList *task_list) {
  char query[] = "SELECT * FROM tasks WHERE completed = 0";
  char database[] = "db/tdo.db";
  sqlite3 *conn;
  sqlite3_stmt *res;
  const char *tail;
  int i = 0;

  sqlite3_open(database, &conn);
  sqlite3_prepare_v2(conn, query, 1000, &res, &tail);

  while (sqlite3_step(res) == SQLITE_ROW) {
    Task task;

    // pull out description
    const unsigned char* desc = sqlite3_column_text(res, 1); 

    // build task
    strncpy(task.description, (char *)desc, 256);

    task.id         = sqlite3_column_int(res, 0);
    task.estimate   = sqlite3_column_int(res, 2);
    task.position   = sqlite3_column_int(res, 3);
    task.due_on     = sqlite3_column_int(res, 5);

    // append to array
    task_list->today[i] = task;

    i++;
  }

  task_list->today_count = i;

  sqlite3_finalize(res);
  sqlite3_close(conn);
}
