/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lib_ls.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qtran <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/03 09:41:10 by qtran             #+#    #+#             */
/*   Updated: 2018/07/03 15:04:14 by qtran            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LIB_LS_H
# define FT_LIB_LS_H
# include <unistd.h>
# include <stdlib.h>
# include <dirent.h>
# include <sys/stat.h>
# include <sys/types.h>
# include <sys/xattr.h>
# include <pwd.h>
# include <uuid/uuid.h>
# include <time.h>
# include "libft/libft.h"
# define SP 20
typedef unsigned char u_char;

typedef struct	s_option
{
	u_char	l;
	u_char	R;
	u_char	a;
	u_char	r;
	u_char	t;
}				t_option;

void	ft_space(int n, int count);
void	ft_print_dir(const char *path);
int		ft_is_op_valid_assign(char *ch, t_option *op);
int		is_file_hidden(const char *path);
int		is_dir(const char *path);
int		ft_R(const char *path);
int		ft_R_level(int level_deep);

#endif
