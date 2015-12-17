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

int ft_compute(t_env *env, t_tetriminos *current_tetrimino){
  int  i;

  i = 0;
  if(env->map[env->y][env->x] == '.')
    while (i < 4)
    {
      env->map[env->y][env->x] = current_tetrimino->letter;
    }
  ft_compute(env, current_tetrimino->next);
  return (1);
}
