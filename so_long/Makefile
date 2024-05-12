NAME = so_long
CC = cc
CFLAGS = -Wall -Wextra -Werror
RM = rm -f

SRCS = get_next_line_bonus.c \
	get_next_line_utils_bonus.c \
	init_data.c \
	map_parsing_utils.c \
	map_valid.c \
	utils.c \
	main.c \
	map_parsing.c \
	make_window.c \
	key_control.c \
	press_keys.c \
	move_utils.c \
	map_valid_dfs.c

INC_DIR = include
LIB_DIR = libft
MLX_DIR = /usr/local/lib

OBJS = $(SRCS:%.c=%.o)

LIBFT = $(LIB_DIR)/libft.a

all: $(NAME)

$(NAME): $(OBJS) $(LIBFT)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS) -L$(LIB_DIR) -lft -L$(MLX_DIR) -lmlx -framework OpenGL -framework AppKit

$(LIBFT):
	make -C $(LIB_DIR)

%.o: %.c
	$(CC) $(CFLAGS) -I$(INC_DIR) -c $< -o $@

clean:
	$(RM) $(OBJS)
	make -C $(LIB_DIR) clean

fclean: clean
	$(RM) $(NAME)
	make -C $(LIB_DIR) fclean

re: fclean all

.PHONY: all clean fclean re