/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_validate.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdequele <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/15 15:55:35 by qdequele          #+#    #+#             */
/*   Updated: 2015/12/15 17:05:12 by qdequele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include "ft_fillit.h"

int		ft_check_char(char *str, int x, int y)
{
	if (!(str[x + y] == '.' || str[x + y] == '#' || str[x + y] == '\n'))
		return (0);
	if (str[x + y] == '#' && !(str[x + y + 1] == '#' | str[x + y - 1] == '#'
		|| str[x + y - 5] == '#' || str[x + y + 5] == '#'))
		return (0);
	return (1);
}

int		ft_check_tetriminos(t_env *env)
{
	env->x = 0;
	while (env->str[env->x] != '\0')
	{
		env->y = 0;
		env->width = 0;
		env->height = 0;
		while (env->str[env->x + env->y] != '\0' && env->y < 20)
		{
			if (ft_check_char(env->str, env->x, env->y) == 0)
				return (0);
			if (env->str[env->x + env->y] == '#')
				env->width++;
			if (env->str[env->x + env->y++] == '\n')
				env->height++;	
		}
		if (env->height != 4 || env->width != 4 || (env->str[env->x + env->y] != '\n'
					&& env->str[env->x + env->y] != '\0'))
			return (0);	
		env->x += 21;
	}
	return (1);
}
