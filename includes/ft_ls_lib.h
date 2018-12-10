
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
	char *target;
	
} t_env;

void	parsing_name(const char *path, t_list **st,
	void (*f_parse)(const char*, t_list**));
void	parsing_name_simple(const char *path, t_list **st);
void	parsing_name_all(const char *path, t_list **st);
void	parsing_name_aR(const char *path, t_list **st);
void	display_simple(t_list **st);
int		ft_strcmp_Mm(char *str1, char *str2);
void	sorting(t_list **st, int (*f_sort)(char*,char*));

//
//
//	sort_ls(t_list **st, &sort)
//void display_ls(t_list **st, void (*f_pr_simple)(t_list**));
//	ft_queue_del(t_list **st);

#endif