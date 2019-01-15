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
#include <errno.h> //
//# include <uuid/uuid.h>
# include <time.h>
# include <stdio.h> //
# include "../libft/libft.h"
# include "../queue/ft_queue_lib.h"
# define ERROR_CHECK(x) if (!x) { perror("Can't process"); exit(0);}
# define PATH_LEN_MAX 1024

typedef unsigned char u_char;

typedef struct s_opt
{
	u_char	l;
	u_char	R;
	u_char	a;
	u_char	r;
	u_char	t;
} t_opt;

typedef struct s_env
{
	const char *path;
	t_queue **qt;
	//
} t_env;

void	ft_ls(const char *path);

void	parsing_name(t_env *env, void (*f_parse)(t_env*
		, void (*sx)(t_queue**, int (*ft_strcmp_Mm)(char*,char*))));

void	parsing_name_simple(t_env *env
	, void (*sx)(t_queue**, int (*ft_strcmp_Mm)(char*,char*)));

void	parsing_name_all(t_env *env
	, void (*sx)(t_queue**, int (*ft_strcmp_Mm)(char*,char*)));

void	parsing_name_aR(t_env *env
	, void (*sx)(t_queue**, int (*ft_strcmp_Mm)(char*,char*)));

void	parsing_name_R(t_env *env
		, void (*sx)(t_queue**, int (*ft_strcmp_Mm)(char*,char*)));

void	display_st(t_queue *st);
void	display_simple(t_env *env);
void	display_aR(t_env *env);

int		ft_strcmp_alphabet(char *str1, char *str2);
int		ft_strcmp_reverse(char *s1, char *s2);
void	sorting(t_queue **st, int (*f_sort)(char*,char*));

int isDir(const char *path);
int isDir2(const char *path);
int isHidden(const char *path);
int	isHidden_pwd(const char *path);
int	isHidden_sp(const char *path);

int ft_strjoin_npath(char path[], int len_max, char *name, char *pop);

void	ft_putnstr(char *str, int len);

#endif
