#include "../includes/ft_ls_lib.h"
#include "../queue/ft_queue_lib.h"
#include <errno.h>
#include <string.h>
#define PATH_LEN_MAX 1024

void newln(void)
{
	//ft_putstr("\n__POP__ "); ft_putstr(m);
	ft_putchar('\n');
}

int ft_test1(const char *name)
{/*
	*
	* CHECK PERMISSION AND IGNORE
	*	PROBLEM IS FT_STRJOIN_PATH <-------- REPLACED WITH SNPRINTF
	*/
	DIR *dir;
	struct dirent *dptr;
	const char *n;
	char *m;
	char path[PATH_LEN_MAX];
	t_queue **qt;

	qt = queue_init_root();
	ERROR_CHECK((dir = opendir(name)));
	ft_putstr(name); ft_putstr(":\n");
	while ((dptr = readdir(dir)) != NULL)
	{
		n = dptr->d_name;
		queue_push(qt, queue_init_one((char*)n, ft_strlen((char*)n)));
	}
	queue_display(*qt);
	while (!queue_is_empty(*qt))
	{
		m = queue_pop(qt);
		//n = ft_strjoin_path((char*)name, m);
		snprintf (path, PATH_LEN_MAX, "%s/%s", name, m);
		if (isDir(path) && !isHidden_pwd(path))
		{
			ft_test1(path);
		}
	}
	queue_clr_all(qt);
	ERROR_CHECK(!(closedir(dir)));
	return (1);
}

void ft_test2(const char *name)
{/*
	* I try to make this func as simple as possible
	* SOMEHOW it doesnt work well with strings ???
	*/
	DIR *dir;
	struct dirent *dptr;
	const char *n;
	char path[1024];
	//char *m;

	ERROR_CHECK((dir = opendir(name)));

	//ft_putstr(name); ft_putstr(":\n");
	printf("%s:\n", name);
	while (1)
	{
		dptr = readdir(dir);
		if (!dptr)
			break ;
		n = (const char*)dptr->d_name;
		//ft_putstr(n); ft_putstr("  ");
		printf("%s  ", n);
		//m = ft_strjoin_path((char*)name, (char*)n);
		if ((dptr->d_type & DT_DIR))
		{
		if (strcmp (n, "..") != 0 && strcmp (n, ".") != 0)
				{
					//snprintf (path, 1024,"%s/%s", name, n);

			ft_test2(path);
		}
	}
	}
	//printf("\n");
	//ERROR_CHECK(!(closedir(dir)));
	if (closedir (dir)) {
			fprintf (stderr, "Could not close\n");
			exit (EXIT_FAILURE);
	}
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
