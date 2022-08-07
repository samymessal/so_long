
SRCS	=	test.c atoi_base.c
CC		=	clang
OBJ		=	$(SRCS: .c=.o)
NAME	=	so_long
$(NAME): $(OBJ)
	$(CC) $(OBJ) -Lmlx_linux -lmlx_Linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz -o $(NAME)

