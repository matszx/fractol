NAME 			=	fractol
CC 				=	gcc
CFLAGS 			=	-Wall -Wextra -Werror -ffast-math -I/usr/include -Imlx
MLX				=	-Lmlx -lmlx -L/usr/lib/X11 -lX11 -lXext

SRC_FILES 		=	main.c \
					render.c \
					math_utils.c \
					handlers.c \
					utils.c			

SRC_DIR			=	src/
SRC				=	$(addprefix $(SRC_DIR), $(SRC_FILES))

OBJ_DIR			=	obj/
OBJ				=	$(addprefix $(OBJ_DIR), $(SRC_FILES:.c=.o))

$(OBJ_DIR)%.o	:	$(SRC_DIR)%.c
					$(CC) $(CFLAGS) -c $< -o $@

all				:	$(OBJ_DIR) $(NAME)

$(OBJ_DIR)		:
					mkdir -p $(OBJ_DIR)

$(NAME)			:	$(OBJ)
					@make -C mlx
					$(CC) $(CFLAGS) $(OBJ) -o $(NAME) $(MLX)

clean			:
					@make clean -C mlx
					rm -rf $(OBJ_DIR)

fclean			:	clean
					rm -f $(NAME)

re				:	fclean all

.PHONY			:	all clean fclean re
