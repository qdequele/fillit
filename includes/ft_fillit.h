/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fillit.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdequele <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/15 16:02:51 by qdequele          #+#    #+#             */
/*   Updated: 2015/12/16 10:29:22 by qdequele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef		FT_FILLIT_H
# define	FT_FILLIT_H
# define BUF_SIZE 7340032
#include <string.h>

typedef struct	s_env {
	char 		*str;
	int			x;
	int			y;
	int			height;
	int			width;
}				t_env;

int    ft_read_params(t_env *env);

#endif