# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ggeri <ggeri@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/01/27 19:05:20 by ggeri             #+#    #+#              #
#    Updated: 2020/01/27 19:26:12 by ggeri            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# program name
NAME = fdf

# compiling with flags
FLAGS = -Wall -Wextra -Werror

# functions name
SRC = main

# functions <name>.c
FUNC_C = $(patsubst %, %.c, $(SRC))

# object files
OBJ = $(patsubst %, %.o, $(SRC))

# header
HEADER = fdf.h

all: $(NAME)

$(NAME): $(OBJ) $(HEADER)
		make -C libft/ fclean && make -C libft/
		gcc $(FLAGS) -I libft -I $(HEADER) -o main.o -c main.c
		gcc -o $(NAME) $(OBJ) -I $(HEADER) -I libft -L libft/ -lft

$(FUNC_O): %.o: %.c
		gcc $(FLAGS) -c $< -I $(HEADERS)

clean:
		make -C libft/ clean
		rm -rf $(OBJ)

fclean: clean
		rm -rf libft/libft.a
		rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re
