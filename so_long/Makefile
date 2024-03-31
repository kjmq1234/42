SRC = main.c init_data.c utils.c map_valid.c map_utils.c get_next_line/get_next_line_bonus.c get_next_line/get_next_line_utils_bonus.c;
OBJ = $(SRC:.c=.o)

CC = cc
CFLAGS = -Wall -Wextra -Werror

all: so_long

so_long: $(OBJ) libft
	@$(CC) -o $@ $< -Llibft -lft


%.o: %.c
	$(CC) -c $(CFLAGS) $?

libft:
	@make -C libft

libftprintf:
	@make -C libftprintf

clean:
	rm -f $(OBJ)
	make -C libft libftprintf clean
	
fclean: clean
	rm -f so_long libft/libft.a libftprintf/libftprintf.a
	
re: fclean all
.PHONY: all bonus libft clean fclean re