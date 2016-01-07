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

int		main(int ac, char **av)
{
	t_env	*env;

	env = (t_env *)malloc(sizeof(t_env));
	env->pieces_count = 0;
	env->pieces = NULL;
	env->current_index = 0;
	env->map_size = 0;
	env->offset = 0;
	env->step = 0;
	if (ac >= 2)
	{
		if (!ft_read_params(env, av))
			return (0);
		if (!ft_check_tetriminos(env))
			return (0);
		if (!ft_parser(env))
			return (0);
		while (ft_generate_map(env) && ft_update_tetrimino(env) && !ft_compute(env))
		{
			env->offset++;
			ft_free_map(env);
		}
		ft_debug("finish", env);
		ft_show_map(env);
	}
	return (1);
}
