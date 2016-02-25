/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bstree_iter.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftriquet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/27 17:55:49 by ftriquet          #+#    #+#             */
/*   Updated: 2015/11/27 19:45:52 by ftriquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bstree_iter(t_bstree *root, void (*f)(void*, size_t))
{
	if (root)
	{
		(*f)(root->content, root->content_size);
		ft_bstree_iter(root->left, f);
		ft_bstree_iter(root->right, f);
	}
}
