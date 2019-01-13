/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   queue_push.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qtran <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/13 19:23:56 by qtran             #+#    #+#             */
/*   Updated: 2019/01/13 19:24:07 by qtran            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_queue_lib.h"

void	queue_push(t_queue **qt, t_queue *q)
{
  t_queue	*tmp;

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
