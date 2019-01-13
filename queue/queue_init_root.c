#include "ft_queue_lib.h"

t_queue **queue_init_root(void)
{
  t_queue **qt;

  qt = (t_queue**)malloc(sizeof(t_queue*));
  *qt = NULL;
  return (qt);
}
