/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   queue_num_elem.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qtran <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/13 19:22:49 by qtran             #+#    #+#             */
/*   Updated: 2019/01/13 19:23:02 by qtran            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_queue_lib.h"

int	queue_num_elem(t_queue *qt)
{
  t_queue	*q;
  int		count;

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
