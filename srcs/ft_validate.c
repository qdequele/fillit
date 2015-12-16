/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_validate.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdequele <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/15 15:55:35 by qdequele          #+#    #+#             */
/*   Updated: 2015/12/15 17:05:12 by qdequele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

int		check_char(char *str, int lg, int min)
{
	if (!(str[lg + min] == '.' || str[lg + min] == '#'
		|| str[lg + min] == '\n'))
		return (0);
	if (str[lg + min] == '#' && !(str[lg + min + 1] == '#'
			|| str[lg + min - 1] == '#' || str[lg + min - 5] == '#'
			|| str[lg + min + 5] == '#'))
		return (0);
	return (1);
}

int		check_tetriminos(char *str)
{
	int		lg;
	int		min;
	int		nbc;
	int		nbl;

	lg = 0;
	while (str[lg += 21])
	{
		min = 0;
		nbc = 0;
		nbl = 0;
		while (str[lg + min] != '\0' && min < 20)
		{
			if (checkChar(str, lg, min) == 0)
				return (0);
			if (str[lg + min] == '#')
				nbc++;
			if (str[lg + min++] == '\n')
				nbl++;
		}
		if (nbl != 4 || nbc != 4 || str[lg + min] != '\n'
			|| str[lg + min] != '\0')
			return (0);
	}
	return (1);
}
