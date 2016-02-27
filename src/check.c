#include <lem_in.h>
#include <ft_printf.h>
#include <libft.h>

#include <stdio.h>
t_parsing_msg	check_dbl(t_map *map, t_room *newroom)
{
	t_room		*room;
	size_t		i;

	i = 0;
	while (i < map->rooms.size)
	{
		room = (t_room *)ft_list_get_at(&map->rooms, i);
		if (ft_strcmp(room->name, newroom->name) == 0)
			return (SAME_NAME);
		else if (newroom->c_x == room->c_x && newroom->c_y == room->c_y)
			return (SAME_COORDS);
		++i;
	}
	return (OK);
}

int		is_int(char *arg)
{
	int			i;
	intmax_t	v;

	i = 0;
	if (arg[0] == '-')
		i++;
	while (arg[i])
	{
		if (!ft_isdigit(arg[i]))
			return (0);
		i++;
	}
	v = ft_atoi(arg);
	if (v != (int)v)
		return (0);
	return (1);
}

t_room		*is_valid_room(t_map *map, char *line)
{
	char			**split;
	t_room			*new;
	t_parsing_msg	msg;

	if (line[0] == '#')
		return (NULL);
	split = ft_strsplit(line, ' ');
	if (ft_tabsize((void **)split) != 3 || !is_int(split[1]) ||
			!is_int(split[2]))
	{
		ft_freetab(split);
		return (NULL);
	}
	new = new_room(split[0], ft_atoi(split[1]), ft_atoi(split[2]));
	ft_freetab(split);
	msg = check_dbl(map, new);
	if (msg == OK)
		return (new);
	if (msg == SAME_NAME)
		exit_error("duplicate room name");
	if (msg == SAME_COORDS)
	{
		exit_error("duplicate room coords");
	}
	return (NULL);
}
