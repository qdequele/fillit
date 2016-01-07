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

int		ft_read_params(t_env *env, char **av)
{
	int		fd;
	int		ret;
	char	buf[BUF_SIZE + 1];
	char	*complete_buf;

	complete_buf = (char *)malloc(sizeof(char));
	fd = open(av[1], O_RDWR, S_IRUSR | S_IWUSR);
	if (fd == -1)
		return (0);
	while ((ret = read(fd, buf, BUF_SIZE)) != 0)
	{
		buf[ret] = '\0';
		complete_buf = ft_strjoin(complete_buf, buf);
	}
	env->str = (char *)malloc(sizeof(char) * (ft_strlen(complete_buf) + 1));
	ft_strncpy(env->str, complete_buf, ft_strlen(complete_buf));
	if (ft_strlen(env->str) > 1)
		return (1);
	else
		return (0);
}
