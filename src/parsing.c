
#include "../includes/ft_ls_lib.h"

void	parsing_name_all(const char *path, t_list **st)
{
	DIR *dir;
	struct dirent *dptr;

	ERROR_CHECK((dir = opendir(path)));
	while((dptr = readdir(dir)) != NULL)
	{
		ft_queue_push(st, ft_queue_init_elem((void*)(dptr->d_name)
			,ft_strlen(dptr->d_name)));
	}
	ERROR_CHECK((!closedir(dir)));
}

void	parsing_name_simple(const char *path, t_list **st)
{
	DIR *dir;
	struct dirent *dptr;

	ERROR_CHECK((dir = opendir(path)));
	while((dptr = readdir(dir)) != NULL)
	{
		if ((dptr->d_name)[0] != '.')
		ft_queue_push(st, ft_queue_init_elem((void*)(dptr->d_name)
			,ft_strlen(dptr->d_name)));
	}
	ERROR_CHECK((!closedir(dir)));
}

void	parsing_name_aR(const char *path, t_list **st)
{
	DIR *dir;
	struct dirent *dptr;

	/*ERROR_CHECK((dir = opendir(path)));
	ft_queue_push(st, ft_queue_init_elem(path, ft_strlen(path)));
	while(!(ft_queue_is_empty(*st)))
	{

	}*/
}

void	parsing_name(const char *path, t_list **st
	, void (*f_parse)(const char*,t_list**))
{
	(*f_parse)(path, st);
}