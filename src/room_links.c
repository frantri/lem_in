/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   room_links.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftriquet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/02 20:31:47 by ftriquet          #+#    #+#             */
/*   Updated: 2016/03/02 20:31:47 by ftriquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <lem_in.h>
#include <libft.h>

t_parsing_msg	handle_link_line(char **line, t_map *map)
{
	char	**split;

	split = ft_strsplit(*line, '-');
	if (ft_tabsize((void **)split) != 2)
	{
		ft_freetab(split);
		return (INVALID_LINE);
	}
	if (link_neighbour(map, split[0], split[1]) == -1)
		return (INVALID_LINE);
	if (link_neighbour(map, split[1], split[0]) == -1)
		return (INVALID_LINE);
	return (OK);
}

int				room_id(void *data, size_t s, void *data2, size_t s2)
{
	(void)s;
	(void)s2;
	return (data == data2);
}

void			break_link(t_room *room, t_room *target)
{
	ft_list_remove(&room->neighbours, target, 0, &ft_room_cmp);
}
