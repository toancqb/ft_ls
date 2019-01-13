#include "ft_queue_lib.h"

t_queue *queue_init_one(char *s, int len)
{
  t_queue *q;
  int i;

  q = (t_queue*)malloc(sizeof(t_queue));
  q->len_max = len + 1;
  q->str = (char*)malloc(sizeof(char) * q->len_max);
  i = 0;
  while (i <= len && s[i] != '\0')
  {
    q->str[i] = s[i];
    i++;
  }
  q->str[i] = '\0';
  q->next = NULL;
  return (q);
}
