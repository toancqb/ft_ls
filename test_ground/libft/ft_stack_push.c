/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stack_push.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qtran <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/15 19:20:56 by qtran             #+#    #+#             */
/*   Updated: 2017/11/15 20:13:42 by qtran            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_stack_push(t_list **st, t_list *new)
{
	t_list *tmp;

	if (st)
	{
		if (*st == NULL)
		{
			*st = new;
		}
		else
		{
			tmp = *st;
			while (tmp->next)
			{
				tmp = tmp->next;
			}
			tmp->next = new;
		}
	}
}
