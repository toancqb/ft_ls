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

char *ft_strjoin_path(char *str1, char *str2)
{
	char *str;
	int	i;
	int	j;

	str = (char*)malloc(sizeof(char) * (ft_strlen(str1) + ft_strlen(str2)));
	str[ft_strlen(str1) + ft_strlen(str2)] = '\0';
	i = 0;
	while (str1[i] != '\0')
	{
		str[i] = str1[i];
		i++;
	}
	str[i] = 47;
	j = 0;
	i++;
	while (str2[j] != '\0')
	{
		str[i] = str2[j];
		i++;
		j++;
	}
	return (str);
}

void	ft_putnstr(char *str, int len)
{
	int i;

	i = 0;
	while (i < len && str[i] != '\0')
	{
		ft_putchar(str[i]);
		i++;
	}
}