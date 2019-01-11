
#include "../includes/ft_ls_lib.h"

void	ft_lst_add_lst(t_list **st, t_list **tmp)
{
	t_list *st_tmp;

	if (st && tmp)
	{
		st_tmp = *st;
		while (st_tmp->next != NULL)
		{
			st_tmp = st_tmp->next;
		}
		st_tmp->next = *tmp;
	}
}

void	error_fix_tmp(t_list **t)
{
	t_list *tmp;
	char *str;

	if (t)
	{
		tmp = *t;
		while (tmp != NULL)
		{
			str = tmp->content;
			str[tmp->content_size] = '\0';
			tmp = tmp->next;
		}
	}
}