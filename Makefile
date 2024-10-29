SRC = $(wildcard src/*/*.c)

OBJ = $(SRC:.c=.o)

CC = cc

FLAGS = -Wall -Werror -Wextra -g3 #-fsanitize=address

ifeq ($(shell uname), Linux)
	MLX = lib/minilibx-linux
	LINKER_FLAGS = -lXext -lX11 -lz
else
	MLX = lib/minilibx_opengl
	LINKER_FLAGS = -framework OpenGL -framework AppKit
endif

INCLUDES = -I includes -I $(MLX) -I ./lib/Libft

LINKER = -L./lib/Libft -L $(MLX) -L./lib/gnl -lgnl -lft -lm -lmlx $(LINKER_FLAGS)

NAME = cub3d

%.o : %.c
	@echo Compiling $<
	$(CC) $(FLAGS) $(INCLUDES) -O3 -c -o $@ $< 

$(NAME) : $(OBJ)
	@make -C $(MLX)
	@make -C lib/Libft
	@make -C lib/gnl
	$(CC) $(FLAGS) $(OBJ) -o $(NAME) $(LINKER)

all : $(NAME)
	@echo $(NAME) Done !

clean :
	@rm -rf $(OBJ)
	@make clean -C ./lib/Libft
	@make clean -C ./lib/gnl

fclean : clean
	@rm -rf $(NAME)
	@make fclean -C ./lib/gnl
	@make clean -C ./lib/Libft

re : fclean all

.PHONY : all clean fclean re
