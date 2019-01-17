#include "../includes/ft_ls_lib.h"


void	init_opt(t_opt *op)
{
	op->a = 0;
	op->R = 0;
	op->l = 0;
	op->r = 0;
	op->t = 0;
	//op->flag = 0;
}

void	assign_opt_char(t_opt *op, char c)
{
	if (c == 'a')
		op->a = 4;
	else if (c == 'R')
		op->R = 2;
	else if (c == 'l')
		op->l = 1;
	else if (c == 'r')
		op->r = 8;
	else
		op->t = 16;
}

int	is_opt_or_path(char *str, t_opt *op)
{
	int i;

	i = 0;
	if (str[i] != '-')
		return (2);
	i++;
	if (str[i] == '\0')
		return (0);
	while (str[i] != '\0')
	{
		if (str[i] == 'a' || str[i] == 'R' || str[i] == 'l'
		 || str[i] == 'r' || str[i] == 't')
			assign_opt_char(op, str[i]);
		else
			return (0);
		i++;
	}
	return (op->l + op->R + op->a + op->r + op->t);
}

void	ft_assign_opt_path(int argc, char **argv, t_opt *op, t_queue **target)
{
	int		i;
	int		n;
	char   	*tmp;

	n = 0;
	if (argc < 2)
		ERROR_CHECK(0);
	i = 1;
	while (i < argc)
	{
		n = is_opt_or_path(argv[i], op);
		if (n == 0)
			ERROR_CHECK(0);
		if (n == 2)
		{
			tmp = ft_strdup(argv[i]);
			queue_push(target, queue_init_one(tmp, ft_strlen(tmp)));
		}
		i++;
	}
			
	if (op->r == 8 && op->t == 16)
	{
		sorting(target, &ft_strcmp_modification_time);
		sorting(target, &ft_strcmp_reverse);
	}
	else if (op->t == 16)
		sorting(target, &ft_strcmp_modification_time);
	else if (op->r == 8)
		sorting(target, &ft_strcmp_reverse);
	else
		sorting(target, &ft_strcmp_alphabet);

}
/*nt main(int argc, char *argv[])
{
	t_opt *op;
	t_queue **t;

	t = queue_init_root();
	op = (t_opt*)malloc(sizeof(t_opt));
	init_opt(op);
	ft_assign_opt_path(argc, argv, op, t);
	if (*t == NULL)
		queue_push(t, queue_init_one(".", 2));
	printf("a-%c  R-%c  l-%c  r-%c  t-%c\n"
		, op->a, op->R, op->l, op->r, op->t);
	ft_putstr(queue_pop(t)); ft_putchar('\n');

	return (0);
}
*/