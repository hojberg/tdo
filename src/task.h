#include <time.h>

typedef struct {
  int     id;
  char    * description[128];
  int     estimate;
  int     position;
  time_t  due_on;

} Task;
