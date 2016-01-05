/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fillit.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdequele <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/15 16:02:51 by qdequele          #+#    #+#             */
/*   Updated: 2016/01/05 15:31:45 by bjamin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_FILLIT_H
# define FT_FILLIT_H
# define BUF_SIZE 5000

# include <string.h>
# include <stdlib.h>

typedef struct		s_coord
{
	int				x;
	int				y;
}					t_coord;

typedef struct		s_tetri
{
	t_coord			coords[4];
	struct s_tetri	*next;
	char			letter;
}					t_tetriminos;

typedef struct		s_env
{
	char			*str;
	int				x;
	int				y;
	int				height;
	int				width;
	int				pieces_count;
	int				current_index;
	t_tetriminos	*current_tetrimino;
	t_tetriminos	*pieces;
	char			**map;
}					t_env;

int					ft_read_params(t_env *env, char **av);
int					ft_check_tetriminos(t_env *env);
int					ft_check_char(char *str, int x, int y);
int					ft_parser(t_env *env);
int					ft_push_tetrimino(t_env *env, t_coord *coords);
void				ft_show_tetrimino(t_env *env);
t_coord				*ft_new_coord(int x, int y);
int					ft_compute(t_env *env);
int					ft_update_tetrimino(t_env *env);
int					ft_place(t_env *env);
int					ft_remove(t_env *env);
#endif
