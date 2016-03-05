/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_init.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftriquet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/27 02:35:57 by ftriquet          #+#    #+#             */
/*   Updated: 2016/02/27 06:54:49 by ftriquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <ft_list.h>
#include <stdlib.h>

static void		ft_dfl_del_func(
		void *data,
		size_t data_size)
{
	(void)data_size;
	(void)data;
}

void			ft_list_init(
		t_list *list,
		void (*del_func)(void *, size_t))
{
	ft_bzero(list, sizeof(t_list));
	if (del_func)
		list->del_func = del_func;
	else
		list->del_func = &ft_dfl_del_func;
}
