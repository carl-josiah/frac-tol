NAME	= fractol

SRC		= fractol.c \
		string_utils.c\


OBJS	= $(SRC:.c=.o)

CC		= cc

CFLAGS	= -Wall -Wextra -Werror

RM = rm -f

all: $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -Lmlx -lmlx -framework OpenGL -framework AppKit -o $(NAME)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re