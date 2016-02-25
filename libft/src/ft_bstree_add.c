/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bstree_add.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftriquet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/27 16:20:37 by ftriquet          #+#    #+#             */
/*   Updated: 2016/02/23 00:45:04 by ftriquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_bstree_add(t_bstree **root, t_bstree *node,
		int (*cmp)(t_bstree*, t_bstree*))
{
	t_bstree	*current;

	if (root)
	{
		current = *root;
		if (current)
		{
			if ((*cmp)(current, node) <= 0)
				return (ft_bstree_add(&(current->right), node, cmp));
			else
				return (ft_bstree_add(&(current->left), node, cmp));
		}
		else
		{
			*root = node;
			return (0);
		}
	}
	return (1);
}
