#include <lem_in.h>
#include <libft.h>

t_parsing_err	check_dbl(t_map *map, t_room *newroom)
{
	t_room	*it;

	it = map->rooms;
	while (it)
	{
		if (ft_strcmp(it->name, newroom->next) == 0)
			return (SAME_NAME);
		else if (newroom->c_x == it->c_x && newroom->c_y == it->c_y)
			return (SAME_COORDS);
		it = it->next;
	}
	return (OK);
}
