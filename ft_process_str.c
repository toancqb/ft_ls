/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_process_str.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qtran <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/03 09:50:50 by qtran             #+#    #+#             */
/*   Updated: 2018/07/03 09:57:58 by qtran            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"

int		ft_is_option_valid(char *ch)
{
	int		len;

	len = ft_strlen(ch);
	len--;
	if (ch[0] == '-')
	{
		while (len >= 0)
		{
			if (!(ch[len] == 'l' || ch[len] == 'R' || ch[len] == 'a' 
					|| ch[len] = 'r' || ch[len] = 't'))
				return (0);
			len--;
		}
		return (1);
	}
	return (0);
}
