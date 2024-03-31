NAME = libft.a

SRCS = ft_isalnum.c \
ft_isalpha.c \
ft_isdigit.c \
ft_isascii.c \
ft_isprint.c \
ft_strlen.c \
ft_memset.c \
ft_bzero.c \
ft_memcpy.c \
ft_calloc.c \
ft_strdup.c \
ft_tolower.c \
ft_atoi.c \
ft_strlcpy.c ft_strlcat.c ft_toupper.c ft_strncmp.c \
ft_strchr.c ft_strrchr.c ft_strnstr.c \
ft_memmove.c \
ft_memcmp.c \
ft_strjoin.c \
ft_substr.c \
ft_strmapi.c \
ft_striteri.c \
ft_memchr.c \
 ft_putchar_fd.c \
ft_putstr_fd.c \
ft_putendl_fd.c \
ft_putnbr_fd.c \
ft_strtrim.c \
ft_split.c \
ft_itoa.c \
ft_realloc.c \
ft_puthex_fd.c \
ft_putuhex_fd.c \
ft_putunbr_fd.c \
ft_putptr_fd.c

OBJS = $(SRCS:.c=.o)

OBJS.d = $(OBJS:.o=.d)

BONUSSRCS = ft_lstnew_bonus.c \
ft_lstadd_front_bonus.c \
ft_lstsize_bonus.c \
ft_lstlast_bonus.c \
ft_lstadd_back_bonus.c \
ft_lstdelone_bonus.c \
ft_lstclear_bonus.c \
ft_lstiter_bonus.c \
ft_lstmap_bonus.c

BONUSOBJS = $(BONUSSRCS:.c=.o)

BONUSOBJS.d = $(BONUSSRCS:.o=.d)

INC = ./

CC = cc
CFLAGS = -c -Wall -Wextra -Werror -MMD -MP
RM = rm -rf

all : $(NAME)

%.o : %.c
	$(CC) $(CFLAGS) $< -o $@ -I $(INC)

$(NAME) : $(OBJS)
	ar -rcs $@ $^

bonus : $(BONUSOBJS)
	ar -rcs $(NAME) $^
	@touch $@

clean : 
	$(RM) $(OBJS) $(BONUSOBJS) $(OBJS.d) $(BONUSOBJS.d)
	rm -f bonus
fclean : clean
	$(RM) $(NAME)
re : fclean all
.PHONY : all clean fclean re bonus