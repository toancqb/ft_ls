/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_range.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qtran <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/03 12:41:33 by qtran             #+#    #+#             */
/*   Updated: 2018/07/03 22:19:22 by qtran            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_lib_ls.h"

int		ft_r_upper(const char *path)
{
	DIR				*dirp;
	struct dirent	*dp;
	t_list			*st;
	int				count;
	char			*str;

	count = 0;
	st = NULL;
	if (!is_dir(path))
		return (0);
	dirp = opendir(path);
	while ((dp = readdir(dirp)) != NULL)
	{
		ft_putstr(dp->d_name);
		if (is_dir((const char*)&dp->d_name))
			ft_queue_push(&st, ft_queue_init_elem((const char*)&dp->d_name,
						ft_strlen((const char*)&dp->d_name)));
		ft_space(ft_strlen((const char*)&dp->d_name), ++count);
	}
	ft_putstr("\n");
	while (ft_queue_is_empty(st) == 0)
	{
		str = (char*)ft_queue_pop(&st);
		ft_print_dir((const char*)str);
		ft_r_upper((const char*)str);
		ft_putstr("\n");
	}
	(void)closedir(dirp);
	return (0);
}

int		ft_r_upper_level(int level_deep)
{
	DIR				*dirp;
	struct dirent	*dp;
	int				count;

	count = 0;
	dirp = opendir("./");
	if (!dirp)
		return (-1);
	if (level_deep == 1)
		while ((dp = readdir(dirp)) != NULL)
		{
			ft_putstr(dp->d_name);
			ft_space(ft_strlen((const char*)&dp->d_name), ++count);
		}
	else
		ft_r_upper("./");
	(void)closedir(dirp);
	return (0);
}
