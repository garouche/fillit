/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checkfile.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: garouche <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/17 19:39:12 by garouche          #+#    #+#             */
/*   Updated: 2017/04/25 17:44:39 by garouche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int	ft_check(char buf[26][21])
{
	char	(*t)[5];
	int		i;

	i = 0;
	while (buf[i][0] != 0)
	{
		t = (char(*)[5])buf[i];
		if (!ft_checkblok(t))
			return (0);
		if (t[4][0] != '\n' && buf[i + 1][0] != 0)
			return (0);
		if (t[4][0] != 0 && buf[i + 1][0] == 0)
			return (0);
		if (!ft_checkt(t))
			return (0);
		i++;
	}
	return (i);
}

int	ft_checkt(char (*t)[5])
{
	int j;
	int i;
	int number;

	j = -1;
	i = -1;
	number = 0;
	while (++i < 4)
	{
		while (++j < 4)
		{
			if (number < 3 && t[i][j] == '#' && t[i][j + 1] != '#' &&
			t[i + 1][j] != '#' && t[i - 1][j - 1] != '#' &&
			t[i + 1][j - 2] != '#' && t[i + 1][j - 1] != '#')
				return (0);
			if (t[i][j] == '#')
				number++;
		}
		j = -1;
	}
	if (number != 4)
		return (0);
	else
		return (1);
}

int	ft_checkline(char (*t)[5], int i)
{
	int j;

	j = 0;
	while (j < 5)
	{
		if (t[i][j] != '.' && t[i][j] != '#' && j < 4)
			return (0);
		if (j == 4 && t[i][j] != '\n')
			return (0);
		j++;
	}
	return (1);
}

int	ft_checkblok(char (*t)[5])
{
	int i;

	i = 0;
	while (i < 4)
	{
		if (!ft_checkline(t, i))
			return (0);
		i++;
	}
	return (1);
}
