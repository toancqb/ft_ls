/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qtran <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/18 20:14:20 by qtran             #+#    #+#             */
/*   Updated: 2018/12/18 20:14:23 by qtran            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls_lib.h"

/*
 *	New Chapter: queue string
 */



/*
 *
 */

void	display_st(t_list *st)
{
	int count;

	count = 1;
	while(st != NULL)
	{
		ft_putnstr(st->content, st->content_size);
		(count % 4 != 0) ? ft_putstr("  ") : ft_putchar('\n');
		count++;
		st = st->next;
	}
	ft_putchar('\n');
}

void	display_simple(t_env *env)
{	
	ft_putchar('\n');
	while(*(env->st) != NULL)
	{
		//if ((*st)->content_size == 0)
		//	continue ;
		ft_putstr((*(env->st))->content);
		ft_putstr("  ");
		*(env->st) = (*(env->st))->next;
	}
}

void	display_simple2(t_env *env)
{
	display_st(*(env->st));
}

void	display_aR(t_env *env)
{
	while(*(env->st) != NULL)
	{
		if ((*(env->st))->isf == '1')
		{
			ft_putstr((*(env->st))->content);
			ft_putstr(":\n");
		}
		else
		{
			ft_putstr((*(env->st))->content);
			ft_putstr("  ");
		}
		(*(env->st)) = (*(env->st))->next;
	}
	ft_putchar('\n');
}
