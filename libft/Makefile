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
ft_putendl_fd \
ft_putnbr_fd.c \


OBJS = ft_isalnum.o ft_isalpha.o ft_isdigit.o ft_isascii.o ft_isprint.o \
ft_strlen.o ft_memset.o ft_bzero.o ft_memcpy.o ft_calloc.o ft_strdup.o \
ft_tolower.o ft_atoi.o ft_strlcpy.o ft_strlcat.o ft_toupper.o ft_strncmp.o \
ft_strchr.o ft_strrchr.o ft_strnstr.o \
ft_memmove.o \
ft_memcmp.o \
ft_strjoin.o \
ft_substr.o \
ft_strmapi.o \
ft_striteri.o \
ft_memchr.o \
ft_putchar_fd.o \
ft_putstr_fd.o \
ft_putendl_fd.o \
ft_putnbr_fd.o \

BONUSSRCS = ft_lstnew.c \
ft_lstadd_front.c \
ft_lstsize.c \

BONUSOBJS = ft_lstnew.o \
ft_lstadd_front.o \
ft_lstsize.o \

INC = ./libft.h

CC = cc
CFLAGS = -c -Wall -Wextra -Werror
RM = rm -rf

all : $(NAME)

%.o : %.c
	$(CC) $(CFLAGS) $< -o $@ -I $(INC)

$(NAME) : $(OBJS)
	ar -rcs $@ $^

bonus : $(OBJS) $(BONUSOBJS)
	ar -rcs $(NAME) $^

clean : 
	$(RM) $(OBJS) $(BONUSOBJS)
fclean : clean
	$(RM) $(NAME)
re : fclean all
.PHONY : all clean fclean re