/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parser.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdequele <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/15 15:55:35 by qdequele          #+#    #+#             */
/*   Updated: 2015/12/15 17:05:12 by qdequele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include "ft_fillit.h"

int 	ft_fill_chars(char *str, int size){
	int i;

	i = 0;
	while (i < size){
		str[i] = '.';
		i++;
	}
	str[i] = '\0';
	return (1);
}
int		ft_generate_map(t_env *env){
	int i;
	int map_size;

	i = 0;
	map_size = ft_sqrt(env->pieces_count * 4);
	env->map = (char **)malloc(sizeof(char *) * map_size);
	if (!env->map)
		return (0);
	while (i < map_size){
		env->map[i] = (char *)malloc(sizeof(char) * (map_size + 1));
		if (!env->map[i])
			return (0);
		ft_fill_chars(env->map[i], map_size + 1);
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
	while (env->str[env->x])
	{
		env->y = 0;
		i = 0;
		while (env->str[env->x + env->y] != '\0' && env->y < 20 && i < 4)
		{
			if (env->str[env->x + env->y] == '#'){
				if (i == 0)
					first[0] = *ft_new_coord(env->y / 5, env->y % 5);
				coords[i] = *ft_new_coord((env->y % 5) - (first[0].y), (env->y / 5) - (first[0].x));
				i++;
			}
			env->y++;
		}
		ft_push_tetrimino(env, coords);
		env->x += 21;
	}
	return (ft_generate_map(env));
}
