/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_path.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qtran <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/03 12:42:30 by qtran             #+#    #+#             */
/*   Updated: 2018/07/03 14:46:43 by qtran            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_lib_ls.h"

int		is_file_hidden(const char *path)
{
	int len;

	len = ft_strlen(path);
	len--;
	while(len >= 0 && path[len] != '/')
	{
		if (path[len] == '.' && (len == 0 || (len > 0 && path[len - 1] == '/')))
			return (1);
		len--;
	}
	return (0);
}

int		is_dir(const char *path)
{
	struct stat statbuf;

	if (stat(path, &statbuf) != 0 || is_file_hidden(path))
		return (0);
	return (S_ISDIR(statbuf.st_mode));
}
