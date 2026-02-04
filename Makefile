CC						=	clang-19 #this is for mlx to work on your computers, change before evaluation
CFLAGS					=	-Wall -Wextra -Werror -I libft -I includes -I minilibx-linux -g3
RM						=	rm -f
NAME					=	cub3D

LIBFT_FILE				=	libft/libft.a
LDFLAGS					=	-L libft -l ft
MAKE_LIB				=	make -C

MLX_FILE				=	minilibx-linux/mlx_linux
MLX_FLAGS				=	-Lminilibx-linux -l mlx_Linux -l Xext -l X11 -l m
MAKE_MLX				=	make -C

CUB3D_SRC				=	main.c cast_ray.c

CUB3D_OBJS				=	$(CUB3D_SRC:%.c=obj/%.o)

all:	$(NAME)

$(CUB3D_OBJS):	obj/%.o: %.c
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -c $< -o $@

$(LIBFT_FILE):
	$(MAKE_LIB) libft

$(MLX_FILE):
	$(MAKE_MLX) minilibx-linux

$(NAME):	$(CUB3D_OBJS) $(LIBFT_FILE) $(MLX_FILE)
	$(CC) $(CFLAGS) $(CUB3D_OBJS) $(LDFLAGS) $(MLX_FLAGS) -o $@

lib_clean:
	$(MAKE_LIB) libft clean

lib_fclean:
	$(MAKE_LIB) libft fclean

clean:	lib_clean
	rm -rf obj

fclean:	clean lib_fclean
	$(RM) $(NAME)

re:	fclean all

.PHONY:	all lib_clean lib_fclean clean fclean re