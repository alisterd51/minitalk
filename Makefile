# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: anclarma <anclarma@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/05/12 13:07:16 by anclarma          #+#    #+#              #
#    Updated: 2021/06/20 17:17:23 by anclarma         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME1		= client
NAME2		= server
C_FILES1	= client.c		\
			  ft_atoi.c		\
			  ft_is.c
C_FILES2	= server.c		\
			  ft_itoa.c		\
			  ft_strlen.c
SRCS1		= $(addprefix srcs/,$(C_FILES1))
SRCS2		= $(addprefix srcs/,$(C_FILES2))
OBJS1		= $(SRCS1:.c=.o)
OBJS2		= $(SRCS2:.c=.o)
CC			= cc
CFLAGS		= -Wall -Wextra -Werror	\
			  -I ./includes

.c.o:
			$(CC) $(CFLAGS) $(CINCLUDES) -c $< -o $(<:.c=.o)

all:		$(NAME1) $(NAME2)

$(NAME1):	$(OBJS1)
			$(CC) $(CFLAGS) $(OBJS1) -o $(NAME1)

$(NAME2):	$(OBJS2)
			$(CC) $(CFLAGS) $(OBJS2) -o $(NAME2)

bonus:		$(NAME1) $(NAME2)

clean:
			rm -f $(OBJS1) $(OBJS2)

fclean:		clean
			rm -f $(NAME1) $(NAME2)

re:			fclean all

.PHONY:		all bonus clean fclean re
