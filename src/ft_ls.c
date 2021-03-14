/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qtran <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/18 20:15:11 by qtran             #+#    #+#             */
/*   Updated: 2018/12/18 20:15:46 by qtran            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls_lib.h"

# define OPT_l 1 << 1
# define OPT_R 1 << 2
# define OPT_a 1 << 3
# define OPT_r 1 << 4
# define OPT_t 1 << 5


/**
 * Parse option en utilisant binaire 
 * OPT_l = 10     = 000010
 * OPT_R = 100    = 000100
 * OPT_a = 1000   = 001000
 * OPT_r = 10000  = 010000
 * OPT_t = 100000 = 100000
 * 
 * option already have option -c: option = 01000
 * if we have option -o: option = option | OPT_O
 * then option := 01100
 * */
int parse_option(int *opt, char *arg)
{
    if(arg && strlen(arg) >= 2 && arg[0] == '-') 
    {
        while(*arg != '\0') 
        {
            if(*arg == 'l')
                *opt |= OPT_l;
            else if(*arg == 'R')
                *opt |= OPT_R;
            else if(*arg == 'a')
                *opt |= OPT_a;
            else if(*arg == 'r')
                *opt |= OPT_r;
            else if(*arg == 't')
                *opt |= OPT_t;
            arg++;
        }
        return 1;
    }
    return 0;
}

void	ft_process(t_env *env)
{
	parsing_name(env, &parsing_name_simple);
	//display_aR(env);	
	ft_queue_clr(env->st);
}

//parsing_name

void	ft_ls(int argc, char **argv)
{
	int		i;
	t_env	*env;

	env = (t_env*)malloc(sizeof(t_env));
	env->st = (t_list**)malloc(sizeof(t_list*));
	env->option = 0;

	i = 1;
	while(i < argc)
	{
		if(!parse_option(&(env->option), argv[i]))
		{
			env->path = (const char *)argv[i];
			ft_process(env);
		}
		i++;
	}

	ft_lstdel(env->st);
	free(env);
}


