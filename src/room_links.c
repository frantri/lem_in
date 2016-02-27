#include <lem_in.h>
#include <libft.h>

t_parsing_msg	handle_link_line(char **line, t_map *map)
{
	char	**split;

	split = ft_strsplit(*line, '-');
	if (ft_tabsize((void **)split) != 2)
	{
		ft_freetab(split);
		return (INVALID_LINE);
	}
	if (link_neighbour(map, split[0], split[1]) == -1)
		return (INVALID_LINE);
	if (link_neighbour(map, split[1], split[0]) == -1)
		return (INVALID_LINE);
	return (OK);
}
