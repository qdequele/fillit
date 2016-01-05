/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_compute.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjamin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/15 16:01:45 by bjamin            #+#    #+#             */
/*   Updated: 2016/01/05 15:45:44 by bjamin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_fillit.h>
#include <libft.h>
#define X env->x + env->current_tetrimino->coords[i].x
#define Y env->y + env->current_tetrimino->coords[i].y

int		ft_can_place(t_env *env)
{
	int		i;
	int		can_place;

	i = 0;
	can_place = 1;
	if (env->map[Y][X] == '.')
	{
		while (i < 4)
		{
			if (env->map[Y][X] != '.')
				can_place = 0;
		}
	}
	return (can_place);
}

int		ft_remove(t_env *env)
{
	env->x = 0;
	env->y = 0;
	while (env->y)
	{
		while (env->x)
		{
			if (env->map[Y][X] >= 'A' + env->current_index)
				env->map[Y][X] = '.';
			env->x++;
		}
		env->y++;
	}
	return (1);
}

int		ft_place(t_env *env)
{
	int i;

	i = 0;
	while (i < 4)
	{
		env->map[Y][X] = env->current_tetrimino->letter;
		i++;
	}
	return (1);
}

int		ft_update_tetrimino(t_env *env)
{
	t_tetriminos	*t_tmp;
	int				i;

	t_tmp = env->pieces;
	i = 0;
	while (i <= env->current_index)
	{
		if (!t_tmp->next)
		{
			env->current_tetrimino = NULL;
			return (0);
		}
		t_tmp = t_tmp->next;
	}
	env->current_tetrimino = t_tmp;
	return (1);
}

int		ft_compute(t_env *env)
{
	int		i;

	i = 0;
	if (ft_can_place(env))
	{
		ft_place(env);
		env->current_index++;
		ft_update_tetrimino(env);
	}
	else
	{
		if (env->x < 4)
			env->x++;
		else
		{
			env->y++;
			env->x = 0;
		}
	}
	ft_compute(env);
	return (1);
}
