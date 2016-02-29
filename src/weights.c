#include <lem_in.h>
#include <libft.h>

int			ft_room_cmp(void *d, size_t s, void *d2, size_t s2)
{
	(void)s;
	(void)s2;
	return (d - d2);
}

void	cut_links(t_room *room, t_map *map);
void	cut(t_map *map)
{
	size_t	i;
	t_room	*r;

	i = 0;
	while (i < map->rooms.size)
	{
		r = ft_list_get_at(&map->rooms, i);
		if (r != map->start && r != map->end)
			cut_links(r, map);
		++i;
	}
}

void		put_weights(t_map *map)
{
	t_list			queue;
	t_room			*curr;

	ft_list_init(&queue, NULL);
	map->end->weight = 0;
	ft_list_add_front(&queue, map->end, sizeof(t_room));
	while (queue.size >= 1)
	{
		curr = ft_list_remove_back(&queue);
		add_neighbours_to_queue(curr, &queue);
	}
	cut(map);
}

void		add_neighbours_to_queue(t_room *room, t_list *list)
{
	t_room	*it;
	size_t	i;

	i = 0;
	while (i < room->neighbours.size)
	{
		it = (t_room *)ft_list_get_at(&room->neighbours, i);
		if (it->weight == -1 && !ft_list_get(list, it, 0, &ft_room_cmp))
		{
			it->weight = room->weight + 1;
			ft_list_add_front(list, it, sizeof(t_room));
		}
		++i;
	}
}
