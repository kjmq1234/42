CC = c++

CFLAGS = -Wall -Wextra -Werror -std=c++98

SRCS = main.cpp Zombie.cpp ZombieHorde.cpp

OBJS = $(SRCS:.cpp=.o)

TARGET = Moar_brainz!

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) $^ -o $@ 

%.o: %.cpp
	$(CC) $(CFLAGS) -c $< -o $@

fclean: clean
	rm -f $(TARGET)

clean:
	rm -f $(OBJS)

re: fclean all

.PHONY: all clean fclean re