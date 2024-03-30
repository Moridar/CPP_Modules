NAME = a.out
CC = c++
CFLAGS = -Wall -Wextra -Werror -std=c++11 -fsanitize=address
SRCS = AMateria.cpp Character.cpp Cure.cpp Ice.cpp MateriaSource.cpp MateriaTrash.cpp main.cpp 
OBJS = $(SRCS:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $^ -o $@

%.o: %.cpp
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all