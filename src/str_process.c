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

int ft_strjoin_npath(char path[], int len_max, char *name, char *pop)
{
	int i;
	int j;

	i = 0;
	while (i < len_max && name[i] != '\0')
	{
		path[i] = name[i];
		i++;
	}
	if (i >= len_max)
	{
		path[i - 1] = '\0';
		return (0);
	}
	path[i] = '/';
	i++;
	j = 0;
	while (i < len_max && pop[j] != '\0')
	{
		path[i] = pop[j];
		i++;
		j++;
	}
	if (i >= len_max)
	{
		path[i - 1] = '\0';
		return (0);
	}
	path[i] = '\0';
	return (1);
}

int isDir(const char *path)
{
	struct stat statbuf;

	if (stat(path, &statbuf) != 0 /*|| isHidden(path)*/)
		return (0);
	return S_ISDIR(statbuf.st_mode);
}

int isDir2(const char *path)
{
	struct stat *buf;

	buf = NULL;
	if (stat(path, buf) != 0)
		return (0);
	if ((buf->st_mode & S_IFCHR) != S_IFCHR && (buf->st_mode & S_IFBLK)
			!= S_IFBLK && (buf->st_mode & S_IFDIR))
		return (1);
	return (0);
}

int	isHidden_pwd(const char *path)
{
	int i;
	char **tab;
	int check;

	check = 0;
	if (!ft_strchr(path, '/'))
		return (!ft_strcmp(path, ".") || !ft_strcmp(path, ".."));
	tab = ft_strsplit(path, '/');
	i = 0;
	while (tab[i] != NULL)
	{
		i++;
	}
	check = (!ft_strcmp(tab[i - 1], ".") || !ft_strcmp(tab[i - 1], ".."));
	while (tab[i] != NULL)
	{
		free(tab[i]);
		i++;
	}
	return (check);
}

int	isHidden_sp(const char *path)
{
	int i;
	char **tab;
	int check;

	check = 0;
	if (!ft_strchr(path, '/'))
		return (!ft_strncmp(path, ".", 1));
	tab = ft_strsplit(path, '/');
	i = 0;
	while (tab[i] != NULL)
	{
		i++;
	}
	check = (!ft_strncmp(tab[i - 1], ".", 1));
	while (tab[i] != NULL)
	{
		free(tab[i]);
		i++;
	}
	return (check);
}

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

	str = (char*)malloc(sizeof(char) * (ft_strlen(str1) + ft_strlen(str2) - 1));
	str[ft_strlen(str1) + ft_strlen(str2) - 1] = '\0';
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
