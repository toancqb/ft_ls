/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qtran <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/18 20:14:30 by qtran             #+#    #+#             */
/*   Updated: 2018/12/18 20:14:39 by qtran            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls_lib.h"

int	main(int argc, char *argv[])
{
	if (argc >= 30)
		ft_putstr("Too Many Arguments");
	else
		ft_ls((const char*)argv[1]);

		return (0);
}
