/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tetrimino.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdequele <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/15 15:55:35 by qdequele          #+#    #+#             */
/*   Updated: 2015/12/15 17:05:12 by qdequele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <stdlib.h>
#include "ft_fillit.h"

int		ft_push_tetrimino(t_env *env, t_coord *coords)
{
	t_tetriminos	*t_new;
	t_tetriminos	*t_tmp;
	t_tetriminos	*t_mid;

	if (!(t_new = (t_tetriminos *)malloc(sizeof(t_tetriminos))))
		return (0);
	ft_memcpy(t_new->coords, coords, sizeof(t_coord));
	t_new->next = NULL;
	t_new->prev = NULL;
	if (!(env->pieces))
		env->pieces = t_new;
	else
	{
		t_tmp = env->pieces;
		while (t_tmp->next)
		{
			t_mid = t_tmp;
			t_tmp = t_tmp->next;
		}
		if (t_mid)
			t_new->prev = t_mid;
		t_tmp = t_new;
	}
	return (1);
}

void	ft_show_tetrimino(t_env *env)
{
	t_tetriminos	*t_tmp;
	int				i;

	t_tmp = env->pieces;
	while (t_tmp->next)
	{
		i = 0;
		while(i < 4){
			ft_putchar('(');
			ft_putnbr(t_tmp->coords[i].x);
			ft_putchar('-');
			ft_putnbr(t_tmp->coords[i].y);
			ft_putstr("),");
		}
		ft_putchar('\n');
	}
}