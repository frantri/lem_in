/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ants.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftriquet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/02 20:31:31 by ftriquet          #+#    #+#             */
/*   Updated: 2016/03/05 15:45:33 by ftriquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <lem_in.h>
#include <libft.h>

void	make_move(t_room *room, t_map *map)
{
	t_room	*dest;
	size_t	i;

	if (room == map->end)
		return ;
	i = 0;
	while (i < room->neighbours.size)
	{
		dest = ft_list_get_at(&room->neighbours, i);
		make_move(dest, map);
		if (room == map->start && room->ants && ++dest->ants)
		{
			dest->ant = (map->ants - --room->ants);
			ft_printf("L%d-%s ", dest->ant, dest->name);
		}
		else if (dest && room->ants && ++dest->ants)
		{
			room->ants = 0;
			dest->ant = room->ant;
			room->ant = 0;
			ft_printf("L%d-%s ", dest->ant, dest->name);
		}
		i++;
	}
}

void	play(t_map *map)
{
	map->start->ants = map->ants;
	while (map->end->ants != map->ants)
	{
		make_move(map->start, map);
		ft_printf("\n");
	}
}
