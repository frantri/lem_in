/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftriquet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/23 18:00:43 by ftriquet          #+#    #+#             */
/*   Updated: 2016/02/27 06:32:41 by ftriquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

char	*ft_strrchr(
		const char *s,
		int c)
{
	size_t	i;

	i = 0;
	while (s[i])
		++i;
	while (i)
	{
		if (s[i] == (char)c)
			return ((char*)(s + i));
		--i;
	}
	if (s[i] == c)
		return ((char*)s);
	return (NULL);
}
