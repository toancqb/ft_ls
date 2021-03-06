/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls_lib.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qtran <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/18 20:16:03 by qtran             #+#    #+#             */
/*   Updated: 2018/12/18 20:16:09 by qtran            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LS_LIB_H
# define FT_LS_LIB_H
# include <unistd.h>
# include <stdlib.h>
# include <dirent.h>
# include <sys/stat.h>
# include <sys/types.h>
# include <sys/xattr.h>
# include <pwd.h>
//# include <uuid/uuid.h>
# include <time.h>
# include <stdio.h>
# include "../libft/libft.h"
# define ERROR_CHECK(x) if (!x) { perror("Can't process"); exit(0);}
# define OPT_l 1 << 1
# define OPT_R 1 << 2
# define OPT_a 1 << 3
# define OPT_r 1 << 4
# define OPT_t 1 << 5

typedef unsigned char u_char;

typedef struct s_env
{
	const char *path;
	t_list **st;
	int option;
} t_env;

void	ft_ls(int argc, char **argv);

void	parsing_name(t_env *env, void (*f_parse)(t_env*
		, void (*sx)(t_list**, int (*ft_strcmp_Mm)(char*,char*))));

void	parsing_name_simple(t_env *env
	, void (*sx)(t_list**, int (*ft_strcmp_Mm)(char*,char*)));

void	parsing_name_all(t_env *env
	, void (*sx)(t_list**, int (*ft_strcmp_Mm)(char*,char*)));

void	parsing_name_aR(t_env *env
	, void (*sx)(t_list**, int (*ft_strcmp_Mm)(char*,char*)));

void	display_st(t_list *st);
void	display_simple(t_env *env);
void	display_aR(t_env *env);
int		ft_strcmp_Mm(char *str1, char *str2);
void	sorting(t_list **st, int (*f_sort)(char*,char*));
int isDir(const char *path);
int isHidden(const char *path);
int	isHidden_pwd(const char *path);

//
//
//	sort_ls(t_list **st, &sort)
//void display_ls(t_list **st, void (*f_pr_simple)(t_list**));
//	ft_queue_del(t_list **st);

#endif
