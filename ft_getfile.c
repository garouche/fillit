/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getfile.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: garouche <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/06 16:00:27 by garouche          #+#    #+#             */
/*   Updated: 2017/04/27 15:54:33 by garouche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include <stdio.h>
#include <string.h>
#include <errno.h>

t_coord	*ft_set(t_coord *coord)
{
	coord->a = -1;
	coord->b = -1;
	return (coord);
}

t_coord	*ft_copy_coord(char (*tetri)[5], t_coord *coord)
{
	int	i;
	int	j;

	i = -1;
	j = -1;
	coord = ft_set(coord);
	while (i++ < 4)
	{
		while (j++ < 4)
		{
			if (tetri[j][i] == '#' && coord->b == -1)
				coord->b = i;
			if (tetri[i][j] == '#' && coord->a == -1)
				coord->a = i;
		}
		j = -1;
	}
	return (coord);
}

void	ft_put_tetri(char array[16][16], char buf[26][21], int nb)
{
	int		i;
	t_coord acoord;

	i = -1;
	ft_memset(&acoord, 0, sizeof(acoord));
	acoord.sq = 2;
	while (!ft_checksquare(array, buf, acoord, nb))
	{
		acoord.sq++;
		ft_resetarray(array);
	}
	while (++i <= acoord.sq)
	{
		write(1, array[i], acoord.sq + 1);
		ft_putchar('\n');
	}
}

void	ft_resetarray(char array[16][16])
{
	int i;

	i = 0;
	while (i < 16)
	{
		ft_memset(array[i], '.', 16);
		array[i][15] = 0;
		i++;
	}
	array[15][0] = 0;
}

void	ft_get_tetri(char *argv)
{
	char	buf[26][21];
	int		fd;
	char	array[16][16];
	int		i;

	fd = open(argv, O_RDONLY);
	if (fd == -1)
		return (ft_putstr("error\n"));
	read(fd, buf, 21 * 26);
	ft_resetarray(array);
	i = ft_check(buf);
	if (i > 1)
		ft_put_tetri(array, buf, i);
	else
		ft_putstr("error\n");
}
