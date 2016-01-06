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
	ft_putstr("######################\n\n");
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
	if (env->map[Y][X] == '.')
	{
		while (i < 4)
		{
			if (((X < env->map_size - 1) && (Y < env->map_size - 1)) && env->map[Y][X] != '.')
			{
				can_place = 0;
			}
			i++;
		}
	}
	else
		can_place = 0;

	if (can_place && env->current_tetrimino->letter == 'K')
	{
		ft_putstr("\n\nWARNING\n\n");
		ft_debug("ft_can_place", env);
		ft_show_map(env);
	}

	return (can_place);
}

int		ft_remove(t_env *env)
{
	int		x;
	int		y;

	y = 0;
	while (y)
	{
		x = 0;
		while (x)
		{
			if (env->map[y][x] >= 'A' + env->current_index)
				env->map[y][x] = '.';
			x++;
		}
		y++;
	}
	env->current_index--;
	ft_update_tetrimino(env);
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
	env->current_index++;
	ft_update_tetrimino(env);
	return (1);
}

int		ft_update_tetrimino(t_env *env)
{
	t_tetriminos	*t_tmp;
	int				i;

	t_tmp = env->pieces;
	i = 0;
	//ft_debug("ft_update_tetrimino", env);
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

void	ft_next(t_env *env)
{
	//ft_debug("ft_next", env);
	if (env->x < (env->map_size - 1))
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
	if (!ft_can_place(env))
	{
		if (env->y > env->map_size)
		{
			if (env->current_index == 0)
				return (0);
			ft_remove(env);
		}
	}
	else
	{
		ft_place(env);
		if (env->current_index == env->pieces_count)
			return (1);
	}
	ft_next(env);
	return (ft_compute(env));
}
