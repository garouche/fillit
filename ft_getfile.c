/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getfile.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: garouche <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/06 16:00:27 by garouche          #+#    #+#             */
/*   Updated: 2016/12/20 10:13:11 by garouche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

t_coord	*ft_set(t_coord *coord)
{
	coord = malloc(sizeof(t_coord));
	if (coord == NULL)
		return (NULL);
	coord->a = -1;
	coord->b = -1;
	return (coord);
}

t_coord	*ft_copy_coord(char (*tetri)[5], t_coord *coord)
{
	int		i;
	t_coord	a;

	a.a = -1;
	a.b = -1;
	i = -1;
	coord = ft_set(coord);
	while (a.a++ < 4 & i++ < 4)
	{
		while (a.b++ < 4)
		{
			if (tetri[a.b][i] == '#' && coord->b == -1)
				coord->b = i;
			if (tetri[a.a][a.b] == '#' && coord->a == -1)
				coord->a = a.a;
		}
		a.b = -1;
	}
	return (coord);
}

void	ft_put_tetri(char array[16][16], char buf[26][21], int nb)
{
	int		i;
	int		j;
	t_coord acoord;

	i = -1;
	j = -1;
	ft_memset(&acoord, 0, sizeof(acoord));
	acoord.sq = 2;
	while (!ft_checksquare(array, buf, acoord, nb))
	{
		acoord.sq++;
		ft_resetarray(array);
	}
	while (++i <= acoord.sq)
	{
		while (++j <= acoord.sq)
			ft_putchar(array[i][j]);
		j = -1;
		ft_putchar('\n');
	}
}

void	ft_resetarray(char array[16][16])
{
	int i;

	i = -1;
	while (++i < 16)
		ft_memset(array[i], '.', 15);
}

int		ft_get_tetri(char *argv)
{
	char	buf[26][21];
	int		fd;
	int		i;
	char	array[16][16];

	i = -1;
	fd = open(argv, O_RDONLY);
	if (fd == -1)
		return (0);
	read(fd, buf, 21 * 26);
	ft_resetarray(array);
	i = ft_check(buf);
	if (i > 1)
		ft_put_tetri(array, buf, i);
	else
		ft_putstr("error\n");
	return (1);
}
