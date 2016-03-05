/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_get.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftriquet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/27 10:41:13 by ftriquet          #+#    #+#             */
/*   Updated: 2016/03/02 20:37:10 by ftriquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

void			*ft_list_get_back(t_list *list)
{
	if (list->size == 0)
		return (NULL);
	return (list->last->data);
}

void			*ft_list_get_front(t_list *list)
{
	if (list->size == 0)
		return (NULL);
	return (list->first->data);
}

void			*ft_list_get(
		t_list *list,
		void *data,
		size_t data_size,
		int (*cmp)(void *, size_t, void *, size_t))
{
	t_list_cell	*it;

	it = list->first;
	if (list->size == 0)
		return (NULL);
	while (it)
	{
		if ((*cmp)(data, data_size, it->data, it->data_size) == 0)
			return (it->data);
		it = it->next;
	}
	return (NULL);
}

void			*ft_list_get_at(
		t_list *list,
		size_t pos)
{
	size_t		i;
	t_list_cell	*cursor;

	if (pos >= list->size)
		return (NULL);
	cursor = list->first;
	i = 0;
	while (i < pos)
	{
		++i;
		cursor = cursor->next;
	}
	if (cursor)
		return (cursor->data);
	return (NULL);
}
