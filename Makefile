#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: qdequele <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/12/15 14:57:05 by qdequele          #+#    #+#              #
#    Updated: 2015/12/15 16:58:27 by bjamin           ###   ########.fr        #
#                                                                              #
#******************************************************************************#

#Define the program
NAME			= fillit
_SRC			= ft_fillit.c ft_compute.c ft_checker.c ft_read_params.c ft_tetrimino.c ft_coords.c
SRC				= $(addprefix srcs/,$(_SRC))
INCLUDE   = includes
VPATH			= SRC INCLUDE
CFLAGS		= -Wall -Wextra -Werror

all: $(NAME)

$(NAME):
	@mkdir bin
	@make -C libft
	@gcc $(CFLAGS) $(SRC) -Llibft -lft -Iincludes -Ilibft -o $(NAME)
	@echo $(NAME)" compilled"

clean:
	@make clean -C libft
	@/bin/rm -rf bin
	@echo "Clean all .o files"

fclean:
	@make fclean -C libft
	@/bin/rm -rf bin
	@/bin/rm -rf $(NAME)
	@echo "Clean all .o and .a"

re: fclean all

.PHONY: all, clean, fclean, re
