# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: smessal <smessal@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/09/02 19:49:20 by smessal           #+#    #+#              #
#    Updated: 2022/09/04 18:11:13 by smessal          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC		=	utils/image_process.c utils/events.c

OBJ		= $(SRC:.c=.o)

CC		=		cc
RM		=		rm -rf
CFLAGS	=		-Wall -Werror -Wextra -g3 -I./includes

NAME	=		so_long

all: 			$(NAME)

%.o: %.c
	$(CC) -Wall -Wextra -Werror -I./includes -I/usr/include -Imlx_linux -O3 -c $< -o $@

$(NAME):		$(OBJ)
					$(CC) $(OBJ) -Lmlx_linux -lmlx_Linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz -o $(NAME)

clean:
					$(RM) $(OBJ)

fclean:		clean
					$(RM) $(NAME)

re:			fclean $(NAME)

.PHONY:		all clean fclean re