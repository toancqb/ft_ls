
#include "../includes/ft_ls_lib.h"

//parsing_name


void	ft_ls(const char *path)
{
	t_list	**st;

	st = (t_list**)malloc(sizeof(t_list*));
	parsing_name(path, st, &parsing_name_simple);
	sorting(st, &ft_strcmp_Mm);
	display_simple(st);
	//ft_queue_del(st);
}

/*void	ls_recursive(const char *path)
{
	t_list	**st;

	ft_queue_push(st, ft_queue_init_elem((void*)path, 0));

}*/
