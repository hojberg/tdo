#include <ncurses.h>
#include "task_list.h"
#include "task.h"

const int MARGIN = 5;

// list rendition
void render_header(char label[], int task_list_size, int width, int color, int row, int col) {
  move(row, col);

  attron(COLOR_PAIR(color));

  for (int i = col; i < width; i++) {
    move(row, i);
    printw(" ");
  }

  move(row, col);
  printw(" %s", label);

  move(row, width);
  printw("%d ", task_list_size);

  attroff(COLOR_PAIR(color));
}

void render_task(Task task, int row, int col) {
  move(row, col);

  if (0) {
    printw("OVERDUE ");
  }

  printw("%s", task.description);
}

void render_list(Task *tasks, int len, int color, int row, int col) {
  int i = 0;
  Task task;

  attron(COLOR_PAIR(color));
  for (; i < len; i++) {
    task = tasks[i];
    render_task(task, row + i, col);
  }
  attroff(COLOR_PAIR(color));
}

// render specifics
void render_today(Task *tasks, int len) {
  render_header("TODAY", len, 60, 3, 2, 5);
  render_list(tasks, len, 0, 4, 5);
}

void render_next(Task *tasks, int len) {
  render_header("NEXT", len, 30, 3, 2, 80);
  render_list(tasks, len, 4, 4, 80);
}

void init_colors() {
	start_color();

  init_pair(0, 10, 0);
  init_pair(1, 8, 0);
  init_pair(2, 0, 10);
  init_pair(3, 0, 11);
} 

void render(TaskList task_list) {	
  initscr();
  init_colors();

  render_today(task_list.today, 
               task_list.today_count);

  render_next(task_list.next, 
              task_list.next_count);

  refresh();

  getch();
  endwin();
}
