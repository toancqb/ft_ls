
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