/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qtran <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/18 20:14:47 by qtran             #+#    #+#             */
/*   Updated: 2018/12/18 20:14:52 by qtran            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls_lib.h"

static void	swap_lst(t_queue **a, t_queue **b)
{
	t_queue *tmp;
	t_queue *tmp2;

	tmp2 = *a;
	tmp = queue_init_one((*a)->content, (*a)->len_max);
	(*a)->content      = (*b)->content;
	(*a)->len_max 		 = (*b)->len_max;

	(*b)->content      = tmp->content;
	(*b)->len_max 		 = tmp->len_max;
	free(tmp2->content);
}

void	sorting(t_queue **qt, int (*f_sort)(char*,char*))
{
	t_queue *tmp_i;
	t_queue *tmp_j;

	if (qt && *qt)
	{
		tmp_i = *qt;
		while (tmp_i != NULL)
		{
			tmp_j = tmp_i->next;
			while (tmp_j != NULL)
			{
				if ((*f_sort)(tmp_i->content, tmp_j->content) > 0)
					swap_lst(&tmp_i, &tmp_j);
				tmp_j = tmp_j->next;
			}
			tmp_i = tmp_i->next;
		}
	}
}
