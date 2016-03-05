/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftriquet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/02 20:31:44 by ftriquet          #+#    #+#             */
/*   Updated: 2016/03/02 20:31:44 by ftriquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <lem_in.h>
#include <stdlib.h>
#include <libft.h>

t_parsing_msg		handle_room_line(char **line, t_map *map)
{
	t_room			*new_room;

	new_room = is_valid_room(map, *line);
	if (new_room)
	{
		add_room(map, new_room, 0);
		return (OK);
	}
	return (INVALID_LINE);
}

t_parsing_msg		handle_sharp(int fd, char **line, t_map *map)
{
	if (!(*line))
		return (INVALID_LINE);
	if ((*line)[0] == '#' && (*line)[1] != '#')
		return (COMMENT);
	else if ((*line)[0] == '#' && (*line)[1] == '#')
		return (handle_special_line(fd, line, map));
	return (OK);
}

t_parsing_msg		handle_special_line(int fd, char **line, t_map *map)
{
	int				flag;
	t_room			*new_room;

	if (!ft_strequ(*line, "##start") && !ft_strequ(*line, "##end"))
		return (INVALID_LINE);
	flag = ft_strequ(*line, "##start") - ft_strequ(*line, "##end");
	if (get_next_line(fd, line) != 1)
		return (INVALID_LINE);
	add_line(map, *line);
	new_room = is_valid_room(map, *line);
	if (new_room)
		add_room(map, new_room, flag);
	else
		return (INVALID_LINE);
	return (OK);
}

int					add_room(t_map *map, t_room *room, int flag)
{
	if (flag == 1 && map->start)
		exit_error("");
	if (flag == -1 && map->end)
		exit_error("");
	ft_list_add_back(&map->rooms, room, sizeof(t_room));
	if (flag == 1)
		map->start = room;
	if (flag == -1)
		map->end = room;
	return (0);
}
