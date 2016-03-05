/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clear_start.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftriquet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/05 02:23:49 by ftriquet          #+#    #+#             */
/*   Updated: 2016/03/05 02:39:44 by ftriquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <lem_in.h>
#include <libft.h>

void	reset_visits(t_map *map)
{
	size_t	i;
	t_room	*r;

	i = 0;
	while (i < map->rooms.size)
	{
		r = ft_list_get_at(&map->rooms, i);
		r->visited = 0;
		++i;
	}
}

int		search_path(t_room *room, t_map *map)
{
	size_t	i;
	t_room	*r;

	i = 0;
	if (room == map->end)
		return (1);
	room->visited = 1;
	while (i < room->neighbours.size)
	{
		r = ft_list_get_at(&room->neighbours, i);
		if (!r->visited && search_path(r, map) == 1)
			return (1);
		++i;
	}
	return (0);
}

void	clean_start(t_map *map)
{
	size_t	i;
	t_room	*r;

	i = 0;
	while (i < map->start->neighbours.size)
	{
		r = ft_list_get_at(&map->start->neighbours, i);
		if (!r->visited && !search_path(r, map) == 1)
		{
			ft_list_remove(&map->start->neighbours, r, 0, &ft_room_cmp);
			--i;
		}
		reset_visits(map);
		++i;
	}
}
