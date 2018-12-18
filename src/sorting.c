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

void	swap_alphabet(t_list **a, t_list **b)
{
	t_list *tmp;

	tmp = (t_list*)malloc(sizeof(t_list));
	tmp->content = (*a)->content;
	tmp->content_size = (*a)->content_size;
	(*a)->content = (*b)->content;
	(*a)->content_size = (*b)->content_size;
	(*b)->content = tmp->content;
	(*b)->content_size = tmp->content_size;
	free(tmp);
}

void	sorting(t_list **st, int (*f_sort)(char*,char*))
{
	t_list *tmp_i;
	t_list *tmp_j;

	//tmp_i = (t_list*)malloc(sizeof(t_list));
	if (st && *st)
	{
		tmp_i = *st;
		while (tmp_i != NULL)
		{
			tmp_j = tmp_i->next;
			while (tmp_j != NULL)
			{
				if ((*f_sort)(tmp_i->content, tmp_j->content) > 0)
					swap_alphabet(&tmp_i, &tmp_j);
				tmp_j = tmp_j->next;
			}
			tmp_i = tmp_i->next;
		}
	}
}
