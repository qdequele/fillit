/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdequele <qdequele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/15 16:01:45 by bjamin            #+#    #+#             */
/*   Updated: 2016/01/06 23:56:21 by qdequele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_fillit.h>
#include <libft.h>

int		ft_free_map(t_env *env)
{
	int y;

	//ft_debug("ft_free_map", env);
	y = 0;
	while (y < env->map_size)
	{
		if (env->map[y])
			free(env->map[y]);
		y++;
	}
	if (env->map)
		free(env->map);
	env->x = 0;
	env->y = 0;
	return (1);
}

int		ft_free_tetrimino(t_env *env)
{
	t_tetriminos	*t_tmp;

	t_tmp = env->pieces;
	while (t_tmp->next)
	{
		if (t_tmp->last)
			free(t_tmp->last);
		t_tmp = t_tmp->next;
	}
	if (t_tmp)
		free(t_tmp);
	if (env->pieces)
		free(env->pieces);
	return (1);
}

int		ft_free_env(t_env *env)
{
	ft_free_map(env);
	if (env->str)
		free(env->str);
	if (env->current_tetrimino)
		free(env->current_tetrimino);
	ft_free_tetrimino(env);
	if(env)
		free(env);
	return (1);
}