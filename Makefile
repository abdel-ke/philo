NAME = philo

SRCS =	libft/ft_atoi.c\
		libft/ft_isdigit.c\
		libft/ft_putstr_fd.c\
		libft/ft_putendl_fd.c\
		checker.c\
		philo.c

OBJ_DIR = philo
OBJ = $(addprefix $(OBJ_DIR)/,$(SRCS:.c = .o));
CFLAGS= #-Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(OBJ)
	gcc $(CFLAGS) $(OBJ) -o $(NAME)
	@echo "\n\033[32m--------- SUCCESSFUL ---------\033[0m"

$(OBJ): $(OBJ_DIR)/%.o: %.c philo.h
	mkdir -p $(dir $@)
	gcc -c $< -o $@

clean:
	rm -rf $(OBJ_DIR)

fclean: clean
	rm $(NAME)

re: fclean all
