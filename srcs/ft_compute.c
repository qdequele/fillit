/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_compute.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: quentindequelen <quentindequelen@student.42.fr>+#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/15 16:01:45 by bjamin            #+#    #+#             */
/*   Updated: 2016/01/06 18:09:02 by quentindequelen  ###   ########.fr       */
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
	ft_putstr("\nenv->current_letter : ");
	ft_putchar('A' + env->current_index);
	ft_putstr("\nenv->offset : ");
	ft_putnbr(env->offset);
	ft_putstr("\nenv->map_size : ");
	ft_putnbr(env->map_size);
	ft_putstr("\n--- END ---\n");
}

int		ft_can_place(t_env *env)
{
	int		i;

	i = 0;

	if (env->map[Y][X] == '.')
	{
		while (i < 4)
		{
			if ((X > env->map_size - 1) || (Y > env->map_size - 1) ||
					env->map[Y][X] != '.')
				return (0);
			i++;
		}
	}
	else
		return (0);
	return (1);
}

int		ft_remember(t_env *env)
{
	t_tetriminos	*t_tmp;

	t_tmp = env->current_tetrimino->next;
	env->x = env->current_tetrimino->last->x;
	env->y = env->current_tetrimino->last->y;
	while (t_tmp && t_tmp->last)
	{
		if (t_tmp->letter == 'B')
			ft_putstr("RAZ B\n");
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

	//ft_debug("ft_remove", env);
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
	ft_debug("ft_remove", env);
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
		if (env->y >= env->map_size - 1)
		{
			if (env->current_index == 0)
				return (0);
			env->current_index--;
			ft_update_tetrimino(env);
			ft_remove(env);
		}
		ft_next(env);
	}
	else
	{
		ft_place(env);
		if (env->current_index == env->pieces_count)
			return (1);
		ft_next(env);
	}
	ft_debug("ft_compute", env);
	ft_show_map(env);
	return (ft_compute(env));
}
