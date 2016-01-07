/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_actions.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdequele <qdequele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/15 16:01:45 by bjamin            #+#    #+#             */
/*   Updated: 2016/01/06 23:56:21 by qdequele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_fillit.h>
#include <libft.h>

int		ft_remember(t_env *env)
{
	t_tetriminos	*t_tmp;

	ft_debug("ft_remember", env);
	t_tmp = env->current_tetrimino->next;
	env->x = env->current_tetrimino->last->x;
	env->y = env->current_tetrimino->last->y;
	while (t_tmp && t_tmp->last)
	{
		t_tmp->last->x = 0;
		t_tmp->last->y = 0;
		t_tmp = t_tmp->next;
	}
	return (1);
}

int		ft_remove(t_env *env)
{
	int		x;
	int		y;

	ft_debug("ft_remove", env);
	y = 0;
	while (y < env->map_size)
	{
		x = 0;
		while (x < env->map_size)
		{
			if (env->map[y][x] >= 'A' + env->current_index)
				env->map[y][x] = '.';
			x++;
		}
		y++;
	}
	ft_remember(env);
	return (1);
}

int		ft_place(t_env *env)
{
	int i;

	ft_debug("ft_place", env);
	i = 0;
	while (i < 4)
	{
		env->map[Y][X] = env->current_tetrimino->letter;
		i++;
	}
	env->current_tetrimino->last = ft_new_coord(env->x, env->y);
	env->current_index++;
	ft_update_tetrimino(env);
	env->x = 0;
	env->y = 0;
	return (1);
}

int		ft_update_tetrimino(t_env *env)
{
	t_tetriminos	*t_tmp;
	int				i;

	//ft_debug("ft_update_tetrimino", env);
	t_tmp = env->pieces;
	i = 0;
	while (i < env->current_index && i <= env->pieces_count)
	{
		if (!t_tmp->next)
		{
			env->current_tetrimino = NULL;
			return (0);
		}
		t_tmp = t_tmp->next;
		i++;
	}
	env->current_tetrimino = t_tmp;
	return (1);
}
