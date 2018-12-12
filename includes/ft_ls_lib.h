
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
# include "../libft/libft.h"
# define ERROR_CHECK(x) if (!x) { perror("Can't process"); exit(0);}

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
	t_list **st;
	//u_char isf;
	//

	//	
} t_env;

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