# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: smessal <smessal@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/09/02 19:49:20 by smessal           #+#    #+#              #
#    Updated: 2022/09/23 15:13:24 by smessal          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC		=	srcs/initialize.c srcs/main.c srcs/parsing.c utils/image_process.c \
			utils/events.c utils/parsing_errors.c utils/get_next_line.c \
			utils/moves.c utils/free.c utils/error_message.c utils/pathfinder.c

BONUS	=	srcs/initialize.c srcs/main.c srcs/parsing.c utils/image_process.c \
			utils/events.c utils/parsing_errors_bonus.c utils/get_next_line.c \
			utils/moves.c utils/free.c utils/error_message.c utils/pathfinder.c \
			utils/move_mechant_bonus.c

OBJ		= $(SRC:.c=.o)

OBJ_BONUS = $(BONUS:.c=.o)

CC		=		cc
RM		=		rm -rf
CFLAGS	=		-g3 -I./includes

NAME	=		so_long

all: 			$(NAME)

%.o: %.c
	$(CC) -I./includes -I/usr/include -Imlx_linux -O3 -c $< -o $@

$(NAME):		$(OBJ)
				make -C utils/libft
				ar -rcs utils/libft/libft.a
				cp utils/libft/libft.a libft.a
				$(CC) $(OBJ) -Lmlx_linux -lmlx_Linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz libft.a -o $(NAME)

bonus:			$(OBJ_BONUS)
				make -C utils/libft
				ar -rcs utils/libft/libft.a
				cp utils/libft/libft.a libft.a
				$(CC) $(OBJ_BONUS) -Lmlx_linux -lmlx_Linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz libft.a -o $(NAME)

clean:
					$(RM) $(OBJ) $(OBJ_BONUS)
					@make clean -sC utils/libft

fclean:		clean
					$(RM) $(NAME)
					$(RM) libft.a
					@make fclean -sC utils/libft

re:			fclean $(NAME)


.PHONY:		all clean fclean re