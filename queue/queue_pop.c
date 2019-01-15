/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   queue_pop.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qtran <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/13 19:23:08 by qtran             #+#    #+#             */
/*   Updated: 2019/01/13 19:23:45 by qtran            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_queue_lib.h"

char	*queue_pop(t_queue **qt)
{
  t_queue	*q;
  char		*tmp;

  if (!qt || !(*qt))
    return (NULL);
  if ((*qt)->next == NULL)
  {
    tmp = ft_strdup((*qt)->content);
    queue_clr_one(qt);
    *qt = NULL;
  }
  else
  {
    q = *qt;
    tmp = ft_strdup(q->content);
    *qt = (*qt)->next;
    queue_clr_one(&q);
  }
  return (tmp);
}
