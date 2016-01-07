/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_compute.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdequele <qdequele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/15 16:01:45 by bjamin            #+#    #+#             */
/*   Updated: 2016/01/06 23:58:21 by qdequele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_fillit.h>
#include <libft.h>

int		ft_can_place(t_env *env)
{
	int		i;

	//ft_debug("ft_can_place", env);
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

	ft_debug("ft_compute", env);
	i = 0;
	env->step++;
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
	}
	else
	{
		ft_place(env);
		if (env->current_index == env->pieces_count)
			return (1);
	}
	//ft_show_map(env);
	ft_putstr("\nStep = ");
	ft_putnbr(env->step);
	ft_putstr("\n");
	ft_next(env);
	return (ft_compute(env));
}
