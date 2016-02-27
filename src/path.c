#include <lem_in.h>
#include <stdlib.h>
#include <libft.h>
//void	remove_link_from_neighbours(t_map *map, t_room *room, int w)
//{
//	t_room	*it;
//
//	ft_printf("Removeing neighbours of %s\n", room->name);
//	it = room->neighbours;
//	if (room->weight == -1)
//		room->weight = w;
//	else
//		room->weight = room->weight > w ? w : room->weight;
//	while (it)
//	{
//		remove_link(get_room(map->rooms, it->name), room->name);
//		it = it->next;
//	}
//	it = room->neighbours;
//	while (it)
//	{
//		remove_link_from_neighbours(map, get_room(map->rooms, it->name), w + 1);
//		it = it->next;
//	}
//}
//
//void	remove_link(t_room *room, char *name)
//{
//	t_room	*it;
//
//	it = room->neighbours;
//	if (!it)
//		return ;
//	if (ft_strequ(it->name, name))
//	{
//		room->neighbours = room->neighbours->next;
//		free(it);
//		return ;
//	}
//	while (it->next && !ft_strequ(it->next->name, name))
//		it = it->next;
//	if (it->next)
//	{
//		it->next = it->next->next;
//		free(it->next);
//		it->next = NULL;
//	}
//}
//
//int		is_neighbour(t_room *room, char *ngh_name)
//{
//	t_room	*it;
//
//	it = room->neighbours;
//	while (it)
//	{
//		if (ft_strequ(it->name, ngh_name))
//			return (1);
//		it = it->next;
//	}
//	return (0);
//}
//
//int		is_multiple_neighbour(t_map *map, char *name)
//{
//	t_room	*it;
//	int		res;
//
//	it = map->rooms;
//	res = 0;
//	while (it)
//	{
//		if (it != map->start && it != map->end)
//			res += is_neighbour(it, name);
//		it = it->next;
//	}
//	return (res);
//}
//
//void		remove_multiple_neighbours(t_map *map)
//{
//	t_room	*it;
//
//	it = map->rooms;
//	while (it)
//	{
//		if (it != map->start && it != map->end && is_multiple_neighbour(map, it->name))
//			remove_neighbour_from_all(map, it->name);
//		it = it->next;
//	}
//}
//
//void		remove_neighbour_from_all(t_map *map, char *name)
//{
//	t_room *it;
//
//	it = map->rooms;
//
//	while (it)
//	{
//		it->weight = -1;
//		if (it != map->start && it != map->end)
//			remove_link(it, name);
//		it = it->next;
//	}
//}
