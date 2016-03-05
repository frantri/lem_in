/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftriquet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/23 15:32:45 by ftriquet          #+#    #+#             */
/*   Updated: 2016/02/27 06:16:38 by ftriquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void	*ft_memcpy(
		void *dst,
		const void *src,
		size_t n)
{
	while (n > 0)
	{
		--n;
		((char*)dst)[n] = ((char*)src)[n];
	}
	return (dst);
}
