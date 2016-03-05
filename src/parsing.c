/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
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

t_map				parse_file(int fd)
{
	char			*line;
	t_map			map;
	t_parsing_msg	flag;

	ft_bzero(&map, sizeof(map));
	ft_list_init(&(map.rooms), NULL);
	get_nb_ants(fd, &map);
	while (get_next_line(fd, &line) == 1)
	{
		add_line(&map, line);
		flag = handle_line(fd, &line, &map);
		if (flag == INVALID_LINE || flag == END_PARSING)
			break ;
	}
	if (!map.start)
		exit_error("");
	if (!map.end)
		exit_error("");
	return (map);
}

void				add_line(t_map *map, char *line)
{
	t_line	*new;

	new = malloc(sizeof(*new));
	if (!new)
		return ;
	new->data = line;
	new->next = NULL;
	if (map->lines)
	{
		new->next = map->lines;
		map->lines = new;
	}
	else
		map->lines = new;
}

void				get_nb_ants(int fd, t_map *map)
{
	char			*line;

	while (42)
	{
		if (get_next_line(fd, &line) != 1)
			exit_error("");
		add_line(map, line);
		if (line[0] == '#' && line[1] == '\0')
			continue ;
		if (is_int(line))
		{
			map->ants = ft_atoi(line);
			break ;
		}
		else
			exit_error("");
	}
}

t_parsing_msg		handle_line(int fd, char **line, t_map *map)
{
	static int		room_flag = 1;
	t_parsing_msg	msg;

	if ((*line)[0] == '\0')
		return (END_PARSING);
	if ((*line)[0] == '#')
		return (handle_sharp(fd, line, map));
	if (!ft_strchr(*line, ' '))
		room_flag = 0;
	if (room_flag == 1)
		msg = handle_room_line(line, map);
	else
		msg = handle_link_line(line, map);
	return (msg);
}
