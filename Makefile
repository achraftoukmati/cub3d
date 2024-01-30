NAME = cub

SRC = main.c  $(wildcard ./graphic/engine/*.c) $(wildcard ./graphic/*.c)

CC = cc

CFLAGS =# -fsanitize=address -g

OBJS = ${SRC:.c=.o}

%.o: %.c
	${CC} ${CFLAGS} -c $< -o $@

LIB = ./mlx/libmlx42.a
GLFW = ./mlx/libglfw3.a

${NAME}: ${OBJS}
	${CC} ${CFLAGS} -framework Cocoa -framework OpenGL -framework IOKit ${GLFW} ${LIB} ${OBJS} -o ${NAME}

all: ${NAME}

clean:
	rm -fr ${OBJS}

fclean: clean
	rm -fr ${NAME}

re: fclean all
