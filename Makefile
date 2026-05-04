# CC						=	clang-19 #this is for mlx to work on your computers, change before evaluation
CFLAGS					=	-Wall -Wextra -Werror -I libft -I includes -I minilibx-linux -g3
RM						=	rm -f
NAME					=	cub3D

LIBFT_FILE				=	libft/libft.a
LDFLAGS					=	-L libft -l ft
MAKE_LIB				=	make -C

MLX_FILE				=	minilibx-linux/mlx_linux
MLX_FLAGS				=	-Lminilibx-linux -l mlx_Linux -l Xext -l X11 -l m

CUB3D_SRC				=	src/dda.c \
							src/draw_figures.c \
							src/imcameraaxper.c \
							src/init_data.c \
							src/main.c \
							src/read_texture.c \
							src/timedif.c \
							src/movement.c \
							src/free_everything.c \
							src/vector_operations.c src/parsing.c src/utils.c \
							src/parse_id.c src/parse_map.c src/checkers.c \
							src/utils_utils.c src/parsing_checkers.c\
							src/init.c src/validating.c \
							src/draw_textures.c \
							src/validating_utils.c \
							src/parse_conf.c

CUB3D_OBJS				=	$(CUB3D_SRC:%.c=obj/%.o)

all:	$(NAME)

$(CUB3D_OBJS):	obj/%.o: %.c
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -c $< -o $@

$(LIBFT_FILE):
	$(MAKE_LIB) libft

# $(MLX_FILE):
# 	$(MAKE_MLX) minilibx-linux

$(NAME):	$(CUB3D_OBJS) $(LIBFT_FILE) #$(MLX_FILE)
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