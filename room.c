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
	res->next = NULL;
	res->ant = 0;
	res->neighbours = NULL;
	return (res);
}

void	add_neighbour(t_room *room, t_room *ngh)
{
	t_room	*it;

	it = room->neighbours;
	if (!it)
	{
		room->neighbours = new_room(ft_strdup(ngh->name), 0, 0);
		return ;
	}
	while (it->next)
	{
		if (it == ngh)
			return ;
		it = it->next;
	}
	if (it != ngh)
		it->next = new_room(ngh->name, 0, 0);
}

t_room	*get_room(t_room *room_list, char *name)
{
	t_room *it;

	it = room_list;
	while (it && ft_strcmp(it->name, name) != 0)
		it = it->next;
	return (it);
}

int		link_neighbour(t_room *room_list, char *r, char *n)
{
	t_room	*r_room;
	t_room	*n_room;

	r_room = get_room(room_list, r);
	n_room = get_room(room_list, n);
	if (!r_room || !n_room || ft_strequ(r, n))
		return (-1);
	add_neighbour(r_room, n_room);
	return (0);
}
