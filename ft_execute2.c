/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_execute.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: garouche <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/12 14:29:23 by garouche          #+#    #+#             */
/*   Updated: 2017/04/27 15:06:16 by garouche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		ft_checkin(char array[16][16], char (*tetri)[5], t_coord *tc, t_coord a)
{
	int		i;
	t_coord t;

	t.a = -1;
	t.b = -1;
	i = a.b;
	while (++t.a < 4)
	{
		while (++t.b < 4)
		{
			if (tetri[t.a][t.b] == '#' && array[a.a][a.b] != '.')
				return (0);
			if ((a.a > a.sq || a.b > a.sq) && tetri[t.a][t.b] == '#')
				return (0);
			if (t.b >= tc->b && t.a >= tc->a)
				a.b++;
		}
		t.b = -1;
		a.b = i;
		if (t.a >= tc->a)
			a.a++;
	}
	return (1);
}

void	ft_remove(char array[16][16], char (*tetri)[5], t_coord *tc, t_coord a)
{
	int		i;
	t_coord	t;

	t.a = -1;
	t.b = -1;
	i = a.b;
	while (++t.a < 4)
	{
		while (++t.b < 4)
		{
			if (tetri[t.a][t.b] == '#')
				array[a.a][a.b] = '.';
			if (t.b >= tc->b && t.a >= tc->a)
				a.b++;
		}
		t.b = -1;
		a.b = i;
		if (t.a >= tc->a)
			a.a++;
	}
}

void	ft_copy(char array[16][16], char (*tetri)[5], t_coord *tc, t_coord a)
{
	int		i;
	t_coord	t;

	t.a = -1;
	t.b = -1;
	i = a.b;
	while (++t.a < 4)
	{
		while (++t.b < 4)
		{
			if (tetri[t.a][t.b] == '#')
				array[a.a][a.b] = 'A' + a.t;
			if (t.b >= tc->b && t.a >= tc->a)
				a.b++;
		}
		t.b = -1;
		a.b = i;
		if (t.a >= tc->a)
			a.a++;
	}
}

t_coord	*ft_reset(char (**t)[5], t_coord *a, char buf[26][21], t_coord *coord)
{
	*t = (char(*)[5])buf[a->t];
	ft_copy_coord(*t, coord);
	a->a = -1;
	a->b = -1;
	return (coord);
}

int		ft_checksquare(char array[16][16], char buf[26][21], t_coord a, int nb)
{
	t_coord	coord;
	char	(*tetri)[5];
	t_coord	s;

	ft_reset(&tetri, &a, buf, &coord);
	while (++a.a <= a.sq)
	{
		while (++a.b <= a.sq)
		{
			if (ft_checkin(array, tetri, &coord, a))
			{
				if (a.t == nb)
					return (1);
				s = a;
				ft_copy(array, tetri, &coord, a);
				a.t++;
				if (ft_checksquare(array, buf, a, nb))
					return (1);
				a = s;
				ft_remove(array, tetri, &coord, a);
			}
		}
		a.b = -1;
	}
	return (0);
}
