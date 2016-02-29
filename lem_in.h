#ifndef LEM_IN_H
# define LEM_IN_H
# include <ft_list.h>
# include <string.h>

typedef enum		e_parsing_msg
{
	SAME_COORDS,
	SAME_NAME,
	INVALID_LINE,
	END_ROOM_LINE,
	END_PARSING,
	COMMENT,
	OK
}					t_parsing_msg;

typedef struct		s_room
{
	t_list			neighbours;
	int				ant;
	char			*name;
	int				c_x;
	int				c_y;
	int				weight;
	int				used;
}					t_room;

typedef struct		s_line
{
	char			*data;
	struct s_line	*next;
}					t_line;

typedef struct		s_map
{
	t_room			*start;
	t_room			*end;
	t_list			rooms;
	int				ants;
	t_line			*lines;
}					t_map;



t_parsing_msg		handle_special_line(int fd, char **line, t_map *map);
int					add_room(t_map *map, t_room *room, int flag);
t_parsing_msg		handle_sharp(int fd, char **line, t_map *map);
t_parsing_msg		handle_room_line(char **line, t_map *map);
t_parsing_msg		handle_line(int fd, char **line, t_map *map);
void				get_nb_ants(int fd, t_map *map);
void				add_line(t_map *map, char *line);
t_map				parse_file(int fd);
t_parsing_msg		handle_link_line(char **line, t_map *map);
t_room				*new_room(char *name, int x, int y);
void				add_neighbour(t_room *room, t_room *ngh);

int					room_cmp(void *d, size_t s, void *d2, size_t s2);
int					room_id(void *data, size_t s, void *data2, size_t s2);
int					ft_room_cmp(void *d, size_t s, void *d2, size_t s2);

t_room				*get_room(t_map *map, char *name);
int					link_neighbour(t_map *map, char *r, char *n);
t_room				*is_valid_room(t_map *map, char *line);
int					is_int(char *arg);
t_parsing_msg		check_dbl(t_map *map, t_room *newroom);
t_parsing_msg		exit_error(char *msg);

void	print_room_name(void *room, size_t s);
void	print_room(void *d, size_t s);
void				reprint_map(t_map *map, t_line *l);
void				print_map(t_map *map);

void				put_weights(t_map *map);
void				add_neighbours_to_queue(t_room *room, t_list *list);
void				break_link(t_room *room, t_room *target);


#endif
