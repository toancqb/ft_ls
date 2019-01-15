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

void	queue_display(t_queue *qt)
 {
   if (qt)
   {
     while (qt != NULL)
     {
       ft_putstr(qt->content); ft_putstr("  ");
       qt = qt->next;
     }
     ft_putchar('\n');
   }
 }
