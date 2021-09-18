NAME		=	cub3D

SRCS	=	parser.c\
			cub3d.c\
			utilsparse.c\
			utilsray.c\
			makemap.c\
			exitfonc.c\
			parsecolors.c\
			validmap.c\
			keys.c\
			utilsvalid.c\
			raycasting.c\
			raycasting2.c\
			sprite.c\
			utilssprite.c\
			sqreen.c


OBJS		=	${SRCS:.c=.o}

CC			=	gcc

CFLAGS		=	-Wall -Wextra -Werror $(INCLUDES)

INCLUDES	=	-I $(MLX_DIR) -I $(LIBFT_DIR) -I includes/

LXFLAGS		=	-framework OpenGL -framework AppKit

MLX			=	libmlx.a

MLX_DIR		=	minilib_mms/

MLX_LIB		=	-lmlx -lm

LIBFT		=	libft.a

LIBFT_DIR	=	libft/

LIBFT_LIB	=	-lft

RM			=	rm -rf

all:		$(NAME)

$(NAME):	$(OBJS) $(MLX) $(LIBFT)
			$(CC) -g $(CFLAGS) -o $(NAME) $(OBJS) -L . $(MLX_LIB) $(LXFLAGS) -L $(LIBFT_DIR) $(LIBFT_LIB)

$(MLX):
			$(MAKE) -C $(MLX_DIR)
			mv $(MLX_DIR)$(MLX) .

$(LIBFT):
			$(MAKE) -C $(LIBFT_DIR)

clean:
			$(RM) $(OBJS)
			$(MAKE) -C $(LIBFT_DIR) fclean
			$(MAKE) -C $(MLX_DIR) clean
			$(RM) $(MLX)
			
fclean:		clean
			$(RM) $(NAME)

re:			fclean all

.PHONY:		all clean fclean re
