# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: garouche <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/11/24 16:32:09 by garouche          #+#    #+#              #
#    Updated: 2017/02/06 10:19:55 by garouche         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME	= fillit

SRC	=	ft_execute2.c ft_checkfile.c ft_getfile.c main.c

OBJ	=	$(SRC:.c=.o)

CFLAGS	= -Wall -Wextra -Werror

.PHONY	: all clean re fclean

LIBDIR	=	libft/
LIBC	= 	$(LIBDIR)libft.a
all		:	$(NAME) 

$(NAME)	:	$(OBJ) $(LIBC) 
			gcc -o $(NAME) $(CFLAGS) -I . $(SRC) -L$(LIBDIR) -lft

$(LIBC)	:	$(LIBDIR)	
			make -C $(LIBDIR)
clean	:
			rm -f $(OBJ)
			make -C $(LIBDIR) fclean 

re		: 	fclean	all

fclean	:	clean
			rm -f $(NAME)
