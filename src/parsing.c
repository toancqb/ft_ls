/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qtran <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/18 20:14:06 by qtran             #+#    #+#             */
/*   Updated: 2018/12/18 20:15:53 by qtran            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls_lib.h"

void	parsing_name_all(t_env *env
	, void (*sx)(t_queue**, int (*ft_strcmp_Mm)(char*,char*)))
{
	DIR *dir;
	struct dirent *dptr;
	const char *n;

	ERROR_CHECK((dir = opendir(env->path)));
	while((dptr = readdir(dir)) != NULL)
	{
		n = ft_strdup(dptr->d_name);
		queue_push(env->qt, queue_init_one((char*)n, ft_strlen(n)));
		free(n);
	}
	(*sx)(env->qt, &ft_strcmp_alphabet);
	ERROR_CHECK((!closedir(dir)));
}

void	parsing_name_simple(t_env *env
	, void (*sx)(t_queue**, int (*ft_strcmp_Mm)(char*,char*)))
{
	DIR *dir;
	struct dirent *dptr;
	const char *n;

	ERROR_CHECK((dir = opendir(env->path)));
	while((dptr = readdir(dir)) != NULL)
	{
		n = ft_strdup(dptr->d_name);
		if (!isHidden_sp(n))
			queue_push(env->qt, queue_init_one((char*)n, ft_strlen(n)));
		free(n);
	}
	(*sx)(env->qt, &ft_strcmp_alphabet);
	ERROR_CHECK((!closedir(dir)));
}

int ft_aR(const char *name, t_queue **qt
, void (*sx)(t_queue**, int (*ft_strcmp_Mm)(char*,char*))) //++
{
	DIR				*dir;
	struct dirent	*dptr;
	const char		*n;
	char			path[PATH_LEN_MAX];
	t_queue			**qt_local;

	if (!isDir(name))
		return (0);
	qt_local = queue_init_root();
	ERROR_CHECK((dir = opendir(name)));
	ft_putstr(name); ft_putstr(":\n");
	while ((dptr = readdir(dir)) != NULL)
	{
		n = (const char*)dptr->d_name;
		queue_push(qt_local, queue_init_one((char*)n, ft_strlen((char*)n)));
	}
	(*sx)(qt_local, &ft_strcmp_alphabet);
	queue_display(*qt_local);
	while (!queue_is_empty(*qt_local))
	{
		ft_strjoin_npath(path, PATH_LEN_MAX, (char*)name, queue_pop(qt_local));
		if (isDir(path) && !isHidden_pwd(path))
		{
			ft_putstr("\n");
			ft_aR(path, qt, sx);
		}
	}
	queue_clr_all(qt_local);
	ERROR_CHECK(!(closedir(dir)));
	return (1);
}

int ft_R(const char *name, t_queue **qt
, void (*sx)(t_queue**, int (*ft_strcmp_Mm)(char*,char*))) //++
{
	DIR				*dir;
	struct dirent	*dptr;
	const char		*n;
	char			path[PATH_LEN_MAX];
	t_queue			**qt_local;

	if (!isDir(name))
		return (0);
	qt_local = queue_init_root();
	ERROR_CHECK((dir = opendir(name)));
	ft_putstr(name); ft_putstr(":\n");
	while ((dptr = readdir(dir)) != NULL)
	{
		n = (const char*)dptr->d_name;
		if (!isHidden_sp(n))
			queue_push(qt_local, queue_init_one((char*)n, ft_strlen((char*)n)));
	}
	(*sx)(qt_local, &ft_strcmp_alphabet);
	queue_display(*qt_local);
	while (!queue_is_empty(*qt_local))
	{
		ft_strjoin_npath(path, PATH_LEN_MAX, (char*)name, queue_pop(qt_local));
		if (isDir(path) && !isHidden_sp(path))
		{
			ft_putstr("\n");
			ft_R(path, qt, sx);
		}
	}
	queue_clr_all(qt_local);
	ERROR_CHECK(!(closedir(dir)));
	return (1);
}

void	parsing_name_aR(t_env *env
	, void (*sx)(t_queue**, int (*ft_strcmp_Mm)(char*,char*))) //++
{
	ft_aR(env->path, env->qt, sx);
}

void	parsing_name_R(t_env *env
	, void (*sx)(t_queue**, int (*ft_strcmp_Mm)(char*,char*))) //++
{
	ft_R(env->path, env->qt, sx);
}

void	parsing_name(t_env *env
	, void (*f_parse)(t_env *env
		, void (*sx)(t_queue**, int (*ft_strcmp_Mm)(char*,char*))))
{
	(*f_parse)(env, &sorting);
}
