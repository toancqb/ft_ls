
#include "../includes/ft_ls_lib.h"
#include <stdio.h>
int isHidden(const char *path)
{
	int len = ft_strlen(path);

	len--;
	while (len >= 0 && path[len] != '/')
	{
		if (path[len] == '.' && (len == 0 || (len > 0 && path[len - 1] == '/')))
			return (1);
		len--;
	}
	return (0);
}

int isDir(const char *path)
{
	struct stat statbuf;

	if (stat(path, &statbuf) != 0 /*|| isHidden(path)*/)
		return (0);
	return S_ISDIR(statbuf.st_mode);
}

int	isHidden_pwd(const char *path)
{
	return (!ft_strcmp(path, ".") || !ft_strcmp(path, ".."));
}

int	main(int argc, char *argv[])
{

	ft_ls((const char*)argv[1]);

	//printf("%d  %d \n", isHidden_pwd("libft"), isHidden_pwd(".."));

	return (0);
}