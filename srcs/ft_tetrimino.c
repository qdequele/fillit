/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tetrimino.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdequele <qdequele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/15 15:55:35 by qdequele          #+#    #+#             */
/*   Updated: 2016/02/09 18:00:33 by qdequele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <stdlib.h>
#include "ft_fillit.h"

void	ft_check_char(t_env *env)
{
	if (!(env->str[env->x + env->y] == '.'
		|| env->str[env->x + env->y] == '#'
		|| env->str[env->x + env->y] == '\n'
		|| env->str[env->x + env->y] == '\0'))
		ft_error(env);
	if (env->str[env->x + env->y] == '#'
		&& !(env->str[env->x + env->y + 1] == '#'
			|| env->str[env->x + env->y - 1] == '#'
			|| env->str[env->x + env->y - 5] == '#'
			|| env->str[env->x + env->y + 5] == '#'))
		ft_error(env);
}

int		ft_check_near(t_env *env)
{
	return ((env->str[env->x + env->y] == '#')
		&& ((TOP && LEFT) || (TOP && BOT) || (TOP && RIGHT)
		|| (RIGHT && BOT) || (RIGHT && LEFT) || (BOT && LEFT)));
}

void	ft_check_case(t_env *env)
{
	ft_check_char(env);
	env->near += ft_check_near(env);
	if (env->str[env->x + env->y] == '#')
		env->width++;
	if (env->str[env->x + env->y++] == '\n')
	{
		env->height++;
		if (env->y % 5 != 0)
			ft_error(env);
	}
}

void	ft_check_tetriminos(t_env *env)
{
	env->x = 0;
	while (env->str[env->x] != '\0')
	{
		env->y = 0;
		env->width = 0;
		env->height = 0;
		env->near = 0;
		while (env->str[env->x + env->y] != '\0' && env->y < 20)
		{
			ft_check_case(env);
		}
		if (env->height != 4 || env->width != 4
			|| (env->str[env->x + env->y] != '\n'
			&& env->str[env->x + env->y] != '\0')
			|| env->str[env->x + env->y + 1] == '\n' || env->near == 0)
			ft_error(env);
		env->x += 21;
	}
}

void	ft_push_tetrimino(t_env *env, t_coord **coords)
{
	t_tetriminos	*t_new;
	t_tetriminos	*t_tmp;

	if (!(t_new = (t_tetriminos *)malloc(sizeof(t_tetriminos))))
		ft_error(env);
	t_new->coords = coords;
	t_new->last = NULL;
	t_new->next = NULL;
	t_new->letter = 'A' + env->pieces_count;
	env->pieces_count++;
	if (env->pieces_count > 26)
		ft_error(env);
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
}
