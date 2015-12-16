/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fillit.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdequele <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/15 16:02:51 by qdequele          #+#    #+#             */
/*   Updated: 2015/12/16 10:29:22 by qdequele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef		FT_FILLIT_H
# define	FT_FILLIT_H
# define BUF_SIZE 7340032
#include <string.h>

typedef struct		s_coord {
	int				x;
	int				y;
}					t_coord;

typedef struct		s_tetriminos {
	t_coord			coords[4];
	struct s_tetriminos	*next;
	struct s_tetriminos	*prev;
}					t_tetriminos;

typedef struct		s_env {
	char 			*str;
	int				x;
	int				y;
	int				height;
	int				width;
	t_tetriminos	*pieces;
}					t_env;

int					ft_read_params(t_env *env, char **av);
int					check_tetriminos(t_env *env);
int					push_tetrimino(t_env *env, t_coord *coords);

#endif
