/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_process_input.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qtran <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/03 09:47:23 by qtran             #+#    #+#             */
/*   Updated: 2018/07/03 09:50:32 by qtran            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_lib_ls.h"

void	ft_init_option(t_option *op)
{
	op = (t_option*)malloc(sizeof(t_option));
	(int)op->l = 0;
	(int)op->R = 0;
	(int)op->a = 0;
	(int)op->r = 0;
	(int)op->t = 0;
}

void	ft_input_option(char *str)
{
	
}
