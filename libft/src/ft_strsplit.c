/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftriquet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/25 10:58:53 by ftriquet          #+#    #+#             */
/*   Updated: 2015/12/04 17:11:21 by ftriquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"
#include <string.h>

static int	ft_count_words(const char *s, char c)
{
	size_t			i;
	unsigned int	count;

	i = 0;
	count = 0;
	while (s[i])
	{
		if (s[i] != '\0' && s[i] == c && s[i + 1] != c)
			count++;
		else if (s[i] != '\0' && i == 0 && s[i] != c)
			count++;
		++i;
	}
	if (i > 0 && s[i - 1] == c)
		count--;
	return (count);
}

char		**ft_strsplit(const char *s, char c)
{
	unsigned int	nb_words;
	char			**tab;
	unsigned int	i;

	i = 0;
	if (s == NULL)
		return (NULL);
	nb_words = ft_count_words(s, c);
	tab = (char**)malloc(sizeof(*tab) * (nb_words + 1));
	if (!tab)
		return (tab);
	while (i < nb_words)
	{
		tab[i] = ft_copy_word(s, c, i + 1);
		i++;
	}
	tab[i] = NULL;
	return (tab);
}
