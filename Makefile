NAME = Cub3d

SRC = main.c ./graphic/engine/initializing.c ./graphic/engine/tools02.c ./graphic/engine/intersections.c ./graphic/engine/tools01.c ./graphic/engine/map.c ./graphic/engine/keys.c ./graphic/engine/player.c ./graphic/engine/raycasting.c ./graphic/engine/tools00.c ./graphic/cub3d.c ./parssing/srcs/main.c ./parssing/srcs/utils.c ./parssing/srcs/utils1.c ./parssing/srcs/utils2.c ./parssing/srcs/utils3.c ./parssing/srcs/utils5.c ./parssing/srcs/utils4.c ./parssing/srcs/utils6.c ./parssing/srcs/error.c ./parssing/srcs/error2.c  ./parssing/srcs/get_next_line.c 

CC = cc

CFLAGS = -Wall -Wextra -Werror

OBJS = ${SRC:.c=.o}

%.o: %.c
	${CC} ${CFLAGS} -c $< -o $@
LIBFT = ./libft/libft.a
LIB = ./mlx/libmlx42.a
GLFW = ./mlx/libglfw3.a

${NAME}: ${OBJS}
	${CC} ${CFLAGS} -framework Cocoa -framework OpenGL -framework IOKit ${GLFW} ${LIB} ${OBJS} ${LIBFT} -o ${NAME}

all: ${NAME}

clean:
	rm -fr ${OBJS}

fclean: clean
	rm -fr ${NAME}

re: fclean all
