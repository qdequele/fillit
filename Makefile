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
_SRC			= ft_fillit.c ft_compute.c ft_validate.c
SRC				= $(addprefix srcs/,$(_SRC))
CFLAGS			= -Wall -Wextra -Werror

all: libft $(NAME)

$(NAME):
	@mkdir bin
	@gcc $(CFLAGS) $(SRC) -L libft  -lft -I includes/ -o $(NAME)
	@echo $(NAME)" compilled"

libft:
	$(MAKE) --debug=v -w -C libft re
	@cp $(LIBFT_PATH)/libft.a .

clean:
	@rm -rf bin
	@echo "Clean all .o files"

fclean: clean
	@/bin/rm -f $(NAME)
	lclean
	@echo "Clean all .o and .a"

lclean: fclean
	$(MAKE) --debug=v -w -C libft fclean
	@echo "libft cleaned"

re: fclean all
