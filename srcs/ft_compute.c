/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_compute.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: quentindequelen <quentindequelen@student.42.fr>+#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/15 16:01:45 by bjamin            #+#    #+#             */
/*   Updated: 2016/01/06 09:41:56 by quentindequelen  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_fillit.h>
#include <libft.h>
#define X (env->x + env->current_tetrimino->coords[i].x)
#define Y (env->y + env->current_tetrimino->coords[i].y)

void	ft_debug(char *str, t_env *env)
{
	ft_putstr("\n\n######################\n\n");
	ft_putstr(str);
	ft_putstr("\nenv->x : ");
	ft_putnbr(env->x);
	ft_putstr("\nenv->y : ");
	ft_putnbr(env->y);
	ft_putstr("\nenv->height : ");
	ft_putnbr(env->height);
	ft_putstr("\nenv->width : ");
	ft_putnbr(env->width);
	ft_putstr("\nenv->pieces_count : ");
	ft_putnbr(env->pieces_count);
	ft_putstr("\nenv->current_index : ");
	ft_putnbr(env->current_index);
	ft_putstr("\nenv->offset : ");
	ft_putnbr(env->offset);
	ft_putstr("\nenv->map_size : ");
	ft_putnbr(env->map_size);
	ft_putstr("\n--- END ---\n");
}

int		ft_can_place(t_env *env)
{
	int		i;
	int		can_place;

	i = 0;
	can_place = 1;
	//ft_debug("ft_can_place", env);
	if (env->map[Y][X] == '.')
	{
		while (i < 4)
		{
			if (X < env->map_size && Y < env->map_size)
			{
				if (env->map[Y][X] != '.')
				{
					can_place = 0;
				}
			}
			i++;
		}
	}
	return (can_place);
}

int		ft_remove(t_env *env)
{
	int		x;
	int		y;

	x = 0;
	y = 0;
	while (y)
	{
		while (x)
		{
			if (env->map[y][x] >= 'A' + env->current_index)
				env->map[y][x] = '.';
			x++;
		}
		y++;
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
	//ft_debug("ft_update_tetrimino", env);
	while (i <= env->current_index && i < env->pieces_count)
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

void	ft_next(t_env *env)
{
	//ft_debug("ft_next", env);
	if (env->x < 4)
		env->x++;
	else
	{
		env->y++;
		env->x = 0;
	}
}

int		ft_compute(t_env *env)
{
	int		i;

	i = 0;
	ft_update_tetrimino(env);
	ft_debug("ft_compute", env);
	if (!ft_can_place(env))
	{
		if (env->y > env->map_size)
		{
			if (env->current_index == 0)
				return (0);
			ft_remove(env);
			env->current_index--;
		}
	}
	else
	{
		ft_place(env);
		if (env->current_index == env->pieces_count)
			return (1);
		env->current_index++;
	}
	ft_next(env);
	return (ft_compute(env));
}
