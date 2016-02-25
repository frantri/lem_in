#include <lem_in.h>
#include <libft.h>

t_map		parse_file(int fd)
{
	char	*line;
	t_map	res;

	ft_bzero(&res, sizeof(res));
	while (get_next_line(fd, &line) == 1)
	{
		if (!line[0])
		{
			free(line);
			return (res);
		}
		if (line && line[0] == '#' && line[0] == '#')
	}
}

int			handle_sharp(char *line, t_map *map)
{
	
}

int			add_room(t_map *map, t_room *room)
{
	
}
