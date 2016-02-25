/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_realloc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftriquet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/30 15:35:34 by ftriquet          #+#    #+#             */
/*   Updated: 2015/12/30 15:44:42 by ftriquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

int		ft_realloc(void **mem1, size_t size1, void *mem2, size_t size2)
{
	void	*res;

	if (!*mem1 || !mem2)
		return (-1);
	if (!(res = malloc(size1 + size2)))
		return (-2);
	ft_memmove(res, *mem1, size1);
	ft_memmove(res + size1, mem2, size2);
	free(*mem1);
	*mem1 = res;
	return (1);
}
