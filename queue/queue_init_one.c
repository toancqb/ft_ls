/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   queue_init_one.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qtran <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/13 19:22:02 by qtran             #+#    #+#             */
/*   Updated: 2019/01/13 19:22:15 by qtran            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_queue_lib.h"

t_queue	*queue_init_one(char *s, int len)
{
  t_queue	*q;
  int		i;

  q = (t_queue*)malloc(sizeof(t_queue));
  q->len_max = len + 1;
  q->content = (char*)malloc(sizeof(char) * q->len_max);
  i = 0;
  while (i <= len && s[i] != '\0')
  {
    q->content[i] = s[i];
    i++;
  }
  q->content[i] = '\0';
  q->next = NULL;
  return (q);
}
