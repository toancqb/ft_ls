#include "ft_queue_lib.h"

char	*ft_strdup2(const char *s1)
{
	char	*str;
	int		i;

	if (!(str = (char*)malloc(sizeof(char) * (ft_strlen(s1) + 1))) || !str)
		return (NULL);
	i = 0;
	while (s1[i] != '\0')
	{
		str[i] = s1[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

char *queue_pop(t_queue **qt)
{
  t_queue *q;
  char *tmp;

  if (!qt || !(*qt))
    return (NULL);
  if ((*qt)->next == NULL)
  {
    tmp = ft_strdup2((*qt)->str);
    //free((*qt)->str);
  //  free(*qt);
    *qt = NULL;
  }
  else
  {
    q = *qt;
    tmp = ft_strdup2(q->str);
    *qt = (*qt)->next;
  //  free(q->str);
  //  free(q);
  }
  return (tmp);
}
