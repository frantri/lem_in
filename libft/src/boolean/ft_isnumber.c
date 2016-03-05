/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isnumber.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftriquet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/27 05:50:36 by ftriquet          #+#    #+#             */
/*   Updated: 2016/02/27 05:52:49 by ftriquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <stdlib.h>

int			ft_isnumber(const char *s)
{
	int		i;

	i = 0;
	if (s[0] == '-' || s[0] == '+')
		++i;
	while (s[i])
	{
		if (!ft_isdigit(s[i]))
			return (0);
		++i;
	}
	return (i);
}
