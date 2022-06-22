NAME	=	so_long
SRC		=	so_long.c		map_init.c		so_long_utils.c		\
			display.c		move.c			enemy.c				\
			getnextline/get_next_line.c
OBJ		=	$(SRC:.c=.o)

INCLUDE	=	-Ilibft		-Igetnextline
LIBRARY	=	-Llibft -lft

LIBRARY_MLX = -Lmlx_linux -lmlx_Linux -L/usr/lib -Imlx_linux  -lXext -lX11  -lz 

CC		=	gcc
CFLAGS	=	-fsanitize=address  -Wall -Werror -Wextra  
			
RM		=	rm -rf

all		: $(NAME)

$(NAME)	: $(OBJ) lib
		@$(CC) $(CFLAGS) -o $@ $(OBJ)  $(LIBRARY) $(LIBRARY_MLX)
		

%.o	: %.c
		@$(CC)  $(CFLAGS) -c $< -o $@ -I/usr/include -Imlx_linux $(INCLUDE) 

lib		:
		@make -C libft

clean	:	
		@$(RM) $(NAME)	
#make clean -C libft

fclean	:	clean
		@$(RM) $(OBJ)
#make fclean -C libft

re		: fclean all

.phony	: all clean fclean re lib

