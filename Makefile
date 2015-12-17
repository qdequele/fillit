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
PATH			= pwd
NAME			= fillit
_SRC			= ft_test.c ft_compute.c ft_checker.c ft_read_params.c ft_tetrimino.c
SRC				= $(addprefix srcs/,$(_SRC))
CFLAGS			= -Wall -Wextra -Werror

all: libft_all $(NAME)

$(NAME):
	@mkdir bin
	@gcc $(CFLAGS) $(SRC) -L ./libft -lft -I includes/ -o $(NAME)
	@echo $(NAME)" compilled"

clean:
	libft_clean
	@/bin/rm -rf bin
	@echo "Clean all .o files"

fclean:
	libft_fclean
	clean
	@/bin/rm -rf $(NAME)
	@echo "Clean all .o and .a"

re: libft_re fclean all

libft_all:
	@$(MAKE) -v -C libft all

libft_clean:
	@$(MAKE) -v -C libft clean

libft_fclean:
	@$(MAKE) -v -C libft fclean

libft_re:
	@make -v -C libft re
