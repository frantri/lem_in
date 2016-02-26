#ifndef LEM_IN_H
# define LEM_IN_H

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
	struct s_room	*next;
	//struct s_room	*prev;
	struct s_room	*neighbours;
	int				ant;
	char			*name;
	int				c_x;
	int				c_y;
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
	t_room			*rooms;
	int				ants;
	t_line			*lines;
}					t_map;



void	print_map(t_map *map);


void				get_nb_ants(int fd, t_map *map);
void				reprint_map(t_map *map, t_line *l);
void				add_line(t_map *map, char *line);
t_parsing_msg		exit_error(char *msg);
t_room				*new_room(char *name, int x, int y);
void				add_neighbour(t_room *room, t_room *ngh);
t_room				*get_room(t_room *room_list, char *name);
int	  				link_neighbour(t_room *room_list, char *r, char *n);
t_map				parse_file(int fd);
t_parsing_msg		handle_line(int fd, char **line, t_map *map);
t_parsing_msg		handle_room_line(char **line, t_map *map);
t_parsing_msg		handle_sharp(int fd, char **line, t_map *map);
t_parsing_msg		handle_special_line(int fd, char **line, t_map *map);
t_parsing_msg		handle_link_line(char **line, t_map *map);
int					add_room(t_map *map, t_room *room, int spec);
t_room				*is_valid_room(t_map *map, char *room_line);
int					is_int(char *arg);
t_parsing_msg		check_dbl(t_map *map, t_room *newroom);
#endif
