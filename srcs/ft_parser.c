/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parser.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: quentindequelen <quentindequelen@student.42.fr>+#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/15 15:55:35 by qdequele          #+#    #+#             */
/*   Updated: 2016/01/06 16:07:58 by quentindequelen  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include "ft_fillit.h"

int		ft_fill_chars(char *str, int size)
{
	int i;

	i = 0;
	while (i < size)
	{
		str[i] = '.';
		i++;
	}
	str[i] = '\0';
	return (1);
}

int		ft_generate_map(t_env *env)
{
	int i;

	i = 0;
	env->x = 0;
	env->y = 0;
	env->map_size = ft_sqrt((env->pieces_count + env->offset) * 4);
	//ft_debug("ft_generate_map", env);
	env->map = (char **)malloc(sizeof(char *) * env->map_size);
	if (!env->map)
		return (0);
	while (i < env->map_size)
	{
		env->map[i] = (char *)malloc(sizeof(char) * (env->map_size + 1));
		if (!env->map[i])
			return (0);
		ft_fill_chars(env->map[i], env->map_size + 1);
		i++;
	}
	return (1);
}

int		ft_parser(t_env *env)
{
	t_coord			coords[4];
	t_coord			first[1];
	int				i;

	env->x = 0;
	//ft_debug("ft_parser", env);
	while (env->str[env->x])
	{
		env->y = 0;
		i = 0;
		while (env->str[env->x + env->y] != '\0' && env->y < 20 && i < 4)
		{
			if (env->str[env->x + env->y] == '#')
			{
				if (i == 0)
					first[0] = *ft_new_coord(env->y / 5, env->y % 5);
				coords[i] = *ft_new_coord(
					(env->y % 5) - (first[0].y), (env->y / 5) - (first[0].x));
				i++;
			}
			env->y++;
		}
		ft_push_tetrimino(env, coords);
		env->x += 21;
	}
	return (1);
}
