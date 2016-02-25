/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bstree_contains.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftriquet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/27 17:19:44 by ftriquet          #+#    #+#             */
/*   Updated: 2015/11/27 17:50:01 by ftriquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_bstree_contains(t_bstree *root, void *cont, size_t len,
		int (*cmp)(void*, size_t, void*, size_t))
{
	if (root)
	{
		if ((*cmp)((root)->content, (root)->content_size, cont, len) == 0)
			return (1);
		return (ft_bstree_contains(root->left, cont, len, cmp) ||
				ft_bstree_contains(root->right, cont, len, cmp));
	}
	return (0);
}
