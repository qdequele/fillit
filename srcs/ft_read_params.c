/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read_params.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdequele <qdequele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/15 16:02:51 by qdequele          #+#    #+#             */
/*   Updated: 2016/02/09 11:46:41 by qdequele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/uio.h>
#include <unistd.h>
#include "ft_fillit.h"

char	*ft_strfjoin(char *s1, char *s2)
{
	char *new_str;

	new_str = ft_strjoin(s1, s2);
	if (s1)
		free(s1);
	return (new_str);
}

void	ft_read_params(t_env *env, char **av)
{
	int		fd;
	int		ret;
	char	buf[BUF_SIZE + 1];

	ret = 0;
	fd = open(av[1], O_RDONLY);
	if (fd == -1)
		ft_error(env);
	ret = read(fd, buf, BUF_SIZE);
	buf[ret] = '\0';
	env->str = ft_strnew(ret);
	ft_strncpy(env->str, buf, ret);
	if (ft_strlen(env->str) <= 1)
		ft_error(env);
}
