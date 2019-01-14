/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   queue_clr_all.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qtran <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/13 19:24:23 by qtran             #+#    #+#             */
/*   Updated: 2019/01/13 19:24:25 by qtran            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_queue_lib.h"

void queue_clr_all(t_queue **qt)
{
  t_queue *tmp;
  t_queue *t;

  if (qt || *qt == NULL)
  {
    tmp = *qt;
    while (tmp != NULL)
    {
      t = tmp;
      tmp = tmp->next;
      queue_clr_one(&t);
    }
  }
}
