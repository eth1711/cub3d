SRC = $(wildcard src/*/*.c)

SRC_BONUS = $(wildcard src_bonus/*/*.c)

OBJ_BONUS = $(SRC_BONUS:.c=.o)

OBJ = $(SRC:.c=.o)

CC = cc

FLAGS = -Wall -Werror -Wextra -g3 -fsanitize=address

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

NAME_BONUS = cub3d_bonus

all : $(NAME)
	@echo $(NAME) Done !

$(NAME) : $(OBJ)
	@make -C $(MLX)
	@make -C lib/Libft
	@make -C lib/gnl
	$(CC) $(FLAGS) $(OBJ) -o $(NAME) $(LINKER)

$(NAME_BONUS) : $(OBJ_BONUS)
	make -C $(MLX)
	make -C lib/Libft
	make -C lib/gnl
	$(CC) $(FLAGS) $(OBJ_BONUS) -o $(NAME_BONUS) $(LINKER)

%.o : %.c
	@echo Compiling $<
	$(CC) $(FLAGS) $(INCLUDES) -c -o $@ $< 

bonus : $(NAME_BONUS)
	echo $(NAME_BONUS) Done !

clean :
	@rm -rf $(OBJ)
	@rm -rf $(OBJ_BONUS)
	@make clean -C ./lib/Libft
	@make clean -C ./lib/gnl

fclean : clean
	@rm -rf $(NAME)
	@rm -rf $(NAME_BONUS)
	@make fclean -C ./lib/gnl
	@make clean -C ./lib/Libft

re : fclean all

.PHONY : all clean fclean re
