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
	//t_queue *tmp2;

//	tmp2 = *a;
	tmp = queue_init_one((*a)->content, (*a)->len_max);
	(*a)->content      = (*b)->content;
	(*a)->len_max 		 = (*b)->len_max;

	(*b)->content      = tmp->content;
	(*b)->len_max 		 = tmp->len_max;
//	free(tmp2->content);
}

int		is_M(char s)
{
	return (s >= 'A' && s <= 'Z');
}

int		is_m(char s)
{
	return (s >= 'a' && s <= 'z');
}

int		Mm_cmp(char s1, char s2)
{
	if (is_m(s1) && is_M(s2))
	{
		return (s1 - ('a' - 'A') - s2);
	}
	else if (is_M(s1) && is_m(s2))
	{
		return (s1 + ('a' - 'A') - s2);
	}
	return (s1 - s2);
}

int		ft_strcmp_alphabet(char *s1, char *s2)
{
	size_t i;

	i = 0;
	while (s1[i] != '\0' || s2[i] != '\0')
	{
		if (Mm_cmp(s1[i], s2[i]))
			return (Mm_cmp(s1[i], s2[i]));
		i++;
	}
	return (0);
}

int		ft_strcmp_reverse(char *s1, char *s2)
{
	size_t i;

	i = 0;
	while (s1[i] != '\0' || s2[i] != '\0')
	{
		if (Mm_cmp(s2[i], s1[i]))
			return (Mm_cmp(s2[i], s1[i]));
		i++;
	}
	return (0);
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
