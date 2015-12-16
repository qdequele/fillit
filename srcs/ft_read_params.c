/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read_params.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdequele <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/15 16:02:51 by qdequele          #+#    #+#             */
/*   Updated: 2015/12/16 10:29:22 by qdequele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include "ft_fillit.h"

int    ft_read_params(t_env *env)
{
	int     ret;
    char    buf[BUF_SIZE + 1];
    char    *complete_buf;

    complete_buf = (char *)malloc(sizeof(char));
    while ((ret = read(0, buf, BUF_SIZE)) != 0)
    {
        buf[ret] = '\0';
        complete_buf = ft_strjoin(complete_buf, buf);
    }
    ft_strncpy(env->str, complete_buf, ft_strlen(complete_buf));
    if (ft_strlen(env->str) > 1)
        return (1);
    else
        return (0);
}