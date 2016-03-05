/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftriquet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/02 20:31:46 by ftriquet          #+#    #+#             */
/*   Updated: 2016/03/05 01:54:34 by ftriquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <lem_in.h>
#include <ft_printf.h>

void	print_room_name(void *room, size_t s)
{
	(void)s;
	ft_printf("%s ", ((t_room *)room)->name);
}

void	print_room(void *d, size_t s)
{
	t_room		*room;

	room = (t_room *)d;
	(void)s;
	ft_printf("ROOM: %s ants:%d , ant: %d {%d}, (%-3d,%-3d): ",
			room->name, room->ants, room->ant,
			room->weight, room->c_x, room->c_y);
	ft_list_iter(&room->neighbours, print_room_name);
	ft_printf("\n");
}

void	print_map(t_map *map)
{
	ft_printf("ANTS: %d\n", map->ants);
	if (map->start)
		ft_printf("START ROOM: %s\n", map->start->name);
	else
		ft_printf("NO START ROOM\n");
	if (map->end)
		ft_printf("END ROOM: %s\n", map->end->name);
	else
		ft_printf("NO END ROOM\n");
	ft_list_iter(&map->rooms, &print_room);
}

void	reprint_map(t_map *map, t_line *l)
{
	if (l == NULL)
		return (reprint_map(map, map->lines));
	if (l->next)
		reprint_map(map, l->next);
	ft_printf("%s\n", l->data);
}
