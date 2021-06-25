NAME = so_long

MAIN = ./main.c

OBJ_MAIN = ${MAIN:.c=.o}

SRCS = srcs/utils.c srcs/parse.c srcs/get_next_line.c \
srcs/get_next_line_utils.c

PATH_SRCS = ./

_SRCS = ${addprefix ${PATH_SRCS}, ${SRCS}}

OBJS = ${_SRCS:.c=.o}

LINK = ar rc

CC = clang

FLAGS = -Wall -Werror -Wextra -g3 -fsanitize=address

RM = rm -rf

PATH_HEADER = ./

.c.o:
			${CC} ${FLAGS} -I${PATH_HEADER} -c $< -o ${<:.c=.o}

MYLIB = mylib.a

PATH_MLX_LINUX = ./minilibx-linux/

MLX_LINUX = ./minilibx-linux/libmlx_Linux.a

all:        ${NAME}

${NAME}:    ${MV} ${OBJ_MAIN} ${OBJS}
			${LINK} ${MYLIB} ${OBJS}
			ranlib ${MYLIB}
			make -C ${PATH_MLX_LINUX}
			${CC} ${FLAGS} -o3 ${OBJ_MAIN} ${MYLIB} ${MLX_LINUX} -lm -lbsd -lX11 -lXext -o ${NAME} libft/libft.a

clean:
			${RM} ${OBJ_MAIN} ${OBJS}
			make clean -C ${PATH_MLX_LINUX}

fclean:     clean
			${RM} ${NAME} ${MYLIB} ${MLX_LINUX}

re:         fclean all

.PHONY:     all clean fclean re