NAME = log
CC = c++
CFLAGS = -std=c++98 -Wall -Wextra -Werror
SRCS = Account.cpp tests.cpp
OBJS = $(SRCS:.cpp=.o)

# Default target
all: $(NAME)

# Compile source files into object files
%.o: %.cpp
	$(CC) $(CFLAGS) -c $< -o $@

# Link object files into executable
$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $^ -o $@

# Clean up object files and executable
clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all
