
#include "../includes/ft_ls_lib.h"

void	display_simple(t_list **st)
{
	while(*st != NULL)
	{
		//if ((*st)->content_size == 0)
		//	continue ;
		ft_putstr((*st)->content);
		ft_putstr("  ");
		*st = (*st)->next;
	}
	ft_putchar('\n');
}