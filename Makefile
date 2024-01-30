NAME = cub

SRC = main.c  $(wildcard ./graphic/engine/*.c) $(wildcard ./graphic/*.c)

CC = cc

CFLAGS =# -fsanitize=address -g

OBJS = ${SRC:.c=.o}

%.o: %.c
	${CC} ${CFLAGS} -c $< -o $@

LIB_DIR = ${HOME}/Desktop/cub/mlx/libmlx42.a
GLFW_DIR = ${HOME}/Desktop/cub/mlx/libglfw3.a

${NAME}: ${OBJS}
	${CC} ${CFLAGS} -framework Cocoa -framework OpenGL -framework IOKit ${GLFW_DIR} ${LIB_DIR} ${OBJS} -o ${NAME}

all: ${NAME}

clean:
	rm -fr ${OBJS}

fclean: clean
	rm -fr ${NAME}

re: fclean all
