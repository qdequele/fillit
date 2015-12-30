/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_coords.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdequele <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/15 15:55:35 by qdequele          #+#    #+#             */
/*   Updated: 2015/12/30 17:05:53 by bjamin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include "ft_fillit.h"

t_coord		*ft_new_coord(int x, int y)
{
	t_coord		*t_new;

	if (!(t_new = (t_coord *)malloc(sizeof(t_coord))))
		return (NULL);
	t_new->x = x;
	t_new->y = y;
	return (t_new);
}
