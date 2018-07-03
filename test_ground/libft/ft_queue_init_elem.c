/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_queue_init_elem.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qtran <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/02 22:58:28 by qtran             #+#    #+#             */
/*   Updated: 2018/07/02 23:01:10 by qtran            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_queue_init_elem(void const *content, size_t content_size)
{
	return (ft_stack_init_elem(content, content_size));
}
