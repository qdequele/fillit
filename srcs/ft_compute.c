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
  env->map[0][0] = current_tetrimino->letter;
  return (1);
}
