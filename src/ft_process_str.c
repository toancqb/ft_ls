/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_process_str.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qtran <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/03 09:50:50 by qtran             #+#    #+#             */
/*   Updated: 2018/07/03 22:16:33 by qtran            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_lib_ls.h"

static void	ft_assign_op(t_option *op, char c)
{
	if (c == 'l')
		op->l = 1;
	if (c == 'R')
		op->R = 1;
	if (c == 'a')
		op->a = 1;
	if (c == 'r')
		op->r = 1;
	if (c == 't')
		op->t = 1;
}

int			ft_is_op_valid_assign(char *ch, t_option *op)
{
	int		len;

	len = ft_strlen(ch);
	len--;
	if (ch[0] == '-')
	{
		while (len >= 0)
		{
			if (!(ch[len] == 'l' || ch[len] == 'R' || ch[len] == 'a' 
					|| ch[len] == 'r' || ch[len] == 't'))
				return (0);
			ft_assign_op(op, ch[len]);
			len--;
		}
		return (1);
	}
	return (0);
}

void	ft_space(int n, int count)
{
	int i;

	if (count % 4 != 0)
	{
		i = 0;
		if (n < SP)
			i = SP - n;
		else
			i = 1;
		while (i > 0)
		{
			ft_putstr(" ");
			i--;
		}
	}
	else
		ft_putstr("\n");
}

void	ft_print_dir(const char *path)
{
	ft_putstr(path);
	ft_putstr(":\n");
}
