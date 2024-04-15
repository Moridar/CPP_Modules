NAME = a.out
CC = c++
CFLAGS = -Wall -Wextra -Werror -std=c++11 
SRCS = Bureaucrat.cpp AForm.cpp main.cpp PresidentialPardonForm.cpp RobotomyRequestForm.cpp ShrubberyCreationForm.cpp
OBJS = $(SRCS:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $^ -o $@

%.o: %.cpp
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm Home_shrubbery
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all