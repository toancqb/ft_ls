#include "ft_queue_lib.h"

int queue_num_elem(t_queue *qt)
{
  t_queue *q;
  int count;

  if (!qt)
    return (0);
  q = qt;
  count = 0;
  while (q != NULL)
  {
    count++;
    q = q->next;
  }
  return (count);
}
