/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_show.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjamin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/06 13:26:46 by bjamin            #+#    #+#             */
/*   Updated: 2016/01/06 13:32:05 by bjamin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <ft_fillit.h>

int	ft_show_map(t_env *env)
{
	int x;
	int y;

	y = 0;
	while (y < env->map_size)
	{
		x = 0;
		while (x < env->map_size)
		{
			ft_putchar(env->map[y][x]);
			x++;
		}
		ft_putchar('\n');
		y++;
	}
	ft_putchar('\n');
	return (1);
}
