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

void	ft_ls_all(const char *path)
{
	t_env	*env;

	env = (t_env*)malloc(sizeof(t_env));
	env->path = path;
	env->qt = queue_init_root();

	parsing_name(env, &parsing_name_all);
	queue_display(*(env->qt));

	queue_clr_all(env->qt);
	free(env);
}

void	ft_ls_simple(const char *path)
{
	t_env	*env;

	env = (t_env*)malloc(sizeof(t_env));
	env->path = path;
	env->qt = queue_init_root();

	parsing_name(env, &parsing_name_simple);
	queue_display(*(env->qt));

	queue_clr_all(env->qt);
	free(env);
}

void	ft_ls_control(int argc, char *argv[])
{
	t_opt *op;
	t_queue **target;
	int n;

	n = 0;
	target = queue_init_root();
	op = (t_opt*)malloc(sizeof(t_opt));
	init_opt(op);
	n = ft_assign_opt_path(argc, argv, op, target);
	
}
