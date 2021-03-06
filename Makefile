SRC_NAME = check.c \
		   errors.c \
		   maintest.c \
		   parsing.c \
		   parsing2.c \
		   path.c \
		   print.c \
		   room.c \
		   room_links.c \
		   weights.c \
		   clear_start.c \
		   ants.c

OBJ_NAME = $(SRC_NAME:.c=.o)

SRC = $(addprefix src/, $(SRC_NAME))

OBJ = $(addprefix obj/, $(OBJ_NAME))

CFLAGS = -Wall -Wextra -Werror

LFLAGS = -lft -L libft

IFLAGS = -I . -I libft/includes

NAME = lem_in

VIEW_NAME = viewer

VIEW_SRC = ./visualizer/room.go ./visualizer/map.go ./visualizer/visualizer.go


CC = gcc

all: $(NAME) $(VIEW_NAME)

$(NAME): $(OBJ)
	make -C libft
	$(CC) $(CFLAGS) $(OBJ) $(LFLAGS) -o $(NAME)

obj/%.o: src/%.c
	@mkdir -p obj
	$(CC) $(CFLAGS) $(IFLAGS) -c $< -o $@

$(VIEW_NAME): $(VIEW_SRC)
	go build -o $(VIEW_NAME) $(VIEW_SRC)

clean:
	rm -rf obj
	make clean -C libft

fclean: clean
	rm -f $(NAME) $(VIEW_NAME)
	make fclean -C libft

re: fclean all

.PHONY: all re fclean clean
