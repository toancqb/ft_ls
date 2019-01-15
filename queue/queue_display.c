/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   queue_display.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qtran <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/13 19:21:49 by qtran             #+#    #+#             */
/*   Updated: 2019/01/13 19:21:56 by qtran            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_queue_lib.h"

void	queue_display_origin(t_queue *qt)
{
  if (qt)
  {
    while (qt != NULL)
    {
      ft_putstr(qt->content); ft_putstr("  ");
      qt = qt->next;
    }
    ft_putchar('\n');
  }
}
