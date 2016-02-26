#include <lem_in.h>
#include <ft_printf.h>

static void	print_rooms(t_room *room)
{
	while (room)
	{
		ft_printf("%s ", room->name);
		room = room->next;
	}
}

static void	print_room(t_room *room)
{
	ft_printf("ROOM: %s (%3d,%3d): ", room->name, room->c_x, room->c_y);
	print_rooms(room->neighbours);
	ft_printf("\n");
}

void	print_map(t_map *map)
{
	t_room *it;

	ft_printf("ANTS: %d\n", map->ants);
	if (map->start)
		ft_printf("START ROOM: %s\n", map->start->name);
	else
		ft_printf("NO START ROOM\n");
	if (map->end)
		ft_printf("END ROOM: %s\n", map->end->name);
	else
		ft_printf("NO END ROOM\n");
	it = map->rooms;
	while (it)
	{
		print_room(it);
		it = it->next;
	}
}

void	reprint_map(t_map *map, t_line *l)
{
	if (l == NULL)
		return (reprint_map(map, map->lines));
	if (l->next)
		reprint_map(map, l->next);
	ft_printf("%s\n", l->data);
}
