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
	, void (*sx)(t_list**, int (*ft_strcmp_Mm)(char*,char*)))
{
	DIR *dir;
	struct dirent *dptr;

	ERROR_CHECK((dir = opendir(env->path)));
	while((dptr = readdir(dir)) != NULL)
	{
		//ft_putstr(dptr->d_name); ft_putstr(" > ");
		ft_queue_push(env->st, ft_queue_init_elem((void*)(dptr->d_name)
			,ft_strlen(dptr->d_name)));
	}
	(*sx)(env->st, &ft_strcmp_Mm);
	ERROR_CHECK((!closedir(dir)));
}

void	parsing_name_simple(t_env *env
	, void (*sx)(t_list**, int (*ft_strcmp_Mm)(char*,char*)))
{
	DIR *dir;
	struct dirent *dptr;

	ERROR_CHECK((dir = opendir(env->path)));
	while((dptr = readdir(dir)) != NULL)
	{
		if (!isHidden((const char*)dptr->d_name))
		ft_queue_push(env->st, ft_queue_init_elem((void*)(dptr->d_name)
			,ft_strlen(dptr->d_name)));
	}
	(*sx)(env->st, &ft_strcmp_Mm);
	ERROR_CHECK((!closedir(dir)));
}

int ft_R(const char *name, t_list **st
, void (*sx)(t_list**, int (*ft_strcmp_Mm)(char*,char*))) //++
{
	/*
	 * 
	 * Error in t_list : "..zw"instead of ".." !!!!!!!!!!!!!
	 * New funcs: ft_strjoin_path (test ok) isHidden_pwd (test ok)
	 * Funcs need to be reviewed: swap strlen of t_list content
	 */
	DIR				*dir;
	struct dirent	*dptr;
	char			*n;
	t_list			*t;

	if (!isDir(name))
		return (0);
	t = NULL;
	ERROR_CHECK((dir = opendir(name)));
	ft_putstr(name); ft_putstr(":\n");
	while ((dptr = readdir(dir)) != NULL)
	{
		n = ft_strdup(dptr->d_name);
		//ft_putstr("\n\n---"); ft_putstr(n); ft_putstr("---\n\n");
		ft_queue_push(&t, ft_queue_init_elem(n, ft_strlen(n)));

		free(n);
	}
	(*sx)(&t, &ft_strcmp_Mm);
	display_st(t);
	while (!ft_queue_is_empty(t))
	{
		n = ft_strjoin_path((char*)name, ft_queue_pop(&t));
		if (isDir(n) && !isHidden_pwd(n))
		{
			ft_putstr("\n");
			ft_R(n, st, sx);
		}
		free(n);
		n = NULL;	
	}
	//ft_lstdel(&t);  //does not WORK !!!
	ERROR_CHECK(!(closedir(dir)));
	return (1);
}

/*t_list **ft_ls_a(const char *name
, void (*sx)(t_list**, int (*ft_strcmp_Mm)(char*,char*))) //++
{
	DIR *dir;
	struct dirent *dptr;
	char *n;
	t_list *tmp;

	if (!isDir(name))
		return (0);
	ERROR_CHECK((dir = opendir(name)));
	ft_putstr("<<<");ft_putstr(name); ft_putstr(">>>:\n");
	while ((dptr = readdir(dir)) != NULL)
	{
		n = ft_strdup(dptr->d_name);
		ft_queue_push(&tmp, ft_queue_init_elem(n, ft_strlen(n)));
		free(n);
	}
	(*sx)(&tmp, &ft_strcmp_Mm);
	//ft_lst_add_lst(st_tmp, &tmp);
	ERROR_CHECK(!(closedir(dir)));
	return (&tmp);
}

int ft_aR(const char *name, t_list **st
, void (*sx)(t_list**, int (*ft_strcmp_Mm)(char*,char*)))
{
	DIR *dir;
	struct dirent *dptr;
	char *n;

	if (!isDir(name))
		return (0);
	ERROR_CHECK((dir = opendir(name)));
}*/

void	parsing_name_aR(t_env *env
	, void (*sx)(t_list**, int (*ft_strcmp_Mm)(char*,char*))) //++
{
	ft_R(env->path, env->st, sx);
}

void	parsing_name(t_env *env
	, void (*f_parse)(t_env *env
		, void (*sx)(t_list**, int (*ft_strcmp_Mm)(char*,char*))))
{
	(*f_parse)(env, &sorting);
}
