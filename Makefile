CC			=	cc
CFLAGS		=	-Wall -Wextra -Werror -Ilibft
NAME		=	cub3D
DEPS		=	cub3D.h
SRCS		=	main.c
OBJS		=	$(SRCS:.c=.o)

LIBMAKE		=	libmake

LIBFT_DIR	=	./libft
LIBFT		=	$(LIBFT_DIR)/libft.a

MLX_DIR		=	minilibx_linux/
MLX_INC		=	-I$(MLX_DIR)
MLX_LIB		=	-L$(MLX_DIR) -lmlx -lXext -lX11 -lm -lz

all: $(NAME) 

$(NAME) : $(OBJS) $(LIBMAKE)
	$(CC) $(CFLAGS) $(OBJS)  $(MLX_LIB) $(LIBFT) -o $(NAME)

$(LIBMAKE):
	make -C $(LIBFT_DIR)
	make -C $(MLX_DIR)

%.o : %.c $(DEPS)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	make clean -C $(LIBFT_DIR)
	make clean -C $(MLX_DIR)
	rm -f $(OBJS)

fclean: clean
	make fclean -C $(LIBFT_DIR)
	rm -f  $(NAME)

re: fclean all

.PHONY: all clean fclean re
