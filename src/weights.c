#include <lem_in.h>
#include <libft.h>

int			ft_room_cmp(void *d, size_t s, void *d2, size_t s2)
{
	s = s2;
	return (ft_strcmp(((t_room *)d)->name, ((t_room *)d2)->name));
}

void		put_weights(t_map *map)
{
	t_list			queue;
	t_room			*curr;

	ft_list_init(&queue, NULL);
	map->start->weight = 0;
	ft_list_add_front(&queue, map->start, sizeof(t_room));
	while (queue.size >= 1)
	{
		curr = ft_list_remove_back(&queue);
		add_neighbours_to_queue(curr, &queue);
	}
}

void		add_neighbours_to_queue(t_room *room, t_list *list)
{
	t_room	*it;
	size_t	i;

	i = 0;
	while (i < room->neighbours.size)
	{
		it = (t_room *)ft_list_get_at(&room->neighbours, i);
		if (it->weight == -1)
		{
			it->weight = room->weight + 1;
			ft_list_add_front(list, it, sizeof(t_room));
		}
		++i;
	}
}
