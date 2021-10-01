# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: abdel-ke <abdel-ke@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/10/01 11:54:26 by abdel-ke          #+#    #+#              #
#    Updated: 2021/10/01 11:54:27 by abdel-ke         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo
HEADER = philosophers.h

SRCS =	ft_actions.c \
		ft_init.c \
		ft_parsing.c \
		philosophers.c

OBJ_DIR = ./objs
OBJ = $(addprefix $(OBJ_DIR)/,$(SRCS:.c=.o))
CFLAGS= -Wall -Wextra -Werror

all: $(NAME)

$(NAME) : $(OBJ)
	@gcc $(CFLAGS) $(OBJ) -o $(NAME) -lpthread
	@echo "\n\033[32m--------- SUCCESSFUL ---------\033[0m"

$(OBJ): $(OBJ_DIR)/%.o: %.c $(HEADER)
	@mkdir -p $(dir $@)
	@gcc -c $< -o $@

clean:
	@rm -rf $(OBJ_DIR)

fclean: clean
	@rm $(NAME)

re: fclean all
