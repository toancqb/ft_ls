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

	if (stat(path, &statbuf) != 0 /*|| isHidden(path)*/)
		return (0);
	return S_ISDIR(statbuf.st_mode);
}

int	isHidden_pwd(const char *path)
{
	int i;
	char **tab;

	if (!ft_strchr(path, '/'))
		return (!ft_strcmp(path, ".") || !ft_strncmp(path, "..", 2));
	tab = ft_strsplit(path, '/');
	i = 0;
	while (tab[i] != NULL)
	{
		i++;
	}
	return (!ft_strcmp(tab[i - 1], ".") || !ft_strncmp(tab[i - 1], "..", 2));
}

int	main(int argc, char *argv[])
{
	if (argc >= 30)
		ft_putstr("Too Many Arguments");
	else
		ft_ls((const char*)argv[1]);

	//printf("%d  %d \n", isHidden_pwd("libft"), isHidden_pwd(".."));
	//ft_putnbr(argc); ft_putstr(argv[1]); ft_putchar('\n');
	//ft_putnbr(isHidden_pwd(argv[1])); ft_putchar('\n');
	return (0);
}
