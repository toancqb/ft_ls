#ifndef FT_QUEUE_LIB_H
# define FT_QUEUE_LIB_H
# include <stdlib.h>
# include "../libft/libft.h"

typedef struct s_queue
{
  char *str;
  int len_max;
  struct s_queue *next;
} t_queue;

t_queue **queue_init_root(void);
void queue_clr_all(t_queue **qt);
void queue_clr_one(t_queue **q);
t_queue *queue_init_one(char *s, int len);
int queue_is_empty(t_queue *qt);
int queue_num_elem(t_queue *qt);
char *queue_pop(t_queue **qt);
void queue_push(t_queue **qt, t_queue *q);
void queue_display(t_queue *qt);

#endif
