NAME = do-op

SRCS = do-op.c operator.c celcul.c
OBJS = do-op.o operator.o celcul.o

CC = cc
CFLAGS = -Wall -Wextra -Werror
RM = rm -rf


all : $(NAME)

$.o : %.c
	$(CC) $(CFLAGS) -c $< $@ -I ft.h

$(NAME) : $(OBJS)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS)

clean : 
	$(RM) $(OBJS) 
fclean : clean
	$(RM) $(NAME) 
re : fclean all 
.PHONY : all clean fclean re 
