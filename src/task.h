#include <time.h>

typedef struct {
  int     id;
  char    description[256];
  int     estimate;
  int     position;
  time_t  due_on;

} Task;
