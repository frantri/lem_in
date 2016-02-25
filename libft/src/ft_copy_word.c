/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_copy_words.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftriquet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/04 17:10:57 by ftriquet          #+#    #+#             */
/*   Updated: 2015/12/04 17:11:15 by ftriquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_copy_word(const char *s, char sep, unsigned int n)
{
	unsigned int	i;
	unsigned int	len;
	char			*res;

	i = 0;
	while (n != 0)
	{
		if (s[i] != sep)
		{
			len = 0;
			n--;
			while (s[i + len] && s[i + len] != sep)
				len++;
			if (n != 0)
				i += len;
		}
		else
			i++;
	}
	if (len == 0)
		len++;
	res = ft_strsub(s, i, len);
	return (res);
}
