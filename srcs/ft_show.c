/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_show.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdequele <qdequele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/06 13:26:46 by bjamin            #+#    #+#             */
/*   Updated: 2016/01/06 23:41:59 by qdequele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <ft_fillit.h>

int		ft_show_map(t_env *env)
{
	int x;
	int y;

	ft_debug("ft_show_map", env);
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

void	ft_debug(char *str, t_env *env)
{
	ft_putstr("######################\n\n");
	ft_putstr(str);
	ft_putstr("\nenv->x : ");
	ft_putnbr(env->x);
	ft_putstr("\nenv->y : ");
	ft_putnbr(env->y);
	ft_putstr("\nenv->height : ");
	ft_putnbr(env->height);
	ft_putstr("\nenv->width : ");
	ft_putnbr(env->width);
	ft_putstr("\nenv->pieces_count : ");
	ft_putnbr(env->pieces_count);
	ft_putstr("\nenv->current_index : ");
	ft_putnbr(env->current_index);
	ft_putstr("\nenv->current_letter : ");
	ft_putchar('A' + env->current_index);
	ft_putstr("\nenv->offset : ");
	ft_putnbr(env->offset);
	ft_putstr("\nenv->map_size : ");
	ft_putnbr(env->map_size);
	ft_putstr("\n--- END ---\n");
}

void	ft_show_tetrimino(t_env *env)
{
	t_tetriminos	*t_tmp;
	int				i;

	t_tmp = env->pieces;
	while (t_tmp->next)
	{
		i = 0;
		while (i < 4)
		{
			ft_putchar('(');
			ft_putnbr(t_tmp->coords[i].x);
			ft_putstr(" ; ");
			ft_putnbr(t_tmp->coords[i].y);
			ft_putstr(") \n");
			i++;
		}
		t_tmp = t_tmp->next;
		ft_putchar('\n');
	}
}
