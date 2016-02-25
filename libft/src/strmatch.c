/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strmatch.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftriquet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/20 19:38:46 by ftriquet          #+#    #+#             */
/*   Updated: 2016/01/20 20:32:19 by ftriquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		strmatch(char *s1, char *s2)
{
	if (*s1 == '\0' && *s2 == '\0')
		return (1);
	else if (*s1 == *s2)
		return (strmatch(s1 + 1, s2 + 1));
	else if (*s1 == '\0' && *s2 == '*')
		return (strmatch(s1, s2 + 1));
	else if (*s2 == '*')
		return (strmatch(s1 + 1, s2) || strmatch(s1, s2 + 1));
	else
		return (0);
}
