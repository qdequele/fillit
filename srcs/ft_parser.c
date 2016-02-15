/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parser.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdequele <qdequele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/15 15:55:35 by qdequele          #+#    #+#             */
/*   Updated: 2016/02/09 18:00:21 by qdequele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include "ft_fillit.h"

void	ft_fill_chars(char *str, int size)
{
	int i;

	i = 0;
	while (i < size)
	{
		str[i] = '.';
		i++;
	}
	str[i] = '\0';
}

int		ft_generate_map(t_env *env)
{
	int i;

	i = 0;
	env->x = 0;
	env->y = 0;
	env->map_size = ft_sqrt((env->pieces_count + env->offset) * 4);
	env->map = (char **)malloc(sizeof(char *) * env->map_size);
	if (!env->map)
		ft_error(env);
	while (i < env->map_size)
	{
		env->map[i] = (char *)malloc(sizeof(char) * (env->map_size + 1));
		if (!env->map[i])
			ft_error(env);
		ft_fill_chars(env->map[i], env->map_size + 1);
		i++;
	}
	return (1);
}

void	ft_parse_coords(t_env *env, t_coord *first, t_coord **coords)
{
	int		i;

	i = 0;
	while (env->str[env->x + env->y] != '\0' && env->y < 20 && i < 4)
	{
		if (env->str[env->x + env->y] == '#')
		{
			if (i == 0)
				first = ft_new_coord(env->y / 5, env->y % 5);
			if (i == 0 && !first)
				ft_error(env);
			coords[i] = ft_new_coord(
						(env->y % 5) - (first->y), (env->y / 5) - first->x);
			if (!coords)
				ft_error(env);
			i++;
		}
		env->y++;
	}
}

void	ft_parser(t_env *env)
{
	t_coord	**coords;
	t_coord	*first;

	env->x = 0;
	first = NULL;
	while (env->str[env->x] != '\0')
	{
		env->y = 0;
		coords = (t_coord **)malloc(sizeof(t_coord *) * 4);
		ft_parse_coords(env, first, coords);
		ft_push_tetrimino(env, coords);
		env->x += 21;
	}
}

void	ft_check_returns(t_env *env)
{
	int i;

	i = 0;
	env->returns = 0;
	while (env->str[i] != '\0')
	{
		if (env->str[i] == '\n')
			env->returns++;
		i++;
	}
	if ((env->pieces_count == 1 && env->returns != 4)
		|| (env->pieces_count > 1
			&& env->returns != ((env->pieces_count * 4)
				+ (env->pieces_count - 1))))
		ft_error(env);
}
