#include "../includes/ft_ls_lib.h"

void	ft_test()
{
	t_list *tmp;
	char *n;

	tmp = NULL;
	ft_queue_push(&tmp, ft_queue_init_elem("111111", 6));
	ft_queue_push(&tmp, ft_queue_init_elem("222222", 6));
	ft_queue_push(&tmp, ft_queue_init_elem("333333", 6));
	ft_queue_push(&tmp, ft_queue_init_elem("444444", 6));
	ft_queue_push(&tmp, ft_queue_init_elem("555555", 6));

	while (!ft_queue_is_empty(tmp))
	{
		n = ft_queue_pop(&tmp);
		ft_putstr(n);
		ft_putchar('\n');
		free(n);
	}
}

void	ft_test1()
{
	t_list *tmp;

	tmp = (t_list*)malloc(sizeof(t_list));
	char *n;

	ft_queue_push(&tmp, ft_queue_init_elem("111111", 6));
	ft_queue_push(&tmp, ft_queue_init_elem("222222", 6));
	ft_queue_push(&tmp, ft_queue_init_elem("333333", 6));
	ft_queue_push(&tmp, ft_queue_init_elem("444444", 6));
	ft_queue_push(&tmp, ft_queue_init_elem("555555", 6));

	while (!ft_queue_is_empty(tmp))
	{
		n = ft_queue_pop(&tmp);
		ft_putstr(n);
		ft_putchar('\n');
		free(n);
	}
}

int main()
{
	ft_test();

	return (0);
}
