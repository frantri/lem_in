/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bstree_new.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftriquet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/27 15:55:54 by ftriquet          #+#    #+#             */
/*   Updated: 2015/11/27 16:18:32 by ftriquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "libft.h"
#include <stdlib.h>

static void		ft_set_node(t_bstree *node)
{
	if (node)
	{
		node->left = NULL;
		node->right = NULL;
	}
}

t_bstree		*ft_bstree_new(void *content, size_t content_size)
{
	t_bstree	*new;

	if ((new = malloc(sizeof(*new))))
	{
		if (content)
		{
			if ((new->content = malloc(content_size)))
			{
				ft_memcpy(new->content, content, content_size);
				new->content_size = content_size;
			}
			else
			{
				free(new);
				return (NULL);
			}
		}
		else
		{
			new->content = NULL;
			new->content_size = 0;
		}
		ft_set_node(new);
	}
	return (new);
}
