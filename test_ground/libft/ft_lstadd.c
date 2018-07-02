/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qtran <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/15 16:47:55 by qtran             #+#    #+#             */
/*   Updated: 2017/11/15 17:26:40 by qtran            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd(t_list **lst, t_list *new)
{
	t_list *tmp;

	if (lst)
	{
		if (*lst == NULL)
		{
			*lst = new;
			(*lst)->next = 0;
		}
		else
		{
			tmp = *lst;
			*lst = new;
			new->next = tmp;
		}
	}
}
