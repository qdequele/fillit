/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read_params.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdequele <qdequele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/15 16:02:51 by qdequele          #+#    #+#             */
/*   Updated: 2015/12/30 17:10:02 by bjamin           ###   ########.fr       */
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

int		ft_read_params(t_env *env, char **av)
{
	int		fd;
	int		ret;
	char	*buf;

	buf = (char *)malloc(sizeof(char) * (BUF_SIZE + 1));
	env->str = (char *)malloc(sizeof(char));
	fd = open(av[1], O_RDWR, S_IRUSR | S_IWUSR);
	if (fd == -1)
		return (0);
	while ((ret = read(fd, buf, BUF_SIZE)) != 0)
	{
		buf[ret] = '\0';
		env->str = ft_strfjoin(env->str, buf);
	}
	if (buf)
		free(buf);
	if (ft_strlen(env->str) > 1)
		return (1);
	else
		return (0);
}
