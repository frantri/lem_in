#ifndef LEM_IN_H
# define LEM_IN_H

typedef enum		e_parsing_err
{
	SAME_COORDS,
	SAME_NAME,
	INVALID_LINE,
	OK
}					t_parsing_err;

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

typedef struct		s_map
{
	t_room			*start;
	t_room			*end;
	t_room			*rooms;
}					t_map;
#endif
