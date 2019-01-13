#include "ft_queue_lib.h"

void queue_display(t_queue *qt)
{
  if (qt)
  {
    while (qt != NULL)
    {
      ft_putstr(qt->str); ft_putstr("  ");
      qt = qt->next;
    }
    //ft_putchar('\n');
  }
}
