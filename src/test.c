
#include "../includes/ft_ls_lib.h"

//parsing_name


void	ft_ls(const char *path)
{
	//t_list	**st;
	t_env	*env;

	env = (t_env*)malloc(sizeof(t_env));
	env->path = path;
	env->st = (t_list**)malloc(sizeof(t_list*));
	parsing_name(env, &parsing_name_aR);
	//display_aR(env);

	ft_lstdel(env->st);
	free(env);
}

/*void	ls_recursive(const char *path)
{
	t_list	**st;

	ft_queue_push(st, ft_queue_init_elem((void*)path, 0));

}*/
