#include <lem_in.h>
#include <stdlib.h>
#include <libft.h>

t_room	*new_room(char *name, int x, int y)
{
	t_room	*res;

	if (!(res = (t_room *)malloc(sizeof(*res))))
		return (NULL);
	res->c_x = x;
	res->c_y = y;
	res->name = ft_strdup(name);
	res->ant = 0;
	res->ants = 0;
	res->used = 0;
	ft_list_init(&res->neighbours, NULL);
	res->weight = -1;
	return (res);
}

void	add_neighbour(t_room *room, t_room *ngh)
{
	ft_list_add_back(&room->neighbours, ngh, sizeof(t_room));
}

int		room_cmp(void *d2, size_t s, void *d, size_t s2)
{
	(void)s;
	(void)s2;
	return (ft_strcmp(((t_room *)d)->name, (char *)d2));
}

t_room	*get_room(t_map *map, char *name)
{
	return (ft_list_get(&map->rooms, name, 0, &room_cmp));
}

int		link_neighbour(t_map *map, char *r, char *n)
{
	t_room	*r_room;
	t_room	*n_room;

	r_room = get_room(map, r);
	n_room = get_room(map, n);
	if (!r_room || !n_room || ft_strequ(r, n))
		return (-1);
	add_neighbour(r_room, n_room);
	return (0);
}
