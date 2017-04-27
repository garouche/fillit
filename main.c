/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: garouche <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/02 14:20:21 by garouche          #+#    #+#             */
/*   Updated: 2017/03/08 15:31:04 by garouche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int	main(int argc, char **argv)
{
	if (argc == 2)
		ft_get_tetri(argv[1]);
	else
		ft_putstr("fillit file_name\n");
	return (0);
}
