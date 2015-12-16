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

int		ft_parser(t_env *env)
{
	t_coord			coords[4];

	env->x = 0;
	while (env->str[env->x += 21])
	{
		env->y = 0;
		while (env->str[env->x + env->y] != '\0' && env->y < 20)
		{
			if ()
				return (0);
			if (env->str[env->x + env->y] == '#')
				env->width++;
			if (env->str[env->x + env->y++] == '\n')
				env->height++;
		}
		if (env->height != 4 || env->width != 4 || env->str[env->x + env->y] != '\n'
			|| env->str[env->x + env->y] != '\0')
			return (0);
	}
	return (1);
}