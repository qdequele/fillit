/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tetrimino.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdequele <qdequele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/15 15:55:35 by qdequele          #+#    #+#             */
/*   Updated: 2016/01/06 23:42:07 by qdequele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <stdlib.h>
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
	//ft_debug("ft_check_tetriminos", env);
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
		if (env->height != 4 || env->width != 4
			|| (env->str[env->x + env->y] != '\n'
			&& env->str[env->x + env->y] != '\0'))
			return (0);
		env->x += 21;
	}
	return (1);
}

int		ft_push_tetrimino(t_env *env, t_coord *coords)
{
	t_tetriminos	*t_new;
	t_tetriminos	*t_tmp;
	
	//ft_debug("ft_push_tetrimino", env);
	if (!(t_new = (t_tetriminos *)malloc(sizeof(t_tetriminos))))
		return (0);
	ft_memcpy(t_new->coords, coords, sizeof(t_coord) * 4);
	t_new->next = NULL;
	t_new->letter = 'A' + env->pieces_count;
	env->pieces_count++;
	if (env->pieces_count > 26)
		return (0);
	if (env->pieces == NULL)
		env->pieces = t_new;
	else
	{
		t_tmp = env->pieces;
		while (t_tmp->next)
		{
			t_tmp = t_tmp->next;
		}
		t_tmp->next = t_new;
	}
	return (1);
}
