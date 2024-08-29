SRC = $(wildcard src/*/*.c)

OBJ = $(SRC:.c=.o)

CC = cc

FLAGS = -Wall -Werror -Wextra #-g3 -fsanitize=address

INCLUDES = -Iincludes -Ilib/minilibx_opengl

LINKER = -L./lib/Libft -L./lib/minilibx_opengl -lft -lm -lmlx

NAME = cub3d

%.o : %.c
	@echo Compiling $<
	@$(CC) $(FLAGS) $(INCLUDES) -static -c -o $@ $< 

$(NAME) : $(OBJ)
	@make -C lib/minilibx_opengl
	@make -C lib/Libft
	@$(CC) $(FLAGS) $(OBJ) -o $(NAME) $(LINKER)

all : $(NAME)
	@echo $(NAME) Done !

clean :
	@rm -rf $(OBJ)
	@make clean -C ./lib/Libft

fclean : clean
	@rm -rf $(NAME)
	@make fclean -C ./lib/Libft

re : fclean all

.PHONY : all clean fclean re
