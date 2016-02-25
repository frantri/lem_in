/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftriquet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/23 08:43:32 by ftriquet          #+#    #+#             */
/*   Updated: 2016/02/25 08:28:31 by ftriquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>

int			nbr_len(intmax_t nb, int base)
{
	if (nb < 0)
		return (1 + nbr_len_u(-nb, base));
	else
		return (nbr_len_u(nb, base));
}

int			nbr_len_u(uintmax_t n, int base)
{
	int		i;

	i = 1;
	while (n >= (size_t)base)
	{
		++i;
		n /= base;
	}
	return (i);
}

intmax_t	ft_atoi(const char *str)
{
	size_t		i;
	int			sign;
	intmax_t	result;

	result = 0;
	i = 0;
	if (str[i] == '-' || str[i] == '+')
	{
		sign = -1 * (str[i] == '-') + 1 * (str[i] == '+');
		++i;
	}
	else
		sign = 1;
	while (str[i] >= '0' && str[i] <= '9')
	{
		result *= 10;
		result += str[i] - '0';
		++i;
	}
	return (sign * result);
}
