/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_process.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qtran <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/18 20:14:59 by qtran             #+#    #+#             */
/*   Updated: 2018/12/18 20:15:05 by qtran            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls_lib.h"

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

int		ft_strcmp_Mm(char *s1, char *s2)
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
