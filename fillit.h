/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: garouche <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/17 19:34:55 by garouche          #+#    #+#             */
/*   Updated: 2016/12/20 10:39:48 by garouche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include "libft/libft.h"
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>

typedef struct		s_coord
{
	int				a;
	int				b;
	int				t;
	int				sq;
}					t_coord;
int					ft_checkt(char (*t)[5]);
int					ft_checkblok(char (*t)[5]);
int					ft_check(char buf[26][21]);
void				*ft_memset(void *s, int c, size_t n);
int					ft_checksquare(char array[16][16], char buf[26][21], \
t_coord a, int nb);
void				ft_resetarray(char array[16][16]);
void				ft_copy(char array[16][16], char (*tetri)[5], t_coord *tc,\
t_coord a);
t_coord				*ft_copy_coord(char (*tetri)[5], t_coord *coord);
void				ft_remove(char array[16][16], char (*tetri)[5], t_coord *tc\
, t_coord a);
int					ft_sqrt(int nb);
int					ft_get_tetri(char *argv);
int					ft_checktetri(char *buf, int i);
int					ft_checkblock(char *buf);
int					ft_checkline(char (*tetri)[5], int i);
char				*ft_get_array(char *argv);
#endif
