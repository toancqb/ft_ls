#include "ft_queue_lib.h"

void queue_push(t_queue **qt, t_queue *q)
{
  t_queue *tmp;

  tmp = NULL;
  if (qt && q)
  {
    if (*qt == NULL)
        *qt = q;
    else
    {
        tmp = *qt;
        while (tmp->next != NULL)
          tmp = tmp->next;
        tmp->next = q;
    }
  }
}
