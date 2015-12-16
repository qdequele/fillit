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

#Define the libft
LIBFT_NAME		= libft.a

#Define the program
PATH			= pwd
NAME			= fillit
_SRC			= srcs/ft_fillit.c srcs/ft_compute.c srcs/ft_validate.c
SRC				= $(addprefix srcs/,$(_SRC))
CFLAGS			= -Wall -Wextra -Werror
O_FILES			= $(patsubst %.c,%.o, $(_SRC))

all: $(LIBFT_NAME) $(NAME)

$(NAME):
	@mkdir bin
	@gcc $(CFLAGS) $(SRC) -Ofast -L libft  -lft -I includes/ -o $(NAME)
	@mv $(O_FILES) bin/
	@echo $(NAME)" compilled"

$(LIBFT_NAME):
	@(cd libft && $(MAKE) re)
	@cp $(LIBFT_PATH)/libft.a .

clean:
	@rm -rf bin
	@echo "Clean all .o files"

fclean: clean
	@/bin/rm -f $(NAME)
	lclean
	@echo "Clean all .o and .a"

lclean: fclean
	@(cd libft && $(MAKE) fclean)
	@echo "libft cleaned"

re: fclean all