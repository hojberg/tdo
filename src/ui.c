#include <ncurses.h>
#include "task.h"

const int MARGIN = 5;

void render_list(Task *tasks, int row, int col) {
  int i;
  int len = 1;

  for (i = 0; i < len; i++) {
    move(row + i, col);
	  printw("%s", tasks[i].description);
  }
}

void render_incomplete(Task *tasks) {
  move(2, 5);

  attron(COLOR_PAIR(3));
  printw("TODAY");
  attroff(COLOR_PAIR(2));

  attron(COLOR_PAIR(0));
  render_list(tasks, 4, 5);
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

void render(Task *tasks) {	
  initscr();
  init_colors();

  render_incomplete(tasks);
  refresh();

  getch();
  endwin();
}
