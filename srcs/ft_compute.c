/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_compute.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjamin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/15 16:01:45 by bjamin            #+#    #+#             */
/*   Updated: 2015/12/15 16:01:47 by bjamin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_fillit.h>
#include <libft.h>
#define X env->x + current_tetrimino->coords[i].x
#define Y env->y + current_tetrimino->coords[i].y

int		ft_can_place(t_env *env, t_tetriminos *current_tetrimino){
	int		i;
	int		can_place;

	i = 0;
	can_place = 1;
	if(env->map[Y][X] == '.')
		while (i < 4)
		{
			if(env->map[Y][X] != '.')
				can_place = 0;
		}
	return (can_place);
}

int		ft_compute(t_env *env, t_tetriminos *current_tetrimino){
	int		i;

	i = 0;
	if (ft_can_place(env, current_tetrimino))
	{	
		while (i < 4)
			{
				env->map[Y][X] = current_tetrimino->letter;
			}
		current_tetrimino = current_tetrimino->next
	}
	else
	{
		if (env->x < 4)
			env->x++;
		else
		{
			env->y++;
			env->x = 0;
		}
	}
	ft_compute(env, current_tetrimino);
	return (1);
}
