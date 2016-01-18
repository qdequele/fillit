/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fillit.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjamin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/15 16:00:29 by bjamin            #+#    #+#             */
/*   Updated: 2016/01/05 15:46:40 by bjamin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_fillit.h"
#include <libft.h>

int		ft_init(t_env *env)
{
	env->pieces_count = 0;
	env->pieces = NULL;
	env->current_index = 0;
	env->map_size = 0;
	env->offset = 0;
	env->step = 0;
	env->x = 0;
	env->y= 0;
	env->width = 0;
	env->height = 0;
	return (1);
}

int		main(int ac, char **av)
{
	t_env	*env;

	env = (t_env *)malloc(sizeof(t_env));
	if (!env)
		ft_error(env);
	ft_init(env);
	if (ac >= 2)
	{
		ft_read_params(env, av);
		ft_check_tetriminos(env);
		ft_parser(env);
		while (ft_generate_map(env) && ft_update_tetrimino(env)
				&& !ft_compute(env))
		{
			env->step = 0;
			env->offset++;
			ft_free_map(env);
		}
		//ft_debug("finish", env);
	}
	return (1);
}
