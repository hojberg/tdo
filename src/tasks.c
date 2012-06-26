#include <stdio.h>
#include <time.h>
#include <string.h>
#include <sqlite3.h>
#include "task.h"

void fetch_incomplete_tasks(Task *tasks) {
  char query[] = "SELECT * FROM tasks";
  char database[] = "db/tdo.db";
  sqlite3 *conn;
  sqlite3_stmt *res;
  const char *tail;
  int i = 0;

  sqlite3_open(database, &conn);
  sqlite3_prepare_v2(conn, query, 1000, &res, &tail);

  while(sqlite3_step(res) == SQLITE_ROW) {
    Task task;
    // pull out description
    const unsigned char* desc = sqlite3_column_text(res, 1); 
    
    // build task
    strcpy(task.description, (char*)desc);

    task.id         = sqlite3_column_int(res, 0);
    task.estimate   = sqlite3_column_int(res, 2);
    task.position   = sqlite3_column_int(res, 3);
    task.due_on     = sqlite3_column_int(res, 5);

    // append to array
    tasks[i] = task;

    i++;
  }

  sqlite3_finalize(res);
  sqlite3_close(conn);
}

void create_task() {
}

void update_task() {
}

void remove_task() {
}
