NAME	= fractol

SRC		= fractol.c \
		utils1.c \
		utils2.c \
		utils3.c \
		parsing.c \
		init.c \
		render.c \
		handlers.c \

OBJS	= $(SRC:.c=.o)

CC		= cc

CFLAGS	= -Wall -Wextra -Werror

RM = rm -f

UNAME = $(shell uname -s)

ifeq ($(UNAME), Darwin)
	MLX_FLAGS = -Lminilibx_opengl_20191021 -lmlx -framework OpenGL -framework AppKit
	CFLAGS += -I./minilibx_opengl_20191021
	MLX_DIR = minilibx_opengl_20191021
else ifeq ($(UNAME), Linux)
	MLX_FLAGS = -Lminilibx-linux -lmlx_Linux -lX11 -lXext
	CFLAGS += -I./minilibx-linux
	MLX_DIR = minilibx-linux
endif

all: $(NAME)

mlx:
	$(MAKE) -C $(MLX_DIR)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME): mlx $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(MLX_FLAGS) -o $(NAME)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)
	$(MAKE) -C $(MLX_DIR) clean

re: fclean all

.PHONY: all clean fclean re mlx