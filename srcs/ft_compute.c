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
	while (env->current_index != env->pieces_count)
	{
		while (!ft_can_place(env))
		{
			if (env->y >= env->map_size - 1)
			{
				if (env->current_index == 0)
					return (0);
				env->current_index--;
				ft_remove(env);
			}
			ft_next(env);
		}
		ft_place(env);
		ft_next(env);
	}
	ft_success(env);
	return (1);
}
