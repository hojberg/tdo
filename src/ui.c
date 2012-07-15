#include <ncurses.h>
#include "task_list.h"
#include "task.h"

const int MARGIN = 5;

void render_list(Task *tasks, int len, int row, int col) {
  int i = 0;
  Task task;

  for (i = 0; i < len; i++) {
    task = tasks[i];
    move(row + i, col);
    printw("%s", task.description);
  }
}

void render_incomplete(Task *tasks, int len) {
  move(2, 5);

  attron(COLOR_PAIR(3));
  printw("TODAY");
  for (int i = 10; i < 60; i++) {
    move(2, i);
    printw(" ");
  }
  move(2, 60);
  printw("%d", len);
  attroff(COLOR_PAIR(2));

  attron(COLOR_PAIR(0));
  render_list(tasks, len, 4, 5);
  attroff(COLOR_PAIR(0));
}

void init_colors() {
	start_color();

  // white / black
  init_pair(0, COLOR_WHITE, COLOR_BLACK);
	
  // grey / black
  init_pair(1, 8, COLOR_BLACK);
	
  // black / grey 
  //init_pair(2, COLOR_BLACK, 7);
  init_pair(2, 12, 0);

  // black / orange
  init_pair(3, COLOR_BLACK, 3);
} 

void render(TaskList task_list) {	
  initscr();
  init_colors();

  render_incomplete(task_list.today, 
                    task_list.today_count);

  refresh();

  getch();
  endwin();
}
