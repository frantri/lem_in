/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bstree_del.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftriquet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/27 17:51:40 by ftriquet          #+#    #+#             */
/*   Updated: 2015/11/27 18:16:15 by ftriquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void	ft_bstree_del(t_bstree **root)
{
	if (root && *root)
	{
		if ((*root)->content)
			free((*root)->content);
		ft_bstree_del(&((*root)->left));
		ft_bstree_del(&((*root)->right));
		free(*root);
		*root = NULL;
	}
}
