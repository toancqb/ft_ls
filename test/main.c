#include "../includes/ft_ls_lib.h"
#include "../queue/ft_queue_lib.h"

int ft_test1(const char *name)
{
	DIR *dir;
	struct dirent *dptr;
	char *n;
	t_queue **qt;

	if (!isDir(name))
		return (0);
	qt = queue_init_root();
	ERROR_CHECK((dir = opendir(name)));
	ft_putstr(name); ft_putstr(":\n");
	while ((dptr = readdir(dir)) != NULL)
	{
		n = ft_strdup(dptr->d_name);
		queue_push(qt, queue_init_one(n, ft_strlen(n)));
		free(n);
	}
	queue_display(*qt);
	while (!queue_is_empty(*qt))
	{
		n = ft_strjoin_path((char*)name, queue_pop(qt));
		ft_putstr("__CHECK "); ft_putstr(n); ft_putstr("__\n");
		if (isDir(n) && !isHidden_pwd(n))
		{
			ft_putstr("\n");
			ft_putstr("__POP "); ft_putstr(n); ft_putstr("__\n");
			ft_test1((const char*)n);
		}
		free(n);
	}
	ERROR_CHECK(!(closedir(dir)));
	return (1);
}

void ft_test_queue()
{
	t_queue **qt;
	t_queue *q;

	qt = (t_queue**)malloc(sizeof(t_queue*));
	*qt = NULL;
	queue_push(qt, queue_init_one("a11111", 6));
	queue_push(qt, queue_init_one("k1155111", 8));
	queue_push(qt, queue_init_one("o1", 2));
	queue_push(qt, queue_init_one("p111", 4));
	queue_push(qt, queue_init_one("r1111", 5));

	ft_putnbr(queue_num_elem(*qt)); ft_putchar('\n');

	while (!queue_is_empty(*qt))
	{
		ft_putstr(queue_pop(qt)); ft_putchar('\n');
	}

}



int main(int argc, char *argv[])
{
	ft_test1(argv[1]);
	//ft_test_queue();
	return (0);
}
