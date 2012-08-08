#ifndef UI
#define UI

void init_colors();

void render_header(char label[], int task_list_size, int width, int color, int row, int col);
void render_task(Task task, int row, int col);
void render_list(Task *tasks, int len, int color, int row, int col);

void render_today(Task *tasks, int len);
void render_next(Task *tasks, int len);

void init_colors();

void render(TaskList * task_list);

#endif
