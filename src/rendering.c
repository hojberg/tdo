#include <ncurses.h>
#include "tdo.h"

const int MARGIN = 5;

void render_list(char *list[], int row, int col)
{
  int i;

  for (i = 0; i < 4; i++)
  {
    move(row + i, col);
	  printw(list[i]);
  }
}

// ----- NEXT ----- //
void render_next()
{
  move(2, 50);
  printw("NEXT");
}


// ----- TODAY ----- //

void render_due_today()
{
  // TODO move this to a getter func
  char *today[4] = {"pick up joan at airport", 
                    "phone laundry service", 
                    "set up apartment showing", 
                    "finish leaderboard ui"};

  move(2, 5);

	attron(COLOR_PAIR(3));
  printw("TODAY");
	attroff(COLOR_PAIR(2));

	attron(COLOR_PAIR(0));
  render_list(today, 4, 5);
	attroff(COLOR_PAIR(0));
}

void render_completed()
{
  // TODO move this to a getter func
  char *completed[4] = {"pick up joan at airport", 
                        "phone laundry service", 
                        "set up apartment showing", 
                        "finish leaderboard ui"};

  move(18, 5);

	attron(COLOR_PAIR(2));
  printw("COMPLETED");
	attroff(COLOR_PAIR(2));

	attron(COLOR_PAIR(1));
  render_list(completed, 20, 5);
	attroff(COLOR_PAIR(1));
}

void render_today()
{
	render_due_today();
	render_completed();
}

void render()
{
	render_today();
	render_next();
	refresh();
}

void init_colors()
{
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

int render()
{	
	initscr();
	init_colors();

	fetch_tasks();

	render();

	getch();
	endwin();

	return 0;
}
