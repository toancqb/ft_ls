/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_process_input.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qtran <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/03 09:47:23 by qtran             #+#    #+#             */
/*   Updated: 2018/07/03 14:51:47 by qtran            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_lib_ls.h"

void	ft_init_option(t_option *op)
{
	op = (t_option*)malloc(sizeof(t_option));
	op->l = 0;
	op->R = 0;
	op->a = 0;
	op->r = 0;
	op->t = 0;
}
/*
void	ft_input_option(char *str)
{
	
}*/