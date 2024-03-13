SRC = server.c client.c
OBJ = $(SRC:.c=.o)

BONUS_SRC = server_bonus.c client_bonus.c
BONUS_OBJ = $(BONUS_SRC:.c=.o)

CC = cc
CFLAGS = -Wall -Wextra -Werror

all: server client

bonus: server_bonus client_bonus

server: server.o libft
	@$(CC) -o $@ $< -Llibft -lft

client: client.o libft
	@$(CC) -o $@ $< -Llibft -lft

server_bonus: server_bonus.o libft
	@$(CC) -o $@ $< -Llibft -lft

client_bonus: client_bonus.o libft
	@$(CC) -o $@ $< -Llibft -lft

%.o: %.c
	$(CC) -c $(CFLAGS) $?

libft:
	@make -C libft

clean:
	rm -f $(OBJ) $(BONUS_OBJ)
	make -C libft clean
	
fclean: clean
	rm -f server client libft/libft.a server_bonus client_bonus
	
re: fclean all
.PHONY: all bonus libft clean fclean re