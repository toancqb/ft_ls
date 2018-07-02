/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qtran <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/02 21:12:47 by qtran             #+#    #+#             */
/*   Updated: 2018/07/02 22:32:22 by qtran            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_lib.h"

void	ft_format(int count)
{
	if (count % 4)
		ft_putstr("         ");
	else
		ft_putstr("\n");	
}

int isHidden(const char *path)
{
	int len = ft_strlen(path);

	len--;
	while (len >= 0 && path[len] != '/')
	{
		if (path[len] == '.' && (len == 0 || (len > 0 && path[len - 1] == '/')))
			return (1);
		len--;
	}
	return (0);
}

int isDir(const char *path)
{
	struct stat statbuf;

	if (stat(path, &statbuf) != 0 || isHidden(path))
		return (0);
	return S_ISDIR(statbuf.st_mode);
}

int ft_R(const char *name)
{
	DIR				*dirp;
	struct dirent	*dp;
	int				count = 0;
	t_list			*st = NULL;
	
	if (!isDir(name))
		return (0);
	dirp = opendir(name);
	while ((dp = readdir(dirp)) != NULL)
	{
		ft_putstr(dp->d_name);
		if (isDir((const char*)&dp->d_name))
			ft_stack_push(&st, ft_stack_init_elem((const char*)&dp->d_name, ft_strlen((const char *)&dp->d_name)));
		ft_format(++count);
	}
	while (ft_stack_num_elem(st) != 0)
	{
		ft_R((const char*)ft_stack_pop(&st));
	}
	(void)closedir(dirp);
	return (0);
}

int ft_R_level(int level_deep)
{
	DIR				*dirp;
	struct dirent	*dp;
	int				count = 0;

	dirp = opendir("./");
	if (/*(dirp = opendir(".")) ||*/ !dirp)
		return (-1);
	if (level_deep == 1)
		while ((dp = readdir(dirp)) != NULL)
		{
			ft_putstr(dp->d_name);
			ft_format(++count);
	
		}
	else
	{
		ft_R("./");
	}
	(void)closedir(dirp);	
	return (0);	
}

int main(int argc, char *argv[])
{
	ft_R_level(0);	
	return (0);
}
