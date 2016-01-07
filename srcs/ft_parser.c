/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parser.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdequele <qdequele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/15 15:55:35 by qdequele          #+#    #+#             */
/*   Updated: 2016/01/06 23:49:18 by qdequele         ###   ########.fr       */
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

	//ft_debug("ft_generate_map", env);
	i = 0;
	env->x = 0;
	env->y = 0;
	if(env->pieces_count < 4)
		env->map_size = ft_sqrt((env->pieces_count + env->offset) * 2);
	else
		env->map_size = ft_sqrt((env->pieces_count + env->offset) * 4);
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
	t_coord			**coords;
	t_coord			*first;
	int				i;

	//ft_debug("ft_parser", env);
	env->x = 0;
	while (env->str[env->x])
	{
		env->y = 0;
		i = 0;
		coords = (t_coord **)malloc(sizeof(t_coord) * 4);
		while (env->str[env->x + env->y] != '\0' && env->y < 20 && i < 4)
		{
			if (env->str[env->x + env->y] == '#')
			{
				if (i == 0)
					first = ft_new_coord(env->y / 5, env->y % 5);
				if (!first)
					return (0);
				coords[i] = ft_new_coord(
					(env->y % 5) - (first->y), (env->y / 5) - first->x);
				i++;
			}
			env->y++;
		}
		if(!ft_push_tetrimino(env, coords))
			return (0);
		env->x += 21;
	}
	return (1);
}
